#include "Renderer.h"
#include "View.h"

#include <SFML\Graphics.hpp>


Renderer::Renderer() : window_(sf::VideoMode::getFullscreenModes()[0], "SFML works!", sf::Style::Fullscreen)
{
	window_.setKeyRepeatEnabled(true);
	window_.setJoystickThreshold(0.15f);
	window_.setFramerateLimit(60);
	window_.setMouseCursorVisible(false);
	window_.setVerticalSyncEnabled(true);

	sf::Vector2u size = window_.getSize();

	sf::View view(sf::FloatRect(0, 0, size.x, size.y));
	window_.setView(view);
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
	sf::View view_ = window_.getView();
	//TODO: Center on players
	view_.setCenter(960.0f, 540.0f);
	window_.setView(view_);

	window_.clear();
	view.Draw(*this);
	window_.display();
}

void Renderer::Draw(sf::Shape& shape)
{
	window_.draw(shape);
}
