#pragma once
#include <SFML/include/SFML/Graphics/RenderWindow.hpp>

namespace sf{
	class RenderTarget;
	class Shape;
}

class View;

class Renderer
{
public:
	Renderer();
	~Renderer();

	sf::RenderWindow& GetWindow();
	sf::RenderTarget& GetTarget();

	sf::Vector2f GetScale();

	void Render(View& drawable);

private:
	sf::RenderWindow window_;

	sf::Vector2f scale_;

	void Draw(sf::Shape& shape);
};

