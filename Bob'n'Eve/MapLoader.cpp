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
#include "PhysicManager.h"
#include "PhysicsComponentEnemy.h"
#include "PhysicsComponentPlayer.h"

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

			for (pugi::xml_node xmlProperty = xmlTile.child("properties").child("property"); xmlProperty; xmlProperty = xmlProperty.next_sibling("property"))
			{
				const char* propertyName = xmlProperty.attribute("name").as_string();

				if (!strcmp(propertyName, "Animation_Id"))
				{
					tile->animationId = xmlProperty.attribute("value").as_int();
				}
				else if (!strcmp(propertyName, "Animation_Mirror"))
				{
					tile->animationMirror = xmlProperty.attribute("value").as_bool();
				}
				else if (!strcmp(propertyName, "Animation_Type"))
				{
					tile->animationType = xmlProperty.attribute("value").as_string();
				}
				else if (!strcmp(propertyName, "Pass_Bob"))
				{
					tile->passBob = xmlProperty.attribute("value").as_bool();;
				}
				else if (!strcmp(propertyName, "Pass_Eve"))
				{
					tile->passEve = xmlProperty.attribute("value").as_bool();;
				}
				else if (!strcmp(propertyName, "Type"))
				{
					tile->type = xmlProperty.attribute("value").as_string();;
				}
				else if (!strcmp(propertyName, "DisplayTime"))
				{
					tile->displayTime = xmlProperty.attribute("value").as_int();;
				}
				else if (!strcmp(propertyName, "Collision_Top"))
				{
					tile->collisionSides[Sides::Top] = xmlProperty.attribute("value").as_bool();;
				}
				else if (!strcmp(propertyName, "Collision_Right"))
				{
					tile->collisionSides[Sides::Right] = xmlProperty.attribute("value").as_bool();;
				}
				else if (!strcmp(propertyName, "Collision_Bottom"))
				{
					tile->collisionSides[Sides::Bottom] = xmlProperty.attribute("value").as_bool();;
				}
				else if (!strcmp(propertyName, "Collision_Left"))
				{
					tile->collisionSides[Sides::Left] = xmlProperty.attribute("value").as_bool();;
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

	for (pugi::xml_node xmlStaticObject = map.child("layer").child("data").child("tile"); xmlStaticObject; xmlStaticObject = xmlStaticObject.next_sibling("tile"))
	{
		uint8_t gid = xmlStaticObject.attribute("gid").as_int();
		if (gid != 0 && gid < tileCount)
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

	for (pugi::xml_node xmlDynamicLayer = map.child("objectgroup"); xmlDynamicLayer; xmlDynamicLayer = xmlDynamicLayer.next_sibling("objectgroup"))
	{
		for (pugi::xml_node xmlProperty = xmlDynamicLayer.child("properties").child("property"); xmlProperty; xmlProperty = xmlProperty.next_sibling("property"))
		{
			const char* propertyName = xmlProperty.attribute("name").as_string();

			if (!strcmp(propertyName, "Gravity"))
			{
				PhysicManager::Instance()->SetGravity(Vector2f(0, xmlProperty.attribute("value").as_float()));
			}
		}

		for (pugi::xml_node xmlDynamicObject = xmlDynamicLayer.child("object"); xmlDynamicObject; xmlDynamicObject = xmlDynamicObject.next_sibling("object"))
		{
			uint8_t gid = xmlDynamicObject.attribute("gid").as_int();
			if (gid == 0 || gid > tileCount)
				continue;

			Object* object = new Object();

			object->id = xmlDynamicObject.attribute("id").as_int();
			object->tile = tiles[gid];
			object->tileSet = tileSets[object->tile->tileSetName];
			object->size = Vector2f(xmlDynamicObject.attribute("width").as_int(), xmlDynamicObject.attribute("height").as_int());
			object->pos = Vector2f(xmlDynamicObject.attribute("x").as_float() + object->size.x / 2, xmlDynamicObject.attribute("y").as_float() - object->size.y / 2);
			object->type = xmlDynamicObject.attribute("tpye").empty() ? object->tile->type : xmlDynamicObject.attribute("tpye").as_string();

			for (pugi::xml_node xmlObjectProperty = xmlDynamicObject.child("properties").child("property"); xmlObjectProperty; xmlObjectProperty = xmlObjectProperty.next_sibling("property"))
			{
				const char* propertyName = xmlObjectProperty.attribute("name").as_string();

				if (!strcmp(propertyName, "GravityScale"))
				{
					object->gravity = xmlObjectProperty.attribute("value").as_int();
				}
				else if (!strcmp(propertyName, "EnemyId"))
				{
					object->id = xmlObjectProperty.attribute("value").as_int();
				}
				else if (!strcmp(propertyName, "SpeedX"))
				{
					object->speed.x = xmlObjectProperty.attribute("value").as_float();
				}
				else if (!strcmp(propertyName, "SpeedY"))
				{
					object->speed.y = xmlObjectProperty.attribute("value").as_float();
				}
			}

			ParseObject(object);

			delete object;
		}
	}

	//clean up
	tileSets.clear();
	tiles.clear();
}

void MapLoader::ParseObject(Object* object)
{
	if (!strcmp(object->type, "Enemy"))
	{
		View::Instance()->Register(new Enemy(ParseInput(object), ParsePhysics(object), ParseGraphics(object), object->enemyId, object->speed));
	}
	else if (!strcmp(object->type, "Coin"))
	{
		View::Instance()->Register(new Coin(ParseInput(object), ParsePhysics(object), ParseGraphics(object)));
	}
	else if (!strcmp(object->type, "Bob") || !strcmp(object->type, "Eve"))
	{
		View::Instance()->Register(new Player(ParseInput(object), ParsePhysics(object), ParseAnimation(object, 0), ParseAnimation(object, 1), ParseAnimation(object, 2), object->speed));
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
	PhysicBodyDef bodyDef;
	bodyDef.bounds_ = FloatRect(object->pos, object->size / 2);
	bodyDef.customId_ = object->type;
	memcpy(bodyDef.collisionSides_, object->tile->collisionSides, 4);

	if (!strcmp(object->type, "Enemy"))
	{
		bodyDef.gravityScale_ = object->gravity;
		bodyDef.type_ = PhysicBody::DYNAMIC;
		bodyDef.collisionIgnoreGroups_.push_back(1);
		return new PhysicsComponentEnemy(bodyDef);
	}
	if (!strcmp(object->type, "Bob"))
	{
		bodyDef.gravityScale_ = object->gravity;
		bodyDef.type_ = PhysicBody::DYNAMIC;
		bodyDef.collisionIgnoreGroups_.push_back(2);
		return new PhysicsComponentPlayer(bodyDef);
	}
	if (!strcmp(object->type, "Eve"))
	{
		bodyDef.gravityScale_ = object->gravity;
		bodyDef.type_ = PhysicBody::DYNAMIC;
		bodyDef.collisionIgnoreGroups_.push_back(3);
		return new PhysicsComponentPlayer(bodyDef);
	}
	//if (!strcmp(object->type, "Platform") || !strcmp(object->type, "PassTrough"))
	{
		bodyDef.type_ = PhysicBody::STATIC;
		if (object->tile->passBob)
		{
			bodyDef.collisionIgnoreGroups_.push_back(2);
		}
		if (object->tile->passEve)
		{
			bodyDef.collisionIgnoreGroups_.push_back(3);
		}
		/*if (!strcmp(object->type, "PassThrough"))
		{
			return new PhysicsComponentStatic(bodyDef);
		}*/
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
