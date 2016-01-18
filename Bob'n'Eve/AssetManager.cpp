#pragma once
#include "AssetManager.h"
#include "Global.h"
#include <assert.h>
#include <SFML/include/SFML/Graphics/Sprite.hpp>
#include <SFML/include/SFML/Audio/Music.hpp>
#include <SFML/include/SFML/Audio/SoundBuffer.hpp>
#include <SFML/include/SFML/Audio/Sound.hpp>
#include <SFML/include/SFML/Graphics/Font.hpp>

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
musicDir_(Global::AssetDir + "music/"), fontDir_(Global::AssetDir + "fonts/"), errorTex_(nullptr)
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
		RegisterTexture(files->at(i));
	}

	delete files;
}

void AssetManager::LoadSounds()
{
	std::vector<std::string>* files = GetFilesInDir(soundDir_);

	for (size_t i = 0; i < files->size(); i++)
	{
		RegisterSound(files->at(i));
	}

	delete files;
}

void AssetManager::LoadMusic()
{
	std::vector<std::string>* files = GetFilesInDir(musicDir_);

	for (size_t i = 0; i < files->size(); i++)
	{
		RegisterMusic(files->at(i));
	}

	delete files;
}

void AssetManager::RegisterTexture(const std::string& name)
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

	tileSets_[name] = new TileSet(texture);;
}

void AssetManager::RegisterTileSet(const std::string& name, const uint32_t tileWidth, const uint32_t tileHeight, const uint8_t spacing, const uint8_t margin)
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

void AssetManager::RegisterSound(const std::string& name)
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

void AssetManager::RegisterMusic(const std::string& name)
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

void AssetManager::RegisterFont(const std::string& name)
{
	if (fonts_.count(name) != 0)
		return;

	std::string path = fontDir_ + name;

	sf::Font* font = new sf::Font();
	if (!font->loadFromFile(path))
	{
		std::string CouldNotLoadFont = "";
		__debugbreak();
		//assert(CouldNotLoadFont == name);
		//TODO: Errorhandling
	}

	fonts_[name] = font;
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

sf::Sprite* AssetManager::GetSprite(const std::string& name)
{
	return GetTile(name, 0);
}

sf::Sprite* AssetManager::GetTile(const std::string& name, const uint8_t gid)
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

sf::Sound* AssetManager::GetSound(const std::string& name)
{
	sf::Sound* sound = new sf::Sound();

	if (sounds_.count(name) != 0)
	{
		RegisterSound(name);
	}
	sound->setBuffer(*sounds_[name]);

	return sound;
}

sf::Music* AssetManager::GetMusic(const std::string& name)
{
	sf::Music* music = new sf::Music();

	if (music_.count(name) != 0)
	{
		RegisterMusic(name);
	}
	music = music_[name];

	return music;
}

sf::Font* AssetManager::GetFont(const std::string& name)
{
	sf::Font* font = new sf::Font();

	if (fonts_.count(name) != 0)
	{
		RegisterFont(name);
	}
	font = fonts_[name];

	return font;
}

