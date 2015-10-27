#include "Game.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"

Game::Game() : physicManager_(0.f, -10.f)
{
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