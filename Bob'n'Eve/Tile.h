#pragma once
#include <cinttypes>

	class Tile
	{
		friend class MapLoader;
		friend class Object;
		friend class TileSet;

	private:
		inline Tile() {}
		inline ~Tile()
		{
			delete[] collisionSides;
		}

		bool passBob = false;
		bool passEve = false;
		uint8_t animationId = -1;
		bool animationMirror = false;
		std::string animationType;
		uint16_t displayTime = 0;
		std::string type;
		std::string tileSetName;
		uint16_t id = -1;
		uint16_t gid = -1;
		bool* collisionSides = new bool[4] { true, true, true, true };
		bool switchesGravity = true;
	};
