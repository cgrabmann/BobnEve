#include "MapLoader.h"
#include "Player.h"
#include "InputComponent.h"
#include "PhysicsComponentBase.h"
#include <vector>
#include "Platform.h"
#include "Enemy.h"
#include "View.h"
#include <assert.h>
#include "AssetManager.h"
#include "Global.h"
#include <pugixml/src/pugixml.hpp>
#include "GraphicsComponent.h"
#include "GraphicsComponentAnimated.h"
#include "GraphicsComponentFade.h"
#include "Tile.h"
#include "TileSet.h"
#include "PhysicsComponentStatic.h"
#include "PhysicsComponentDynamic.h"
#include "Frame.h"
#include "Object.h"

View* MapLoader::LoadMap(const char* path)
{
	assert(path != NULL);

	AssetManager* asset = AssetManager::Instance();

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file((Global::AssetDir + "maps/" + path).c_str());

	assert(result);

	pugi::xml_node map = doc.child("map");

	Global::TileWidth = map.attribute("tilewidth").as_int();
	Global::TileWidth = map.attribute("tileheight").as_int();
	Global::MapWidth = map.attribute("width").as_int();
	Global::MapHeight = map.attribute("height").as_int();

	std::vector<Platform*>* platforms = new std::vector<Platform*>;
	platforms->reserve(256);
	Player* bob = nullptr;
	Player* eve = nullptr;
	std::vector<Enemy*>* enemies = new std::vector<Enemy*>;
	platforms->reserve(32);

	std::unordered_map<std::string, TileSet*> tileSets;
	tileSets.reserve(4);
	std::unordered_map<uint16_t, Tile*> tiles;
	tiles.reserve(32);


	for (pugi::xml_node xmlTileset = map.child("tileset"); xmlTileset; xmlTileset = xmlTileset.next_sibling("tileset"))
	{
		TileSet* tileSet = new TileSet();

		tileSet->firstgid = xmlTileset.attribute("firstgid").as_int();
		tileSet->name = xmlTileset.attribute("name").as_string();
		tileSet->tilecount = xmlTileset.attribute("tilecount").as_int();
		tileSet->spacing = xmlTileset.attribute("spacing").as_int();
		tileSet->margin = xmlTileset.attribute("margin").as_int();
		const pugi::char_t* imagePath = xmlTileset.child("image").attribute("source").as_string();
		tileSet->imgPath = strrchr(imagePath, '/') + 1;
		tileSet->tiles = new Tile[tileSet->tilecount];
		tileSet->tilewidth = xmlTileset.attribute("tilewidth").as_int();
		tileSet->tileheight = xmlTileset.attribute("tileheight").as_int();

		tileSets[tileSet->name] = tileSet;

		asset->RegisterTileSetByName(tileSet->imgPath, tileSet->tilewidth, tileSet->tileheight, tileSet->spacing, tileSet->margin);

		for (pugi::xml_node xmlTile = xmlTileset.child("tile"); xmlTile; xmlTile = xmlTile.next_sibling("tile"))
		{
			Tile* tile = new Tile();
			tile->tileSetName = tileSet->name;
			int id = xmlTile.attribute("id").as_int();
			tile->id = id;
			tile->gid = tileSet->firstgid + id;

			for (pugi::xml_node xmlTileProperty = xmlTile.child("properties").child("property"); xmlTileProperty; xmlTileProperty = xmlTileProperty.next_sibling("property"))
			{
				const char* propertyName = xmlTileProperty.attribute("name").as_string();

				if (!strcmp(propertyName, "AnimationId"))
				{
					tile->animationId = xmlTileProperty.attribute("value").as_int();
				}
				else if (!strcmp(propertyName, "AnimationMirror"))
				{
					tile->animationMirror = xmlTileProperty.attribute("value").as_bool();
				}
				else if (!strcmp(propertyName, "AnimationType"))
				{
					tile->animationType = xmlTileProperty.attribute("value").as_string();
				}
				else if (!strcmp(propertyName, "BobPass"))
				{
					tile->bobPass = xmlTileProperty.attribute("value").as_bool();;
				}
				else if (!strcmp(propertyName, "EvePass"))
				{
					tile->evePass = xmlTileProperty.attribute("value").as_bool();;
				}
				else if (!strcmp(propertyName, "Type"))
				{
					tile->type = xmlTileProperty.attribute("value").as_string();;
				}
				else if (!strcmp(propertyName, "DisplayTime"))
				{
					tile->displayTime = xmlTileProperty.attribute("value").as_int();;
				}
			}

			tiles[tile->gid] = tile;
			tileSet->tiles[id] = *tile;
		}
	}

	uint8_t xPos = 0;
	uint8_t yPos = 0;
	uint8_t tileCount = tiles.size();
	for (pugi::xml_node tile = map.child("layer").child("data").child("tile"); tile; tile = tile.next_sibling("tile"))
	{
		uint8_t gid = tile.attribute("gid").as_int();
		if (gid != 0 && gid <= tileCount)
		{
			Object* object = new Object();

			object->tile = tiles[gid];
			object->tileSet = tileSets[object->tile->tileSetName];
			object->pos = Vector2f(xPos * Global::TileWidth, yPos * Global::TileHeight);
			object->size = Vector2f(Global::TileWidth, Global::TileHeight);
			object->gravity = 0;
			object->enemyId = -1;

			if (!strcmp(object->tile->type, "PassTrough"))
			{
				platforms->push_back(new Platform(ParseInput(object), ParsePhysics(object), ParseGraphics(object)));
			}
			else  if (!strcmp(object->tile->type, "Enemy"))
			{
				enemies->push_back(new Enemy(ParseInput(object), ParsePhysics(object), ParseGraphics(object)));
			}
			else if (!strcmp(object->tile->type, "Bob"))
			{
				bob = new Player(ParseInput(object), ParsePhysics(object), ParseGraphics(object));
			}
			else if (!strcmp(object->tile->type, "Eve"))
			{
				eve = new Player(ParseInput(object), ParsePhysics(object), ParseGraphics(object));
			}
			else // if (!strcmp(object->tile->type, "Platform"))
			{
				platforms->push_back(new Platform(ParseInput(object), ParsePhysics(object), ParseGraphics(object)));
			}

			delete object;
		}

		xPos++;
		if (xPos >= Global::MapWidth)
		{
			xPos = 0;
			yPos++;
		}
	}

	for (pugi::xml_node xmlObject = map.child("objectgroup").child("object"); xmlObject; xmlObject = xmlObject.next_sibling("object"))
	{
		uint8_t gid = xmlObject.attribute("gid").as_int();
		if (gid == 0 || gid > tileCount)
			continue;

		Object* object = new Object();

		object->tile = tiles[gid];
		object->tileSet = tileSets[object->tile->tileSetName];
		object->pos = Vector2f(xmlObject.attribute("x").as_float(), xmlObject.attribute("y").as_float());
		object->size = Vector2f(xmlObject.attribute("width").as_int(), xmlObject.attribute("height").as_int());

		for (pugi::xml_node xmlObjectProperty = xmlObject.child("properties").child("property"); xmlObjectProperty; xmlObjectProperty = xmlObjectProperty.next_sibling("property"))
		{
			const char* propertyName = xmlObjectProperty.attribute("name").as_string();

			if (!strcmp(propertyName, "Gravity"))
			{
				object->gravity = xmlObjectProperty.attribute("value").as_int();
			}
			else if (!strcmp(propertyName, "EnemyId"))
			{
				object->enemyId = xmlObjectProperty.attribute("value").as_int();
			}
		}

		if (!strcmp(object->tile->type, "PassTrough"))
		{
			platforms->push_back(new Platform(ParseInput(object), ParsePhysics(object), ParseGraphics(object)));
		}
		else  if (!strcmp(object->tile->type, "Enemy"))
		{
			enemies->push_back(new Enemy(ParseInput(object), ParsePhysics(object), ParseGraphics(object)));
		}
		else if (!strcmp(object->tile->type, "Bob"))
		{
			bob = new Player(ParseInput(object), ParsePhysics(object), ParseGraphics(object));
		}
		else if (!strcmp(object->tile->type, "Eve"))
		{
			eve = new Player(ParseInput(object), ParsePhysics(object), ParseGraphics(object));
		}
		else // if (!strcmp(object->tile->type, "Platform"))
		{
			platforms->push_back(new Platform(ParseInput(object), ParsePhysics(object), ParseGraphics(object)));
		}

		delete object;
	}

	//clean up
	tileSets.clear();
	tiles.clear();

	return new View(bob, eve, platforms, enemies);
}

