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
#include <windows.h>
#include "Coin.h"
#include "PhysicBodyDef.h"

void MapLoader::LoadMap(const char* path)
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

		asset->RegisterTileSet(tileSet->imgPath, tileSet->tilewidth, tileSet->tileheight, tileSet->spacing, tileSet->margin);

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

	View::Instance()->CleanUp();
	uint8_t xPos = 0;
	uint8_t yPos = 0;
	uint8_t tileCount = tiles.size();
	//Platform Layer
	for (pugi::xml_node xmlTile = map.child("layer").child("data").child("tile"); xmlTile; xmlTile = xmlTile.next_sibling("tile"))
	{
		uint8_t gid = xmlTile.attribute("gid").as_int();
		if (gid != 0 && gid <= tileCount)
		{
			Object* object = new Object();

			object->id = -1;
			object->tile = tiles[gid];
			object->tileSet = tileSets[object->tile->tileSetName];
			object->pos = Vector2f(xPos * Global::TileWidth + Global::TileWidth / 2, yPos * Global::TileHeight + Global::TileHeight / 2);
			object->size = Vector2f(Global::TileWidth, Global::TileHeight);
			object->type = object->tile->type;
			object->gravity = 0;
			object->enemyId = -1;

			ParseObject(object);

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

		object->id = xmlObject.attribute("id").as_int();
		object->tile = tiles[gid];
		object->tileSet = tileSets[object->tile->tileSetName];
		object->size = Vector2f(xmlObject.attribute("width").as_int(), xmlObject.attribute("height").as_int());
		object->pos = Vector2f(xmlObject.attribute("x").as_float() + object->size.x / 2, xmlObject.attribute("y").as_float() - object->size.y / 2);
		object->type = xmlObject.attribute("tpye").empty() ? object->tile->type : xmlObject.attribute("tpye").as_string();

		for (pugi::xml_node xmlObjectProperty = xmlObject.child("properties").child("property"); xmlObjectProperty; xmlObjectProperty = xmlObjectProperty.next_sibling("property"))
		{
			const char* propertyName = xmlObjectProperty.attribute("name").as_string();

			if (!strcmp(propertyName, "Gravity"))
			{
				object->gravity = xmlObjectProperty.attribute("value").as_int();
			}
			else if (!strcmp(propertyName, "EnemyId"))
			{
				object->id = xmlObjectProperty.attribute("value").as_int();
			}
		}

		ParseObject(object);

		delete object;
	}

	//clean up
	tileSets.clear();
	tiles.clear();
}

void MapLoader::ParseObject(Object* object)
{
	if (!strcmp(object->type, "Enemy"))
	{
		View::Instance()->Register(new Enemy(ParseInput(object), ParsePhysics(object), ParseGraphics(object), object->enemyId));
	}
	else if (!strcmp(object->type, "Coin"))
	{
		View::Instance()->Register(new Coin(ParseInput(object), ParsePhysics(object), ParseGraphics(object)));
	}
	else if (!strcmp(object->type, "Bob") || !strcmp(object->type, "Eve"))
	{
		View::Instance()->Register(new Player(ParseInput(object), ParsePhysics(object), ParseAnimation(object, 0), ParseAnimation(object, 1), ParseAnimation(object, 2)));
	}
	else // if (!strcmp(object->type, "Platform") || !strcmp(object->type, "PassTrough"))
	{
		View::Instance()->Register(new Platform(ParseInput(object), ParsePhysics(object), ParseGraphics(object)));
	}
}

InputComponent* MapLoader::ParseInput(Object* object)
{
	if (!strcmp(object->type, "Enemy"))
	{
		return new InputComponent();
	}
	if (!strcmp(object->type, "Coin"))
	{
		return new InputComponent();
	}
	if (!strcmp(object->type, "Bob"))
	{
		return InputComponent::GetBobInputComponent();
	}
	if (!strcmp(object->type, "Eve"))
	{
		return InputComponent::GetEveInputComponent();
	}
	// if (!strcmp(object->type, "Platform") || !strcmp(object->type, "PassTrough"))
	{
		return new InputComponent();
	}
}

GraphicsComponent* MapLoader::ParseGraphics(Object* object, const Tile* tile)
{
	if (tile == nullptr)
	{
		tile = object->tile;
	}

	if (strcmp(tile->animationType, "Static"))
	{
		if (!strcmp(tile->animationType, "Fade"))
		{
			return new GraphicsComponentFade(GetFramesByAnimationId(object, tile->animationId), tile->animationMirror);
		}
		return new GraphicsComponentAnimated(GetFramesByAnimationId(object, tile->animationId), tile->animationMirror);
	}

	return new GraphicsComponent(AssetManager::Instance()->GetTile(object->tileSet->imgPath, tile->id));
}

GraphicsComponent* MapLoader::ParseAnimation(Object* object, uint8_t animationId)
{
	for (int i = 0; i < object->tileSet->tilecount; i++)
	{
		if (object->tileSet->tiles[i].animationId == animationId)
		{
			return ParseGraphics(object, &object->tileSet->tiles[i]);
		}
	}
	return new GraphicsComponent();
}

PhysicsComponentBase* MapLoader::ParsePhysics(Object* object)
{
	//TODO remove / 64 when PhysicsEngine is ready
	PhysicBodyDef bodyDef;
	bodyDef.bounds = FloatRect(object->pos, Vector2f(32, 32));
	bodyDef.gravityScale_ = object->gravity;

	if (!strcmp(object->type, "Enemy"))
	{
		bodyDef.type_ = PhysicBody::STATIC;
		bodyDef.collisionIgnorGroups_.push_back(1);
		return new PhysicsComponentStatic(bodyDef);
	}
	if (!strcmp(object->type, "Bob"))
	{
		bodyDef.bounds.halfSize.y = 48;
		bodyDef.type_ = PhysicBody::DYNAMIC;
		bodyDef.collisionIgnorGroups_.push_back(2);
		return new PhysicsComponentDynamic(bodyDef);
	}
	if (!strcmp(object->type, "Eve"))
	{
		bodyDef.bounds.halfSize.y = 48;
		bodyDef.type_ = PhysicBody::DYNAMIC;
		bodyDef.collisionIgnorGroups_.push_back(3);
		return new PhysicsComponentDynamic(bodyDef);
	}
	//if (!strcmp(object->type, "Platform") || !strcmp(object->type, "PassTrough"))
	{
		bodyDef.type_ = PhysicBody::STATIC;
		if (object->tile->bobPass)
		{
			bodyDef.collisionIgnorGroups_.push_back(2);
		}
		if (object->tile->evePass)
		{
			bodyDef.collisionIgnorGroups_.push_back(3);
		}
		return new PhysicsComponentStatic(bodyDef);
	}
}

std::vector<Frame*> MapLoader::GetFramesByAnimationId(Object* object, uint8_t animationId)
{
	std::vector<Frame*> tempFrames;
	tempFrames.reserve(4);
	for (int i = 0; i < object->tileSet->tilecount; i++)
	{
		if (object->tileSet->tiles[i].animationId == animationId)
		{
			tempFrames.push_back(new Frame(AssetManager::Instance()->GetTile(object->tileSet->imgPath, object->tileSet->tiles[i].id), object->tile->displayTime));
		}
	}

	return tempFrames;
}
