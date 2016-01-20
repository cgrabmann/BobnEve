#include "MainMenu.h"
#include "LeaderBoard.h"
#include <SFML/include/SFML/Graphics/Text.hpp>
#include "Global.h"
#include <sstream>
#include <cassert>
#include "AssetManager.h"
#include <SFML/include/SFML/Graphics/Sprite.hpp>
#include <SFML/include/SFML/System/Time.hpp>
#include "Renderer.h"

MainMenu::MainMenu(Map::MapState status, sf::Time time, LeaderBoard* board)
{
	font_ = *AssetManager::Instance()->GetFont("arial.ttf");

	sf::Color green = sf::Color(0, 255, 33);
	sf::Color pink = sf::Color(190, 7, 130);
	sf::Color blue = sf::Color(0, 28, 191);

	switch (status)
	{
	case Map::Active:
	{
		sf::Sprite* title = AssetManager::Instance()->GetSprite("Title.png");
		CenterSprite(title, 75);
		elements_.push_back(title);
	}
	break;
	case Map::Victory:
	{
		sf::Text* scoreHeader = new sf::Text("You WIN!", font_, 128);
		scoreHeader->setColor(pink);
		CenterText(scoreHeader, 50);
		elements_.push_back(scoreHeader);

		sf::Text* score = new sf::Text(Renderer::TimeToString(time), font_, 72);
		score->setColor(green);
		CenterText(score, 200);
		elements_.push_back(score);
	}
	break;
	case Map::GameOver:
	{
		sf::Text* scoreHeader = new sf::Text("Game Over!", font_, 256);
		scoreHeader->setColor(green);
		CenterText(scoreHeader, 50);
		elements_.push_back(scoreHeader);
	}
	break;
	default: break;
	}

	sf::Text* boardHeader = new sf::Text("Leaderboard:", font_, 128);
	boardHeader->setColor(pink);
	CenterText(boardHeader, 400);
	elements_.push_back(boardHeader);

	int size = board->GetSize();
	sf::Time* boardScores = board->GetEntries();
	std::stringstream streamBuilder;
	for (int i = 0; i < size; i++)
	{
		streamBuilder.str("");
		streamBuilder << (i + 1) << ".) " << Renderer::TimeToString(boardScores[i]);
		sf::Text* boardEntry = new sf::Text(streamBuilder.str(), font_, 72);
		boardEntry->setColor(green);
		CenterText(boardEntry, 550 + 100 * i);
		elements_.push_back(boardEntry);
	}

	streamBuilder.str("");
	if (status == Map::MapState::Active)
	{
		streamBuilder << "Space to game - ";
	}
	streamBuilder << "R to restart - ESC to quit";
	sf::Text* start = new sf::Text(streamBuilder.str(), font_, 64);
	start->setColor(pink);
	CenterText(start, 900);
	elements_.push_back(start);

	sf::Text* copyright = new sf::Text("© Grabmann Clemens - Radlwimmer Stefan - Reiter Jacqueline", font_, 48);
	copyright->setColor(green);
	CenterText(copyright, 1000);
	elements_.push_back(copyright);
}

void MainMenu::Update(int16_t ms)
{
}
