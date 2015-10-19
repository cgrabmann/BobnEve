#pragma once
#include <SFML/include/SFML/Graphics/RenderWindow.hpp>

namespace sf{
	class RenderTarget;
	class Shape;
}

class Entity;

class Renderer
{
	friend class Entity;
public:
	Renderer();
	~Renderer();

	sf::RenderWindow& GetWindow();
	sf::RenderTarget& GetTarget();
	void Render(Entity& drawable);

private:
	sf::RenderWindow window_;

	void Draw(sf::Shape& shape);
};

