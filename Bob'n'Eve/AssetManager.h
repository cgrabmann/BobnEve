#pragma once

#include <string>
#include <unordered_map>
#include <cinttypes>

namespace sf{
	class Sprite;
	class Sound;
	class Music;
	class Texture;
	class SoundBuffer;
}

class AssetManager
{
public:
	static AssetManager* Instance();

	sf::Sprite* GetSpriteByName(const std::string& name);
	sf::Sprite* GetSpriteByName(const std::string& name, const uint8_t gid);
	sf::Sound* GetSoundByName(const std::string& name);
	sf::Music* GetMusicByName(const std::string& name);

protected:
	void LoadAll();
	void LoadTextures();
	void LoadSounds();
	void LoadMusic();

private:
	static AssetManager* instance_;

	AssetManager();
	~AssetManager();


	void LoadTextureByName(const std::string& name);
	void LoadSoundByName(const std::string& name);
	void LoadMusicByName(const std::string& name);

	std::vector<std::string>* GetFilesInDir(const std::string& dir);

	std::unordered_map<std::string, sf::Texture*> textures_;
	std::unordered_map<std::string, sf::SoundBuffer*> sounds_;
	std::unordered_map<std::string, sf::Music*> music_;

	std::string textureDir_;
	std::string soundDir_;
	std::string musicDir_;

	const std::string errorTex = "Error.png";

	class CGuard
	{
	public:
		~CGuard()
		{
			if (NULL != AssetManager::instance_)
			{
				delete AssetManager::instance_;
				AssetManager::instance_ = NULL;
			}
		}
	};
};
