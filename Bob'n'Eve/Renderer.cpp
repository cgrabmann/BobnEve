#include "Renderer.h"
#include "View.h"

#include <SFML\Graphics.hpp>


Renderer::Renderer() : window_(sf::VideoMode::getFullscreenModes()[0], "SFML works!", sf::Style::Fullscreen)
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

void Renderer::Render(View& view)
{
	window_.clear();
	view.Draw(*this);
	window_.display();
}

void Renderer::Draw(sf::Shape& shape)
{
	window_.draw(shape);
}
