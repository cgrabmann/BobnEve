#pragma once
#include <cinttypes>
#include <stddef.h>
#include "GameObject.h"
#include <vector>

class CallbackCombiner;
class Tile;
class TileSet;
class Object;
class Map;
class Frame;

class MapLoader
{
public:
	static void LoadMap(const char* path);

private:
	inline MapLoader() {}
	inline MapLoader(const MapLoader&) {}
	inline ~MapLoader() {}

	static void ParseObject(Object* object, CallbackCombiner& combiner);
	static InputComponent* ParseInput(Object* object);
	static GraphicsComponent* ParseGraphics(Object* object, const Tile* tile = nullptr);
	static PhysicsComponentBase* ParsePhysics(Object* object, CallbackCombiner& combiner);
	static GraphicsComponent* ParseAnimation(Object* object, uint8_t animationId);
	static std::vector<Frame*> GetFramesByAnimationId(Object* object, uint8_t animationId);
};