#pragma once
#include <cinttypes>

class InputComponent;
class Player;

class InputComponentBase
{
public:
	InputComponentBase();
	~InputComponentBase();

	virtual void Update(Player& player, int16_t ms) = 0;

	static InputComponentBase* GetBobInputComponent();
	static InputComponentBase* GetEveInputComponent();
protected:
	static InputComponentBase* GetPlayerInputComponent(uint8_t player);

	void Left(Player& player);
	void Right(Player& player);
	void Jump(Player& player);

	static uint8_t JoyStickCount();
};

