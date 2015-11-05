#pragma once
#include <cinttypes>

class GameObject;

class InputComponentBase
{
public:
	InputComponentBase();
	~InputComponentBase();

	virtual void Update(GameObject& player, int16_t ms);

	static InputComponentBase* GetBobInputComponent();
	static InputComponentBase* GetEveInputComponent();
protected:
	static InputComponentBase* GetPlayerInputComponent(uint8_t player);

	void Left(GameObject& player);
	void Right(GameObject& player);
	void Jump(GameObject& player);

	static uint8_t JoyStickCount();
};

