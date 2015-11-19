#pragma once
#include <cinttypes>

	class Tile
	{
		friend class MapLoader;
		friend class Object;
		friend class TileSet;

	private:
		inline Tile() {}
		inline ~Tile() {}

		bool bobPass = false;
		bool evePass = false;
		uint8_t animationId = 0;
		bool animationMirror = false;
		const char* animationType;
		uint8_t displayTime = 0;
		const char* type;
		const char* tileSetName;
		uint16_t id = 0;
		uint16_t gid = 0;
	};
