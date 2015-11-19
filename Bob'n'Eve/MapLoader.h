#pragma once
#include <cinttypes>
#include <stddef.h>
#include "GameObject.h"
#include <vector>

class Tile;
class TileSet;
class Object;
class View;
class Frame;

class MapLoader
{
public:

	static View* LoadMap(const char* path);

private:
	inline MapLoader() {}
	inline MapLoader(const MapLoader&) {}
		inline ~MapLoader() {}

	static InputComponent* ParseInput(Object* object);
	static GraphicsComponent* ParseGraphics(Object* object);
	static PhysicsComponentBase* ParsePhysics(Object* object);

	static std::vector<Frame*> GetAnimationById(Object* object, uint8_t id);
};