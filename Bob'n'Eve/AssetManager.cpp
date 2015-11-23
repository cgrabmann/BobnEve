#pragma once
#include "AssetManager.h"
#include "Global.h"
#include <assert.h>
#include <SFML/include/SFML/Graphics/Sprite.hpp>
#include <SFML/include/SFML/Audio/Music.hpp>
#include <SFML/include/SFML/Audio/SoundBuffer.hpp>
#include <SFML/include/SFML/Audio/Sound.hpp>

AssetManager* AssetManager::instance_ = NULL;

AssetManager* AssetManager::Instance()
{
	static CGuard g;   // Speicherbereinigung
	if (!instance_)
		instance_ = new AssetManager();
	return instance_;
}

AssetManager::AssetManager() : tileSets_(), sounds_(), music_(),
textureDir_(Global::AssetDir + "textures/"), soundDir_(Global::AssetDir + "sounds/"),
musicDir_(Global::AssetDir + "music/"), errorTex_(nullptr)
{
}

AssetManager::~AssetManager()
{
	tileSets_.clear();
	sounds_.clear();
	music_.clear();
}

void AssetManager::LoadAll()
{
	LoadTextures();
	LoadSounds();
	LoadMusic();
}

void AssetManager::LoadTextures()
{
	std::vector<std::string>* files = GetFilesInDir(textureDir_);

	for (size_t i = 0; i < files->size(); i++)
	{
		RegisterTextureByName(files->at(i));
	}

	delete files;
}

void AssetManager::LoadSounds()
{
	std::vector<std::string>* files = GetFilesInDir(soundDir_);

	for (size_t i = 0; i < files->size(); i++)
	{
		RegisterSoundByName(files->at(i));
	}

	delete files;
}

void AssetManager::LoadMusic()
{
	std::vector<std::string>* files = GetFilesInDir(musicDir_);

	for (size_t i = 0; i < files->size(); i++)
	{
		RegisterMusicByName(files->at(i));
	}

	delete files;
}

void AssetManager::RegisterTextureByName(const std::string& name)
{
	RegisterTileSetByName(name, 0, 0);
}

void AssetManager::RegisterTileSetByName(const std::string& name, const uint32_t tileWidth, const uint32_t tileHeight, const uint8_t spacing, const uint8_t margin)
{
	if (tileSets_.count(name) != 0)
		return;

	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile(textureDir_ + name))
	{
		std::string CouldNotLoadTexture = "";
		__debugbreak();
		//assert(CouldNotLoadTexture == name);
		texture = GetErrorTex();
	}

	tileSets_[name] = new TileSet(texture, tileWidth, tileHeight, spacing, margin);;
}

void AssetManager::RegisterSoundByName(const std::string& name)
{
	if (sounds_.count(name) != 0)
		return;

	std::string path = soundDir_ + name;

	sf::SoundBuffer* sound = new sf::SoundBuffer();
	if (!sound->loadFromFile(path))
	{
		std::string CouldNotLoadSound = "";
		__debugbreak();
		//assert(CouldNotLoadSound == name);
		//TODO: Errorhandling
	}

	sounds_[name] = sound;
}

void AssetManager::RegisterMusicByName(const std::string& name)
{
	if (music_.count(name) != 0)
		return;

	std::string path = musicDir_ + name;

	sf::Music* music = new sf::Music();
	if (!music->openFromFile(path))
	{
		std::string CouldNotLoadMusic = "";
		__debugbreak();
		//assert(CouldNotLoadMusic == name);
		//TODO: Errorhandling
	}

	music_[name] = music;
}

std::vector<std::string>* AssetManager::GetFilesInDir(const std::string& dir)
{
	std::vector<std::string>* files = new std::vector<std::string>();

	return files;
}

sf::Texture* AssetManager::GetErrorTex()
{
	if (!errorTex_)
	{
		const std::string errorTex = "Error.png";

		errorTex_ = new sf::Texture();
		if (!errorTex_->loadFromFile(textureDir_ + errorTex))
		{
			std::string CouldNotLoadTexture = errorTex;
			__debugbreak();
			//assert(CouldNotLoadTexture == "");
			exit(-1);
		}
		errorTex_->setRepeated(true);
	}
	return errorTex_;
}

sf::Sprite* AssetManager::GetSpriteByName(const std::string& name)
{
	return GetTileByName(name, 0);
}

sf::Sprite* AssetManager::GetTileByName(const std::string& name, const uint8_t gid)
{
	if (tileSets_.count(name) == 0)
	{
		std::string CouldNotLoadTexture = name;
		__debugbreak();
		//assert(CouldNotLoadTexture == "");
		tileSets_[name] = new TileSet(GetErrorTex(), 0, 0, 0, 0);
	}
	TileSet* tileSet = tileSets_[name];

	sf::Sprite* sprite = new sf::Sprite(*(tileSet->texture));
	sprite->setTextureRect(tileSet->GetTileRect(gid));
	sprite->setOrigin(tileSet->tileCenter);

	return sprite;
}

sf::Sound* AssetManager::GetSoundByName(const std::string& name)
{
	sf::Sound* sound = new sf::Sound();

	if (sounds_.count(name) != 0)
	{
		RegisterSoundByName(name);
	}
	sound->setBuffer(*sounds_[name]);

	return sound;
}

sf::Music* AssetManager::GetMusicByName(const std::string& name)
{
	sf::Music* music = new sf::Music();

	if (music_.count(name) != 0)
	{
		RegisterMusicByName(name);
	}
	music = music_[name];

	return music;
}


