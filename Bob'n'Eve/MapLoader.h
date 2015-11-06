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
};