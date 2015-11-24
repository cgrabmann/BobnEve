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

	static void LoadMap(const char* path);

private:
	inline MapLoader() {}
	inline MapLoader(const MapLoader&) {}
	inline ~MapLoader() {}

	static InputComponent* ParseInput(Object* object);
	static GraphicsComponent* ParseGraphics(Object* object, const Tile* tile = nullptr);
	static PhysicsComponentBase* ParsePhysics(Object* object);
	static GraphicsComponent* ParseAnimation(Object* object, uint8_t animationId);
	static std::vector<Frame*> GetFramesByAnimationId(Object* object, uint8_t animationId);
};