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
	void RegisterTileSetByName(const std::string& name, const uint32_t tileWidth, const uint32_t tileHeight, const uint8_t spacing = 0, const uint8_t margin = 0);
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
		TileSet(const sf::Texture* texture) : TileSet(texture, texture->getSize().x, texture->getSize().y, 0, 0)
		{}

		TileSet(const sf::Texture* texture, const uint32_t tileWidth, const uint32_t tileHeight, const uint8_t spacing, const uint8_t margin) :
			size(texture->getSize()),
			tileSize(tileWidth, tileHeight),
			tileCount(size.x / tileSize.x, size.y / tileSize.y),
			tileCenter(tileWidth / 2, tileHeight / 2),
			spacing_(spacing),
			margin_(margin),
			texture(texture)
		{}

		sf::IntRect GetTileRect(uint8_t gid) const
		{
			return sf::IntRect(margin_ + (spacing_ + tileSize.x) * (gid % tileCount.x), margin_ + (spacing_ + tileSize.y) * (gid / tileCount.x), tileSize.x, tileSize.y);
		}

		const sf::Vector2u size, tileSize, tileCount;
		const sf::Vector2f tileCenter;
		const uint8_t spacing_, margin_;

	private:
		const sf::Texture* texture;
	};
};
