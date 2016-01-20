#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "MapLoader.h"
#include "Vector2f.h"
#include "MainMenu.h"
#include "AssetManager.h"
#include "Global.h"

Game::Game() : paused_(true), board_(new LeaderBoard(Global::LEADERBOARD))
{
	PhysicManager::CreateInstance(Vector2f(0.f, 15.f));
	MapLoader::LoadMap("Map_Final.tmx");
	AssetManager::Instance()->RegisterFont("arial.ttf");
	AssetManager::Instance()->RegisterTexture("Title.png");
	menu_ = new MainMenu(Map::MapState::Active, sf::seconds(-1), board_);
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
	Map* view;

	while (window.isOpen())
	{
		view = Map::Instance();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
#ifndef  _DEBUG
			case sf::Event::LostFocus:
				Pause(view);
				break;
#endif
			case sf::Event::GainedFocus:
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					if (menu_ == nullptr)
					{
						Pause(view);
					}
					else
					{
						window.close();
					}
					break;
				case sf::Keyboard::Space:
					if (menu_ != nullptr && view->GetStatus() != Map::MapState::GameOver)
					{
						Resume(view);
					}
					break;
				case sf::Keyboard::R:
					if (menu_ != nullptr)
					{
						view->CleanUp();
						MapLoader::LoadMap("Map_Final.tmx");

						Resume(view);
					}
					break;
				default: break;
				}
			default: break;
			}
		}

		// Measure time since last frame    
		sf::Time elapsedTime = clock.restart();
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

			if (view->GetStatus() != Map::MapState::Active)
			{
				if (view->GetStatus() == Map::MapState::Victory)
				{
					board_->AddEntry(view->GetTime());
					board_->SaveEntires(Global::LEADERBOARD);
				}

				Pause(view);
			}
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

void Game::Pause(Map* view)
{
	menu_ = new MainMenu(view->GetStatus(), view->GetTime(), board_);
	renderer_.SetMenu(menu_);
	paused_ = true;
}

void Game::Resume(Map* view)
{
	delete menu_;
	menu_ = nullptr;
	renderer_.SetMenu(nullptr);
	paused_ = false;
}
