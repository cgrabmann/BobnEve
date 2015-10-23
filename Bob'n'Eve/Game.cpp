#include "Game.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "View.h"

Game::Game() : physicManager_(b2Vec2(0.f, -10.f)), paused_(false)
{
	view_ = new View();
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

		if (window.hasFocus() && !paused_)
		{
			view_->Update(16.6f);
		}

		renderer_.Render(*view_);
	}
}

void Game::GetInput()
{
}

void Game::Start()
{
	sf::RenderWindow& window = renderer_.GetWindow();
	window.setKeyRepeatEnabled(true);
	window.setJoystickThreshold(0.15f);
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
	window.setVerticalSyncEnabled(true);

	Loop();
}

void Game::Stop()
{
}