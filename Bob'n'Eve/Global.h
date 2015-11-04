#pragma once
#include <cinttypes>
#include <string>

class Global
{
public:
	//in pixels
	static uint32_t TileHeight;
	//in pixels
	static uint32_t TileWidth;

	//in tiles
	static uint32_t MapHeight;
	//in tiles
	static uint32_t MapWidth;

	//
	static std::string AssetDir;
};