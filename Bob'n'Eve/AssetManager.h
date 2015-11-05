#pragma once

#include <string>
#include <unordered_map>
#include <cinttypes>
#include <SFML/include/SFML/Graphics/Rect.hpp>
#include <SFML/include/SFML/Graphics/Texture.hpp>

namespace sf{
	class Sprite;
	class Sound;
	class Music;
	class Texture;
	class SoundBuffer;
}


class AssetManager
{
	class TileSet;

public:
	static AssetManager* Instance();

	sf::Sprite* GetSpriteByName(const std::string& name);
	sf::Sprite* GetTileByName(const std::string& name, const uint8_t gid);
	sf::Sound* GetSoundByName(const std::string& name);
	sf::Music* GetMusicByName(const std::string& name);

	void RegisterTextureByName(const std::string& name);
	void RegisterTileSetByName(const std::string& name, const uint32_t tileWidth, const uint32_t tileHeight);
	void RegisterSoundByName(const std::string& name);
	void RegisterMusicByName(const std::string& name);

protected:
	void LoadAll();
	void LoadTextures();
	void LoadSounds();
	void LoadMusic();

private:
	static AssetManager* instance_;

	AssetManager();
	~AssetManager();

	std::vector<std::string>* GetFilesInDir(const std::string& dir);
	
	std::unordered_map<std::string, TileSet*> tileSets_;
	std::unordered_map<std::string, sf::SoundBuffer*> sounds_;
	std::unordered_map<std::string, sf::Music*> music_;

	std::string textureDir_;
	std::string soundDir_;
	std::string musicDir_;

	sf::Texture* errorTex_;
	sf::Texture* GetErrorTex();

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

	class TileSet
	{
		friend class AssetManager;
	public:
		TileSet(const sf::Texture* texture) : TileSet(texture, texture->getSize().x, texture->getSize().y)
		{}

		TileSet(const sf::Texture* texture, const  uint32_t tileWidth, const  uint32_t tileHeight) :
			size(texture->getSize()),
			tileSize(tileWidth, tileHeight),
			tileCount(size.x / tileSize.x, size.y / tileSize.y),
			tileCenter(size.x / 2, size.y / 2),
			texture(texture)
		{}

		sf::IntRect GetTileRect(const uint8_t gid) const
		{
			return sf::IntRect(tileSize.x * (gid % tileCount.x), tileSize.y * (gid / tileCount.x), tileSize.x, tileSize.y);
		}

		const sf::Vector2u size, tileSize, tileCount;
		const sf::Vector2f tileCenter;

	private:
		const sf::Texture* texture;
	};
};
