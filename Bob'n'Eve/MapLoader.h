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
		uint8_t animationFrameId = 0;
		uint8_t displayTime = 0;
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