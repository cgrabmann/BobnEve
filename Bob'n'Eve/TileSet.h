#pragma once
#include <cinttypes>
#include <pugixml.hpp>

class Tile;

class TileSet
{
	friend class MapLoader;
private:
	TileSet();
	~TileSet();

	uint8_t firstgid = 1;
	const char* name = nullptr;
	const char* imgPath = nullptr;
	uint8_t tilecount = 0;
	uint8_t tilewidth = 0;
	uint8_t tileheight = 0;
	uint8_t spacing = 0;
	uint8_t margin = 0;

	Tile* tiles = nullptr;
};

