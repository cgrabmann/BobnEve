#include "InputComponent.h"
#include "Player.h"
#include <SFML/include/SFML/Window/Joystick.hpp>
#include "InputComponentJoystick.h"

InputComponent::InputComponent()
{
}


InputComponent::~InputComponent()
{
}

void InputComponent::Update(GameObject& object, int16_t ms)
{
}

InputComponent* InputComponent::GetBobInputComponent()
{
	return GetPlayerInputComponent(1);
}

InputComponent* InputComponent::GetEveInputComponent()
{
	return GetPlayerInputComponent(2);
}

InputComponent* InputComponent::GetPlayerInputComponent(uint8_t player)
{
	uint8_t count = JoyStickCount();

	if (count > 0)
	{
		return new InputComponentJoystick(player, count);
	}
	return new InputComponentKeyboard(player);
}

void InputComponent::Jump(GameObject& object)
{
	object.Up();
}

void InputComponent::Left(GameObject& object)
{
	object.Left();
}

void InputComponent::Right(GameObject& object)
{
	object.Right();
}

uint8_t InputComponent::JoyStickCount()
{
	if (sf::Joystick::isConnected(0) && sf::Joystick::isConnected(1))
		return 2;

	if (sf::Joystick::isConnected(0))
		return 1;

	return 0;
}
