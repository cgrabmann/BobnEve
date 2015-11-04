#include "InputComponentJoystick.h"
#include <SFML/include/SFML/System/Vector2.hpp>
#include <iostream>


InputComponentJoystick::InputComponentJoystick(unsigned player, unsigned joystickCount) : InputComponent(player)
{
	if (player == 1)
	{
		joystickId_ = 0;
		//Linker Stick
		xAxis_ = sf::Joystick::X;
		yAxis_ = sf::Joystick::Y;
	}
	else
	{
		if (joystickCount == 1)
		{
			joystickId_ = 0;
			//Rechter Stick
			xAxis_ = sf::Joystick::Z;
			yAxis_ = sf::Joystick::R;
		}
		else
		{
			joystickId_ = 1;
			//Linker Stick
			xAxis_ = sf::Joystick::X;
			yAxis_ = sf::Joystick::Y;
		}
	}
}


InputComponentJoystick::~InputComponentJoystick()
{
}

void InputComponentJoystick::Update(Player& player, int16_t ms)
{
	InputComponent::Update(player, ms);

	sf::Vector2f movement = sf::Vector2f(sf::Joystick::getAxisPosition(joystickId_, xAxis_), sf::Joystick::getAxisPosition(joystickId_, yAxis_));

	if (movement.x > threshold)
		this->Right(player);

	if (movement.x < -threshold)
		this->Left(player);

	if (movement.y < -threshold)
		this->Jump(player);
}

