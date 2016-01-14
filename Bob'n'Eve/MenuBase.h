#pragma once
#include <cstdint>
#include <SFML/include/SFML/Graphics/Drawable.hpp>
#include <vector>
#include <SFML/include/SFML/Graphics/Text.hpp>
#include <SFML/include/SFML/Graphics/Sprite.hpp>

class Renderer;

class MenuBase
{
public:
	MenuBase();

	virtual void Update(int16_t ms);
	virtual void Draw(Renderer& renderer) const;
	void CenterSprite(sf::Sprite* sprite, int top) const;
	void CenterText(sf::Text* text, int top) const;
	void RTLText(sf::Text* text, int left, int top) const;

	void AddElement(sf::Drawable* element)
	{
		elements_.push_back(element);
	}

	bool IsActive() const
	{
		return isActive_;
	}

	void IsActive(bool set)
	{
		isActive_ = set;
	}

protected:
	std::vector<sf::Drawable*> elements_;
	bool isActive_;
};

