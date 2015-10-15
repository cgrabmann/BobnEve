#include "Renderer.h"

#include <SFML\Graphics.hpp>

#include "Entity.h"


Renderer::Renderer()
{
	window_.create(sf::VideoMode(200, 200), "SFML works!");
}


Renderer::~Renderer()
{
}

void Renderer::GetWindow(sf::RenderWindow*& window)
{
	window = &window_;
}

void Renderer::Render(Entity& drawable)
{
	window_.clear();
	drawable.Draw(*this);
	window_.display();
}

void Renderer::Draw(sf::Shape& shape)
{
	window_.draw(shape);
}
