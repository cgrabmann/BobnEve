#pragma once
#include <SFML/include/SFML/Graphics/RenderWindow.hpp>
#include "Vector2f.h"
#include "MenuBase.h"

namespace sf{
	class RenderTarget;
	class Shape;
}

class Map;

class Renderer
{
public:
	Renderer();
	~Renderer();

	sf::RenderWindow& GetWindow()
	{
		return window_;
	}

	sf::RenderTarget& GetTarget()
	{
		return window_;
	}

	void SetMenu(MenuBase* menu)
	{
		menu_ = menu;
	}

	Vector2f GetScale() const
	{
		return scale_;
	}

	void Render();

	static std::string TimeToString(sf::Time time);

private:
	sf::View GetGameView();
	sf::View GetMapView();
	sf::View GetMenuView();

	MenuBase* menu_;

	sf::RenderWindow window_;

	Vector2f scale_;

	void Draw(sf::Shape& shape);
};

