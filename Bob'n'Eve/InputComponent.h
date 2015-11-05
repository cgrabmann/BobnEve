#pragma once
#include <cinttypes>
#include <SFML/include/SFML/Window/Keyboard.hpp>
#include "InputComponentBase.h"
class Player;

class InputComponent : public  InputComponentBase
{
public:
	InputComponent(unsigned int player);
	~InputComponent();

	virtual void Update(GameObject& player, int16_t ms) override;

protected:
	sf::Keyboard::Key keyLeft_;
	sf::Keyboard::Key keyRight_;
	sf::Keyboard::Key keyJump_;
};

