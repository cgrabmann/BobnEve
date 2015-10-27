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
	void Render(View& drawable);

private:
	sf::RenderWindow window_;

	void Draw(sf::Shape& shape);
};

