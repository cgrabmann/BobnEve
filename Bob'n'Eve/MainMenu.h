#pragma once
#include "MenuBase.h"
#include <SFML/include/SFML/Graphics/Sprite.hpp>
#include "Map.h"

namespace sf{
	class Time;
	class Text;
}

class LeaderBoard;

class MainMenu : public MenuBase
{
public:
	MainMenu(Map::MapState status, sf::Time time, LeaderBoard* board);
	virtual void Update(int16_t ms) override;
private:
	sf::Font font_;
};

