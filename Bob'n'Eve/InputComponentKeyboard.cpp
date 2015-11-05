#include "InputComponentKeyboard.h"

InputComponentKeyboard::InputComponentKeyboard(unsigned player)
{
	if (player == 1)
	{
		keyJump_ = sf::Keyboard::W;
		keyLeft_ = sf::Keyboard::A;
		keyRight_ = sf::Keyboard::D;
	}
	else
	{
		keyJump_ = sf::Keyboard::Up;
		keyLeft_ = sf::Keyboard::Left;
		keyRight_ = sf::Keyboard::Right;
	}
}

InputComponentKeyboard::~InputComponentKeyboard()
{

}

void InputComponentKeyboard::Update(Player& player, int16_t ms)
{
	if (sf::Keyboard::isKeyPressed(keyLeft_))
		this->Left(player);

	if (sf::Keyboard::isKeyPressed(keyRight_))
		this->Right(player);

	if (sf::Keyboard::isKeyPressed(keyJump_))
		this->Jump(player);

}


