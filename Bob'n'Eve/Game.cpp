#include "Game.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "EntityComposite.h"

Game::Game()
{
	renderer_ = Renderer();
	view_ = new EntityComposite(1.0f,0,Entity::TypeEnum::PLATFORM);
}

Game::~Game()
{
}

void Game::Loop()
{
	sf::RenderWindow* window = nullptr;
	renderer_.GetWindow(window);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		renderer_.Render(*view_);
	}
}

void Game::GetInput()
{
}

void Game::Start()
{
}

void Game::Stop()
{
}