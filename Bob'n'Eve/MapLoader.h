#pragma once
#include <cinttypes>
#include <stddef.h>

class View;

class MapLoader
{
public:

	static View* LoadMap(const char* path);

private:
	MapLoader();
	MapLoader(const MapLoader&);
	~MapLoader();

	struct Tile
	{
		bool bobPass = false;
		bool evePass = false;
		union {
			uint8_t standFrameId = 0;
			uint8_t runFrameId;
			uint8_t jumpFrameId;
			uint8_t animationFrameId;
		};
		uint8_t displayTime;
	};

	struct TileSet
	{
		~TileSet()
		{
			delete[] name;
			delete[] imgPath;
		}

		uint8_t firstgid = 1;
		char* name = NULL;
		char* imgPath = NULL;
		uint8_t tilecount = 0;

		Tile* tiles = NULL;
	};
};