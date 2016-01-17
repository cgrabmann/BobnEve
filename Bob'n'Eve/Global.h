#pragma once
#include <cinttypes>
#include <string>

class Global
{
public:
	//in pixels
	static uint16_t ScreenHeight;
	//in pixels
	static uint16_t ScreenWidth;

	//in pixels
	static uint8_t TileHeight;
	//in pixels
	static uint8_t TileWidth;

	//in tiles
	static uint8_t MapHeight;
	//in tiles
	static uint8_t MapWidth;

	//Folder Path
	static std::string AssetDir;
	static std::string LEADERBOARD;
};