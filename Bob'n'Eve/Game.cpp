#include "Game.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "View.h"
#include "MapLoader.h"
#include "Vector2f.h"

Game::Game() : paused_(false)
{
	PhysicManager::CreateInstance(Vector2f(0.f, 10.f));
	view_ = MapLoader::LoadMap("Map1.tmx");
}

Game::~Game()
{
}

void Game::Loop()
{
	bool wasPDown = false, wasEscDown = false;
	bool isPDown = false, isEscDown = false;

	sf::RenderWindow& window = renderer_.GetWindow();
	sf::Clock clock;
	clock.restart();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Measure time since last frame    
		sf::Time elapsedTime = clock.restart();

#ifdef false
		if (elapsedTime.asMilliseconds() > 250 && elapsedTime.asMilliseconds() < 1000)
		{
			//Lag spike
			__debugbreak();
		}
#endif

		//Esc closes the game
		isEscDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
		if (!wasEscDown && isEscDown)
			window.close();
		wasEscDown = isEscDown;

		//P pauses the game
		isPDown = sf::Keyboard::isKeyPressed(sf::Keyboard::P);
		if (!wasPDown && isPDown)
			paused_ = !paused_;
		wasPDown = isPDown;

#ifndef  _DEBUG
		if (window.hasFocus() && !paused_)
#endif
		{
			view_->Update(elapsedTime.asMilliseconds());
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