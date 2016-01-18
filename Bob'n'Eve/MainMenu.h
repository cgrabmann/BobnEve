#pragma once
#include "MenuBase.h"
#include <SFML/include/SFML/Graphics/Sprite.hpp>

namespace sf{
	class Time;
	class Text;
}

class LeaderBoard;

class MainMenu : public MenuBase
{
public:
	MainMenu(sf::Time time, LeaderBoard* board);

	virtual void Update(int16_t ms) override;
private:
	sf::Font font_;
};

