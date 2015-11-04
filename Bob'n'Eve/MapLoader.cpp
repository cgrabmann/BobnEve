#include "MapLoader.h"
#include "Player.h"
#include "InputComponentBase.h"
#include "PhysicsComponentBase.h"
#include <vector>
#include "Platform.h"
#include "Enemy.h"
#include "View.h"
#include <pugixml/src/pugixml.hpp>
#include "GraphicsComponentStatic.h"
#include "GraphicsComponentAnimated.h"
#include <assert.h>
#include "AssetManager.h"
#include "Global.h"

//MapLoader* MapLoader::instance_ = NULL;

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

	for (pugi::xml_node tileset = map.child("tileset"); tileset; tileset = tileset.next_sibling("tileset"))
	{
		
	}

	AssetManager* asset = AssetManager::Instance();

	//Player* bob = new Player(InputComponentBase::GetBobInputComponent(), new PhysicsComponentBase(), new GraphicsComponentStatic(asset->GetSpriteByName("Test.png", 0)));
	std::vector<sf::Sprite*> textures;
	textures.push_back(asset->GetSpriteByName("Test.png", 0));
	textures.push_back(asset->GetSpriteByName("Test.png", 1));
	Player* bob = new Player(InputComponentBase::GetBobInputComponent(), new PhysicsComponentBase(), new GraphicsComponentAnimated(textures, 1000));
	Player* eve = new Player(InputComponentBase::GetEveInputComponent(), new PhysicsComponentBase(), new GraphicsComponentStatic(asset->GetSpriteByName("Test.png", 3)));
	std::vector<Platform*>* platforms = new std::vector<Platform*>;
	std::vector<Enemy*>* enemies = new std::vector<Enemy*>;

	return new View(bob, eve, platforms, enemies);
}