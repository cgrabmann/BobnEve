#include "MapLoader.h"
#include "Player.h"
#include "InputComponentBase.h"
#include "PhysicsComponentBase.h"
#include <vector>
#include "Platform.h"
#include "Enemy.h"
#include "View.h"
#include "GraphicsComponentStatic.h"
#include "GraphicsComponentAnimated.h"
#include <assert.h>
#include "AssetManager.h"
#include "Global.h"
#include <pugixml/src/pugixml.hpp>

MapLoader::MapLoader()
{
}

MapLoader::~MapLoader()
{
}

View* MapLoader::LoadMap(const char* path)
{
	assert(path != NULL);

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file((Global::AssetDir + "maps/" + path).c_str());

	assert(result);

	pugi::xml_node map = doc.child("map");

	Global::TileWidth = map.attribute("tilewidth").as_int();
	Global::TileHeight = map.attribute("tileheight").as_int();
	Global::MapWidth = map.attribute("width").as_int();
	Global::MapHeight = map.attribute("height").as_int();

	std::vector<TileSet*> tilesets;
	for (pugi::xml_node xmlTileset = map.child("tileset"); xmlTileset; xmlTileset = xmlTileset.next_sibling("tileset"))
	{
		TileSet* tileset = new TileSet();
		tileset->firstgid = xmlTileset.attribute("firstgid").as_int();
		const pugi::char_t* name = xmlTileset.attribute("name").as_string();
		size_t nameLength = strlen(name) + 1;
		tileset->name = new char[nameLength];
		memcpy(tileset->name, name, nameLength);
		tileset->tilecount = xmlTileset.attribute("tilecount").as_int();
		const pugi::char_t* imagePath = xmlTileset.child("image").attribute("source").as_string();
		size_t pathLength = strlen(imagePath) + 1;
		tileset->imgPath = new char[pathLength];
		memcpy(tileset->imgPath, imagePath, pathLength);
		tileset->tiles = new Tile[tileset->tilecount];
		tilesets.push_back(tileset);
	}

	AssetManager* asset = AssetManager::Instance();

	std::vector<Platform*>* platforms = new std::vector<Platform*>;
	pugi::xml_node tilemap = map.child("layer").child("data");
	uint8_t xPos = 0;
	uint8_t yPos = 0;
	for (pugi::xml_node tile = tilemap.child("tile"); tile; tile = tile.next_sibling("tile"))
	{
		uint8_t tileID = tile.attribute("gid").as_int();
		TileSet* currentTileSet = nullptr;
		for (int i = tilesets.size() - 1; i > 0; i--)
		{
			if (tilesets.at(i)->firstgid <= tileID)
			{
				currentTileSet = tilesets.at(i);
				break;
			}
		}
		if (currentTileSet != nullptr)
			platforms->push_back(new Platform(new InputComponentBase(),
				new PhysicsComponentBase(xPos * Global::TileWidth + (Global::TileWidth / 2), yPos * Global::TileHeight + (Global::TileHeight / 2)),
				new GraphicsComponentStatic(asset->GetSpriteByName(currentTileSet->imgPath, tileID - currentTileSet->firstgid))));

		if (xPos == Global::MapWidth - 1)
		{
			xPos = 0;
			yPos++;
		}
		else
		{
			xPos++;
		}
	}

	//Player* bob = new Player(InputComponentBase::GetBobInputComponent(), new PhysicsComponentBase(), new GraphicsComponentStatic(asset->GetSpriteByName("Test.png", 0)));
	std::vector<sf::Sprite*> textures;
	textures.push_back(asset->GetSpriteByName("Bob.png", 1));
	textures.push_back(asset->GetSpriteByName("Bob.png", 2));
	Player* bob = new Player(InputComponentBase::GetBobInputComponent(), new PhysicsComponentBase(100.f, 750.f), new GraphicsComponentAnimated(textures, 1000));
	Player* eve = new Player(InputComponentBase::GetEveInputComponent(), new PhysicsComponentBase(100.f, 750.f), new GraphicsComponentStatic(asset->GetSpriteByName("Eve.png", 1)));
	std::vector<Enemy*>* enemies = new std::vector<Enemy*>;


	//cleanup
	for (unsigned int i = 0; i < tilesets.size(); i++)
	{
		delete tilesets.at(i);
	}

	return new View(bob, eve, platforms, enemies);
}