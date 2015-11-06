#include "TileSet.h"
#include "Tile.h"


TileSet::TileSet()
{
}


TileSet::~TileSet()
{
	delete[] tiles;
}
