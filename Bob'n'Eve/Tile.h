#pragma once
#include <cinttypes>


class Tile
{
	friend class MapLoader;
	friend class TileSet;
private:
	Tile();
	~Tile();

	bool bobPass = false;
	bool evePass = false;
	uint8_t animationFrameId = 0;
	uint8_t displayTime = 0;
};

