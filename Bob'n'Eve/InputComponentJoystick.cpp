#include "InputComponentJoystick.h"
#include <SFML/include/SFML/System/Vector2.hpp>


InputComponentJoystick::InputComponentJoystick(unsigned player, unsigned joystickId) : InputComponent(player), joystickId_(joystickId)
{
	if ((player == 1 && joystickId == 0) || (player == 2 && joystickId == 1))
	{//Linker Stick
		xAxis_ = sf::Joystick::X;
		yAxis_ = sf::Joystick::Y;
	}
	else
	{//Rechter Stick
		xAxis_ = sf::Joystick::R;
		yAxis_ = sf::Joystick::U;
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

	if (movement.y > threshold)
		this->Jump(player);
}

