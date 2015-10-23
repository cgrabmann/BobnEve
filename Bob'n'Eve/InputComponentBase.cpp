#include "InputComponentBase.h"
#include "Player.h"

InputComponentBase::InputComponentBase()
{
}


InputComponentBase::~InputComponentBase()
{
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

