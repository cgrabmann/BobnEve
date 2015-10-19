#include "Game.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "EntityComposite.h"

Game::Game() : world_(b2Vec2(0.f, -10.f))
{
	view_ = new EntityComposite(1.0f,0,Entity::TypeEnum::PLATFORM);
}

Game::~Game()
{
}

void Game::Loop()
{
	sf::RenderWindow& target = renderer_.GetWindow();

	while (target.isOpen())
	{
		sf::Event event;
		while (target.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				target.close();
		}
		renderer_.Render(*view_);
	}
}

void Game::GetInput()
{
}

void Game::Start()
{
	Loop();
}

void Game::Stop()
{
}