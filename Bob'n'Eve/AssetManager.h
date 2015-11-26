#pragma once

#include <string>
#include <unordered_map>
#include <cinttypes>
#include <SFML/include/SFML/Graphics/Rect.hpp>
#include <SFML/include/SFML/Graphics/Texture.hpp>

namespace sf{
	class Font;
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

	sf::Sprite* GetSprite(const std::string& name);
	sf::Sprite* GetTile(const std::string& name, const uint8_t gid);
	sf::Sound* GetSound(const std::string& name);
	sf::Music* GetMusic(const std::string& name);
	sf::Font* GetFont(const std::string& name);

	void RegisterTexture(const std::string& name);
	void RegisterTileSet(const std::string& name, const uint32_t tileWidth, const uint32_t tileHeight, const uint8_t spacing = 0, const uint8_t margin = 0);
	void RegisterSound(const std::string& name);
	void RegisterMusic(const std::string& name);
	void RegisterFont(const std::string& name);

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
	std::unordered_map<std::string, sf::Font*> fonts_;

	std::string textureDir_;
	std::string soundDir_;
	std::string musicDir_;
	std::string fontDir_;

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
