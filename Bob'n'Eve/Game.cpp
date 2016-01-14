#include "Game.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "View.h"
#include "MapLoader.h"
#include "Vector2f.h"
#include "MainMenu.h"
#include "AssetManager.h"

Game::Game() : paused_(true), board_(new LeaderBoard(""))
{
	PhysicManager::CreateInstance(Vector2f(0.f, 15.f));
	MapLoader::LoadMap("Map1.tmx");
	AssetManager::Instance()->RegisterFont("arial.ttf");
	AssetManager::Instance()->RegisterTexture("Title.png");
	menu_ = new MainMenu(-1, board_);
	renderer_.SetMenu(menu_);
}

Game::~Game()
{
}

void Game::Loop()
{
	bool wasSpaceDown = false, wasEscDown = false;
	bool isSpaceDown = false, isEscDown = false;

	sf::RenderWindow& window = renderer_.GetWindow();
	sf::Clock clock;
	clock.restart();
	View* view;

	while (window.isOpen())
	{
		view = View::Instance();

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
		{
			if (menu_ == nullptr)
			{
				menu_ = new MainMenu(-1, board_);
				renderer_.SetMenu(menu_);
				paused_ = true;
			}
			else
			{
				window.close();
			}

		}
		wasEscDown = isEscDown;

		//P pauses the game
		isSpaceDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
		if (!wasSpaceDown && isSpaceDown)
			if (menu_ != nullptr)
			{
				delete menu_;
				menu_ = nullptr;
				renderer_.SetMenu(nullptr);
				paused_ = false;
			}
		wasSpaceDown = isSpaceDown;

		if (!paused_
#ifndef  _DEBUG
			&& window.hasFocus() 
#endif
			)
		{
			view->Update(
#ifndef  _DEBUG
				elapsedTime.asMilliseconds()
#else
				16.6f
#endif
				);
		}

		if (!view->IsActive())
		{
			board_->AddEntry(view->GetScore());

			menu_ = new MainMenu(view->GetScore(), board_);
			renderer_.SetMenu(menu_);
			paused_ = true;

			view->CleanUp();
			MapLoader::LoadMap("Map1.tmx");
		}

		renderer_.Render();
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
	renderer_.GetWindow().close();
}