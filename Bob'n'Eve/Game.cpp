#include "Game.h"

#define DEBUG

#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "View.h"
#include "MapLoader.h"

Game::Game() : paused_(false), physicManager_(0.f, -10.f), view_(MapLoader::LoadMap(""))
{
}

Game::~Game()
{
}

void Game::Loop()
{
	bool wasPDown = false, wasEscDown = false;
	bool isPDown = false, isEscDown = false;

	sf::RenderWindow& window = renderer_.GetWindow();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		isEscDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
		if (!wasEscDown && isEscDown)
			window.close();
		wasEscDown = isEscDown;

		isPDown = sf::Keyboard::isKeyPressed(sf::Keyboard::P);
		if (!wasPDown && isPDown)
		paused_ = !paused_;
		wasPDown = isPDown;

#ifndef  DEBUG
		if (window.hasFocus() && !paused_)
#endif
		{
			view_->Update(16);
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