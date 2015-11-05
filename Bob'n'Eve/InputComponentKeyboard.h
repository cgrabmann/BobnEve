#pragma once
#include <cinttypes>
#include <SFML/include/SFML/Window/Keyboard.hpp>
#include "InputComponentBase.h"
class Player;

class InputComponentKeyboard : public InputComponentBase
{
public:
	InputComponentKeyboard(unsigned int player);
	~InputComponentKeyboard();

	virtual void Update(Player& player, int16_t ms) override;

protected:
	sf::Keyboard::Key keyLeft_;
	sf::Keyboard::Key keyRight_;
	sf::Keyboard::Key keyJump_;
};

