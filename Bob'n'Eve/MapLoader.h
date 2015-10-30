#pragma once
#include <stddef.h>
#include "AssetManager.h"

class View;

class MapLoader
{
public:
	//static MapLoader* Instance();

	static View* LoadMap(const char* path);

private:
	//static MapLoader* instance_;
	MapLoader();
	MapLoader(const MapLoader&);
	~MapLoader();
	/*class CGuard
	{
	public:
		~CGuard()
		{
			if (NULL != MapLoader::instance_)
			{
				delete MapLoader::instance_;
				MapLoader::instance_ = NULL;
			}
		}
	};*/
};