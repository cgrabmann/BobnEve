#pragma once

#include <string>

class AssetManager
{
public:
	AssetManager();
	virtual ~AssetManager();

private:
	std::string rootDir_;
};
