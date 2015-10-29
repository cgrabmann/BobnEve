#pragma once
#include <cinttypes>

class Global
{
public:
	//in pixels
	static uint8_t TileHeight;
	//in pixels
	static uint8_t TileWidth;

	//in tiles
	static uint8_t MapHeight;
	//in tiles
	static uint8_t MapWidth;

	//
	static std::string AssetDir;
};

uint8_t Global::TileHeight = 64;
uint8_t Global::TileWidth = 64;

std::string Global::AssetDir = "./Assets/";