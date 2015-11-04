#pragma once
#include "AssetManager.h"
#include "Global.h"
#include <assert.h>
#include <SFML/include/SFML/Graphics/Texture.hpp>
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

AssetManager::AssetManager() : textures_(), sounds_(), music_(),
textureDir_(Global::AssetDir + "textures/"), soundDir_(Global::AssetDir + "sounds/"), musicDir_(Global::AssetDir + "music/")
{
}

AssetManager::~AssetManager()
{

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
		LoadTextureByName(files->at(i));
	}

	delete files;
}

void AssetManager::LoadSounds()
{
	std::vector<std::string>* files = GetFilesInDir(soundDir_);

	for (size_t i = 0; i < files->size(); i++)
	{
		LoadSoundByName(files->at(i));
	}

	delete files;
}

void AssetManager::LoadMusic()
{
	std::vector<std::string>* files = GetFilesInDir(musicDir_);

	for (size_t i = 0; i < files->size(); i++)
	{
		LoadMusicByName(files->at(i));
	}

	delete files;
}

void AssetManager::LoadTextureByName(const std::string& name)
{
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile(textureDir_ + name))
	{
		if (!texture->loadFromFile(textureDir_ + errorTex))
		{
			assert(false);
			exit(-1);
		}
		texture->setRepeated(true);
	}

	texture->setSmooth(true);
	textures_[name] = texture;
}

void AssetManager::LoadSoundByName(const std::string& name)
{
	std::string path = soundDir_ + name;

	sf::SoundBuffer* sound = new sf::SoundBuffer();
	if (!sound->loadFromFile(path))
	{
		assert(false);
		//TODO: Errorhandling
	}

	sounds_[name] = sound;
}

void AssetManager::LoadMusicByName(const std::string& name)
{
	std::string path = musicDir_ + name;

	sf::Music* music = new sf::Music();
	if (!music->openFromFile(path))
	{
		assert(false);
		//TODO: Errorhandling
	}

	music_[name] = music;
}

std::vector<std::string>* AssetManager::GetFilesInDir(const std::string& dir)
{
	std::vector<std::string>* files = new std::vector<std::string>();

	return files;
}

sf::Sprite* AssetManager::GetSpriteByName(const std::string& name)
{
	sf::Sprite* sprite = new sf::Sprite();

	if (textures_.count(name) == 0)
	{
		LoadTextureByName(name);
	}
	sprite->setTexture(*textures_[name]);
	sprite->setOrigin(Global::TileWidth / 2.f, Global::TileHeight / 2.f);

	return sprite;
}

sf::Sprite* AssetManager::GetSpriteByName(const std::string& name, const uint8_t gid)
{
	sf::Sprite* sprite = GetSpriteByName(name);

	sf::Vector2u size = sprite->getTexture()->getSize();
	uint8_t maxTilesX = size.x / Global::TileWidth;
	
	uint8_t tilePosX = gid % maxTilesX;
	uint8_t tilePosY = gid / maxTilesX;


	sprite->setTextureRect(sf::IntRect(Global::TileWidth * tilePosX, Global::TileHeight * tilePosY, Global::TileWidth, Global::TileHeight));

	return sprite;
}

sf::Sound* AssetManager::GetSoundByName(const std::string& name)
{
	sf::Sound* sound = new sf::Sound();

	if (sounds_.count(name) != 0)
	{
		LoadSoundByName(name);
	}
	sound->setBuffer(*sounds_[name]);

	return sound;
}

sf::Music* AssetManager::GetMusicByName(const std::string& name)
{
	sf::Music* music = new sf::Music();

	if (music_.count(name) != 0)
	{
		LoadMusicByName(name);
	}
	music = music_[name];

	return music;
}





