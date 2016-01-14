#include "MainMenu.h"
#include "LeaderBoard.h"
#include <SFML/include/SFML/Graphics/Text.hpp>
#include "Global.h"
#include <sstream>
#include <cassert>
#include "AssetManager.h"
#include <SFML/include/SFML/Graphics/Sprite.hpp>

MainMenu::MainMenu(int points, LeaderBoard* board)
{	
	font_ = *AssetManager::Instance()->GetFont("arial.ttf");

	sf::Color green = sf::Color(0, 255, 33);
	sf::Color pink = sf::Color(190, 7, 130);
	sf::Color blue = sf::Color(0, 28, 191);

	std::stringstream streamBuilder;

	if (points >= 0)
	{
		sf::Text* scoreHeader = new sf::Text("Your Score:", font_, 128);
		scoreHeader->setColor(green);
		CenterText(scoreHeader, 50);
		elements_.push_back(scoreHeader);

		streamBuilder << points << " Points";
		sf::Text* score = new sf::Text(streamBuilder.str(), font_, 72);
		score->setColor(blue);
		CenterText(score, 200);
		elements_.push_back(score);
	}
	else
	{
		sf::Sprite* title = AssetManager::Instance()->GetSprite("Title.png");
		CenterSprite(title, 50);
		elements_.push_back(title);
	}

	sf::Text* boardHeader = new sf::Text("Leaderboard:", font_, 128);
	boardHeader->setColor(green);
	CenterText(boardHeader, 400);
	elements_.push_back(boardHeader);

	int size = board->GetSize();
	int* boardScores = board->GetEntries();
	for (int i = 0; i < size; i++)
	{
		streamBuilder.str("");
		streamBuilder << (i + 1) << ".) " << boardScores[i] << " Points";
		sf::Text* boardEntry = new sf::Text(streamBuilder.str(), font_, 72);
		boardEntry->setColor(blue);
		CenterText(boardEntry, 550 + 100 * i);
		elements_.push_back(boardEntry);
	}

	sf::Text* start = new sf::Text("Space to game - ESC to quit", font_, 64);
	start->setColor(pink);
	CenterText(start, 950);
	elements_.push_back(start);
}

void MainMenu::Update(int16_t ms)
{
}
