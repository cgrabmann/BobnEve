#include "MapLoader.h"
#include "Player.h"
#include "InputComponentBase.h"
#include "PhysicsComponentBase.h"
#include <vector>
#include "Platform.h"
#include "Enemy.h"
#include "View.h"
#include "GraphicsComponentStatic.h"
#include <assert.h>
#include "AssetManager.h"
#include "Global.h"
#include <pugixml/src/pugixml.hpp>
#include "GraphicsComponentFade.h"
#include "Tile.h"
#include "TileSet.h"

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
	Global::TileWidth = map.attribute("tileheight").as_int();
	Global::MapWidth = map.attribute("width").as_int();
	Global::MapHeight = map.attribute("height").as_int();
	
	AssetManager* asset = AssetManager::Instance();

	TileSet* tileSetBob = nullptr;
	TileSet* tileSetEve = nullptr;

	std::vector<TileSet*> tilesets;
	for (pugi::xml_node xmlTileset = map.child("tileset"); xmlTileset; xmlTileset = xmlTileset.next_sibling("tileset"))
	{
		TileSet* tileset = new TileSet();
		tileset->firstgid = xmlTileset.attribute("firstgid").as_int();
		tileset->name = xmlTileset.attribute("name").as_string();
		tileset->tilecount = xmlTileset.attribute("tilecount").as_int();
		const pugi::char_t* imagePath = xmlTileset.child("image").attribute("source").as_string();
		tileset->imgPath = strrchr(imagePath, '/') + 1;
		tileset->tiles = new Tile[tileset->tilecount];
		tileset->tilewidth = xmlTileset.attribute("tilewidth").as_int();
		tileset->tileheight = xmlTileset.attribute("tileheight").as_int();
		if (strcmp(tileset->name, "Bob") == 0)
		{
			tileSetBob = tileset;
		}
		else if (strcmp(tileset->name, "Eve") == 0)
		{
			tileSetEve = tileset;
		}
		tilesets.push_back(tileset);

		//AssetManager::LoadTileSetByName(tileset->imgPath, tileset->tilewidth, tileset->tileheight);
		asset->RegisterTileSetByName(tileset->imgPath, tileset->tilewidth, tileset->tileheight);
	}

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
				new PhysicsComponentBase(Vector2f(xPos, yPos), false),
				new GraphicsComponentStatic(asset->GetTileByName(currentTileSet->imgPath, tileID - currentTileSet->firstgid))));

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

	std::vector<sf::Sprite*> textures;
	textures.push_back(asset->GetTileByName(tileSetBob->imgPath, 1));
	textures.push_back(asset->GetTileByName(tileSetBob->imgPath, 2));
	Player* bob = new Player(InputComponentBase::GetBobInputComponent(), new PhysicsComponentBase(Vector2f(1.f, 10.f), true), new GraphicsComponentFade(textures, 1000));
	Player* eve = new Player(InputComponentBase::GetEveInputComponent(), new PhysicsComponentBase(Vector2f(5.f, 10.f), true), new GraphicsComponentStatic(asset->GetTileByName(tileSetEve->imgPath, 1)));
	std::vector<Enemy*>* enemies = new std::vector<Enemy*>;


	//cleanup
	for (unsigned int i = 0; i < tilesets.size(); i++)
	{
		delete tilesets.at(i);
	}

	return new View(bob, eve, platforms, enemies);
}