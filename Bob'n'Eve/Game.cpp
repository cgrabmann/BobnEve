#include "Game.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "View.h"
#include "MapLoader.h"
#include "Vector2f.h"

Game::Game() : paused_(false)
{
	PhysicManager::CreateInstance(Vector2f(0.f, 10.f));
	view_ = MapLoader::LoadMap("01.tmx");
}

Game::~Game()
{
}

void Game::Loop()
{
	bool wasPDown = false, wasEscDown = false;
	bool isPDown = false, isEscDown = false;

	PhysicManager* physicManager = PhysicManager::Instance();

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

#ifndef  _DEBUG
		if (window.hasFocus() && !paused_)
#endif
		{
			view_->Update(16);
		}

		if (!paused_)
		{
			physicManager->Update(1.f / 60.f);
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