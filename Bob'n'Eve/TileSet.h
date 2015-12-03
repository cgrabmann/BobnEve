#pragma once
#include <cinttypes>
#include <pugixml.hpp>

class Tile;
class Object;

class TileSet
{
	friend class MapLoader;
	friend class Object;
	friend class Tile;

private:
	inline TileSet() {}
	inline ~TileSet()
	{
		delete[] tiles;
	}

	uint8_t firstgid = 1;
	std::string name;
	std::string imgPath;
	uint8_t tilecount = 0;
	uint8_t tilewidth = 0;
	uint8_t tileheight = 0;
	uint8_t spacing = 0;
	uint8_t margin = 0;

	Tile* tiles = nullptr;
};

