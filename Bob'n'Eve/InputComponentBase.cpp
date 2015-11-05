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

void InputComponentBase::Update(GameObject& object, int16_t ms)
{
}

InputComponentBase* InputComponentBase::GetBobInputComponent()
{
	return GetPlayerInputComponent(1);
}

InputComponentBase* InputComponentBase::GetEveInputComponent()
{
	return GetPlayerInputComponent(2);
}

InputComponentBase* InputComponentBase::GetPlayerInputComponent(uint8_t player)
{
	uint8_t count = JoyStickCount();

	if (count > 0)
	{
		return new InputComponentJoystick(player, count);
	}
	return new InputComponentKeyboard(player);
}

void InputComponentBase::Jump(GameObject& object)
{
	object.Up();
}

void InputComponentBase::Left(GameObject& object)
{
	object.Left();
}

void InputComponentBase::Right(GameObject& object)
{
	object.Right();
}

uint8_t InputComponentBase::JoyStickCount()
{
	if (sf::Joystick::isConnected(0) && sf::Joystick::isConnected(1))
		return 2;

	if (sf::Joystick::isConnected(0))
		return 1;

	return 0;
}
