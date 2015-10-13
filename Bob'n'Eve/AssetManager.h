#pragma once

#include <string>

class AssetManager
{
private:
	std::string rootDir_;
public:
	AssetManager();
	virtual ~AssetManager();
};
