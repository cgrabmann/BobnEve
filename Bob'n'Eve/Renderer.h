#pragma once
#include <SFML/include/SFML/Graphics/RenderWindow.hpp>
#include "Vector2f.h"

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

	Vector2f GetScale() const;

	void Render();

private:
	sf::RenderWindow window_;

	Vector2f scale_;

	void Draw(sf::Shape& shape);
};

