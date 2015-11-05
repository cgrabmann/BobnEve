#include "InputComponentJoystick.h"
#include <SFML/include/SFML/System/Vector2.hpp>


InputComponentJoystick::InputComponentJoystick(unsigned player, unsigned joystickCount) : InputComponentKeyboard(player)
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

void InputComponentJoystick::Update(GameObject& object, int16_t ms)
{
	InputComponentKeyboard::Update(object, ms);

	sf::Vector2f movement = sf::Vector2f(sf::Joystick::getAxisPosition(joystickId_, xAxis_), sf::Joystick::getAxisPosition(joystickId_, yAxis_));

	if (movement.x > threshold)
		this->Right(object);

	if (movement.x < -threshold)
		this->Left(object);

	if (movement.y < -threshold)
		this->Jump(object);
}

