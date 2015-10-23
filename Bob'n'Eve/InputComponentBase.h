#pragma once
#include <cinttypes>

class Player;

class InputComponentBase
{
public:
	InputComponentBase();
	~InputComponentBase();

	virtual void Update(Player& player, int16_t ms) = 0;
protected:

	void Left(Player& player);
	void Right(Player& player);
	void Jump(Player& player);
};

