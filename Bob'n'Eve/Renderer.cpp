#include "Renderer.h"

#include <SFML\Graphics.hpp>

#include "Entity.h"


Renderer::Renderer() : window_(sf::VideoMode(200, 200), "SFML works!")
{
}


Renderer::~Renderer()
{
}

sf::RenderWindow& Renderer::GetWindow()
{
	return window_;
}

sf::RenderTarget& Renderer::GetTarget()
{
	return window_;
}

void Renderer::Render(Entity& rootEntity)
{
	window_.clear();
	rootEntity.Draw(*this);
	window_.display();
}

void Renderer::Draw(sf::Shape& shape)
{
	window_.draw(shape);
}
