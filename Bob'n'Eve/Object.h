#pragma once
#include <cstdint>
#include "Vector2f.h"
#include "Tile.h"

class Object
	{
		friend class MapLoader;

	private:
		inline Object()
		{}
		inline ~Object()
		{}

		const Tile* tile;
		const TileSet* tileSet;

		int8_t gravity = 0;
		uint8_t enemyId = -1; 
		Vector2f pos, size;
	};
