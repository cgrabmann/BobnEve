#include "InputComponentBase.h"
#include "Player.h"
#include <SFML/include/SFML/Window/Joystick.hpp>
#include "InputComponentJoystick.h"

InputComponentBase::InputComponentBase()
{
}


InputComponentBase::~InputComponentBase()
{
}

InputComponentBase* InputComponentBase::GetBobInputComponent()
{
	if (sf::Joystick::isConnected(0))
	{
		return new InputComponentJoystick(1, 0);
	}
	return new InputComponent(1);
}

InputComponentBase* InputComponentBase::GetEveInputComponent()
{
	if (sf::Joystick::isConnected(1))
	{
		return new InputComponentJoystick(2, 1);
	}
	return new InputComponent(2);
}

void InputComponentBase::Jump(Player& player)
{
	player.Jump();
}

void InputComponentBase::Left(Player& player)
{
	player.MoveLeft();
}

void InputComponentBase::Right(Player& player)
{
	player.MoveRight();
}

