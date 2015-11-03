#include "MapLoader.h"
#include "Player.h"
#include "InputComponentBase.h"
#include "PhysicsComponent.h"
#include <vector>
#include "Platform.h"
#include "Enemy.h"
#include "View.h"
#include <pugixml/src/pugixml.hpp>
#include "GraphicsComponentStatic.h"

//MapLoader* MapLoader::instance_ = NULL;

MapLoader::MapLoader()
{
}

MapLoader::~MapLoader()
{
}

//MapLoader* MapLoader::Instance()
//{
//	static CGuard g;   // Speicherbereinigung
//	if (!instance_)
//		instance_ = new MapLoader();
//	return instance_;
//}

View* MapLoader::LoadMap(const char* path)
{
	assert(path != NULL);

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(path);

	assert(!result);

	AssetManager* asset = AssetManager::Instance();

	Player* bob = new Player(InputComponentBase::GetBobInputComponent(), new PhysicsComponentBase(), new GraphicsComponentStatic(asset->GetSpriteByName("Test.png", 0)));
	Player* eve = new Player(InputComponentBase::GetEveInputComponent(), new PhysicsComponentBase(), new GraphicsComponentStatic(asset->GetSpriteByName("Test.png", 3)));
	std::vector<Platform*>* platforms = new std::vector<Platform*>;
	std::vector<Enemy*>* enemies = new std::vector<Enemy*>;

	return new View(bob, eve, platforms, enemies);
}