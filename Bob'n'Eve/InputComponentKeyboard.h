#pragma once
#include <cinttypes>
#include <SFML/include/SFML/Window/Keyboard.hpp>
#include "InputComponent.h"
class Player;

class InputComponentKeyboard : public InputComponent
{
public:
	InputComponentKeyboard(unsigned int player);
	~InputComponentKeyboard();

	virtual void Update(GameObject& player, int16_t ms) override;

protected:
	sf::Keyboard::Key keyLeft_;
	sf::Keyboard::Key keyRight_;
	sf::Keyboard::Key keyJump_;
};

