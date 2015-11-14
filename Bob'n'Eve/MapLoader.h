#pragma once
#include <cinttypes>
#include <stddef.h>
#include "GameObject.h"

class Tile;
class TileSet;
class Object;
class View;

class MapLoader
{
public:

	static View* LoadMap(const char* path);

private:
	MapLoader();
	MapLoader(const MapLoader&);
	~MapLoader();

	static InputComponent* ParseInput(Object* object);
	static GraphicsComponent* ParseGraphics(Object* object);
	static PhysicsComponentBase* ParsePhysics(Object* object);
};