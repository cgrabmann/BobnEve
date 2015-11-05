#include "InputComponent.h"

InputComponent::InputComponent(unsigned player)
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

InputComponent::~InputComponent()
{

}

void InputComponent::Update(GameObject& object, int16_t ms)
{
	if (sf::Keyboard::isKeyPressed(keyLeft_))
		this->Left(object);

	if (sf::Keyboard::isKeyPressed(keyRight_))
		this->Right(object);

	if (sf::Keyboard::isKeyPressed(keyJump_))
		this->Jump(object);

}


