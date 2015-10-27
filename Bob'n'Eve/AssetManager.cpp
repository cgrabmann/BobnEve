#include "AssetManager.h"

AssetManager::AssetManager(std::string rootDir) : textures_(), sounds_(), music_(), rootDir_(rootDir),
textureDir_(rootDir + "textures/"), soundDir_(rootDir + "sounds/"), musicDir_(rootDir + "music/")
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
	std::vector<std::string>& files = *GetFilesInDir(textureDir_);

	for (size_t i = 0; i < files.size(); i++)
	{
		LoadTextureByName(files[i]);
	}
}

void AssetManager::LoadSounds()
{
	std::vector<std::string>& files = *GetFilesInDir(soundDir_);

	for (size_t i = 0; i < files.size(); i++)
	{
		LoadSoundByName(files[i]);
	}
}

void AssetManager::LoadMusic()
{
	std::vector<std::string>& files = *GetFilesInDir(musicDir_);

	for (size_t i = 0; i < files.size(); i++)
	{
		LoadMusicByName(files[i]);
	}
}

bool AssetManager::LoadTextureByName(const std::string& name)
{
	std::string path = textureDir_ + name;

	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile(path))
	{
		return false;
	}

	texture->setSmooth(true);
	textures_[name] = texture;
	return true;
}

bool AssetManager::LoadSoundByName(const std::string& name)
{
	std::string path = soundDir_ + name;

	sf::SoundBuffer* sound = new sf::SoundBuffer();
	if (!sound->loadFromFile(path))
	{
		return false;
	}

	sounds_[name] = sound;
	return true;
}

bool AssetManager::LoadMusicByName(const std::string& name)
{
	std::string path = musicDir_ + name;

	sf::Music* music = new sf::Music();
	if (!music->openFromFile(path))
	{
		return false;
	}

	music_[name] = music;
	return true;
}

std::vector<std::string>* AssetManager::GetFilesInDir(const std::string& dir)
{
	std::vector<std::string>* files = new std::vector<std::string>();

	return files;
}

sf::Sprite* AssetManager::GetSpriteByName(const std::string& name)
{
	sf::Sprite* sprite = new sf::Sprite();

	if (textures_.count(name) != 0)
	{
		sprite->setTexture(*textures_[name]);
	}

	return sprite;
}

sf::Sound* AssetManager::GetSoundByName(const std::string& name)
{
	sf::Sound* sound = new sf::Sound();

	if (sounds_.count(name) != 0)
	{
		sound->setBuffer(*sounds_[name]);
	}

	return sound;
}

sf::Music* AssetManager::GetMusicByName(const std::string& name)
{
	sf::Music* music = new sf::Music();

	if (music_.count(name) != 0)
	{
		music = music_[name];
	}

	return music;
}





