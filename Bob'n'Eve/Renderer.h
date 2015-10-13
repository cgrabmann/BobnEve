#pragma once
#include <SFML/include/SFML/Graphics/RenderWindow.hpp>

namespace sf{
	class Shape;
}

class Entity;

class Renderer
{
	friend class Entity;
private:
	sf::RenderWindow window_;

	void Draw(sf::Shape& shape);

public:
	Renderer();
	~Renderer();

	void GetWindow(sf::RenderWindow*& window);
	void Render(Entity& drawable);
};