InputComponent* MapLoader::ParseInput(Object* object)
{
	if (!strcmp(object->tile->type, "PassTrough"))
	{
		return new InputComponent();
	}
	if (!strcmp(object->tile->type, "Enemy"))
	{
		return new InputComponent();
	}
	if (!strcmp(object->tile->type, "Bob"))
	{
		return InputComponent::GetBobInputComponent();
	}
	if (!strcmp(object->tile->type, "Eve"))
	{
		return InputComponent::GetEveInputComponent();
	}
	// if (!strcmp(object->tile->type, "Platform"))
	{
		return new InputComponent();
	}
}

GraphicsComponent* MapLoader::ParseGraphics(Object* object)
{
	GraphicsComponent* tempGraphics = nullptr;

	if (strcmp(object->tile->animationType, "Static"))
	{
		if (!strcmp(object->tile->animationType, "Fade"))
		{
			return new GraphicsComponentFade(GetAnimationById(object, object->tile->animationId), object->tile->animationMirror);
		}
		return new GraphicsComponentAnimated(GetAnimationById(object, object->tile->animationId), object->tile->animationMirror);
	}

	return new GraphicsComponent(AssetManager::Instance()->GetTileByName(object->tileSet->imgPath, object->tile->id));
}

PhysicsComponentBase* MapLoader::ParsePhysics(Object* object)
{
	//TODO remove / 64 when PhysicsEngine is ready

	if (!strcmp(object->tile->type, "PassTrough"))
	{
		return new PhysicsComponentStatic(object->pos / 64);
	}
	if (!strcmp(object->tile->type, "Enemy"))
	{
		return new PhysicsComponentStatic(object->pos / 64);
	}
	if (!strcmp(object->tile->type, "Bob"))
	{
		return new PhysicsComponentDynamic(object->pos / 64);
	}
	if (!strcmp(object->tile->type, "Eve"))
	{
		return new PhysicsComponentDynamic(object->pos / 64);
	}
	//if (!strcmp(object->tile->type, "Platform"))
	{
		return new PhysicsComponentStatic(object->pos / 64);
	}
}

std::vector<Frame*> MapLoader::GetAnimationById(Object* object, uint8_t id)
{
	std::vector<Frame*> tempFrames;
	tempFrames.reserve(4);
	for (int i = 0; i < object->tileSet->tilecount; i++)
	{
		if (object->tileSet->tiles[i].animationId == id)
		{
			tempFrames.push_back(new Frame(AssetManager::Instance()->GetTileByName(object->tileSet->imgPath, object->tileSet->tiles[i].id), object->tile->displayTime));
		}
	}

	return tempFrames;
}
