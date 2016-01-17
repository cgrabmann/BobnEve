#include "Game.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "View.h"
#include "MapLoader.h"
#include "Vector2f.h"
#include "MainMenu.h"
#include "AssetManager.h"
#include "Global.h"

Game::Game() : paused_(true), board_(new LeaderBoard(Global::LEADERBOARD))
{
	PhysicManager::CreateInstance(Vector2f(0.f, 15.f));
	MapLoader::LoadMap("Map1.tmx");
	AssetManager::Instance()->RegisterFont("arial.ttf");
	AssetManager::Instance()->RegisterTexture("Title.png");
	menu_ = new MainMenu(sf::seconds(-1), board_);
	renderer_.SetMenu(menu_);
}

Game::~Game()
{
}

void Game::Loop()
{
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
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::LostFocus:
				menu_ = new MainMenu(sf::seconds(-1), board_);
				renderer_.SetMenu(menu_);
				paused_ = true;
				break;
			case sf::Event::GainedFocus:
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					if (menu_ == nullptr)
					{
						menu_ = new MainMenu(sf::seconds(-1), board_);
						renderer_.SetMenu(menu_);
						paused_ = true;
					}
					else
					{
						window.close();
					}
					break;
				case sf::Keyboard::Space:
					if (menu_ != nullptr)
					{
						delete menu_;
						menu_ = nullptr;
						renderer_.SetMenu(nullptr);
						paused_ = false;
					}
					break;
				case sf::Keyboard::R:
					if (menu_ != nullptr)
					{
						view->CleanUp();
						MapLoader::LoadMap("Map1.tmx");

						delete menu_;
						menu_ = nullptr;
						renderer_.SetMenu(nullptr);
						paused_ = false;
					}
					break;
				}
			}
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
			board_->SaveEntires(Global::LEADERBOARD);

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