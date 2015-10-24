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

	sf::Sprite GetSpriteByName(std::string name);
	sf::Sound GetSoundByName(std::string name);
	sf::Music GetMusicByName(std::string name);
	
	void LoadAll();
	void LoadTextures();
	void LoadSounds();
	void LoadMusic();

	void LoadTextureByName(std::string name);
	void LoadSoundByName(std::string name);
	void LoadMusicByName(std::string name);

private:
	std::vector<std::string> GetFilesInDir(std::string dir);

	std::unordered_map<std::string, sf::Texture> textures_;
	std::unordered_map<std::string, sf::SoundBuffer> sounds_;
	std::unordered_map<std::string, sf::Music> music_;

	std::string rootDir_;
	std::string textureDir_;
	std::string soundDir_;
	std::string musicDir_;
};
