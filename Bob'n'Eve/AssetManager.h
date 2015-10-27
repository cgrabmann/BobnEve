#pragma once

#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include <unordered_map>

class AssetManager
{
public:
	AssetManager(std::string rootDir);
	virtual ~AssetManager();

	sf::Sprite* GetSpriteByName(const std::string& name);
	sf::Sound* GetSoundByName(const std::string& name);
	sf::Music* GetMusicByName(const std::string& name);
	
	void LoadAll();
	void LoadTextures();
	void LoadSounds();
	void LoadMusic();

	bool LoadTextureByName(const std::string& name);
	bool LoadSoundByName(const std::string& name);
	bool LoadMusicByName(const std::string& name);

private:
	std::vector<std::string>* GetFilesInDir(const std::string& dir);

	std::unordered_map<std::string, sf::Texture*> textures_;
	std::unordered_map<std::string, sf::SoundBuffer*> sounds_;
	std::unordered_map<std::string, sf::Music*> music_;

	std::string rootDir_;
	std::string textureDir_;
	std::string soundDir_;
	std::string musicDir_;
};
