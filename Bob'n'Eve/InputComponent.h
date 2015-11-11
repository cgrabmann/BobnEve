#pragma once
#include <cinttypes>

class GameObject;

class InputComponent
{
public:
	InputComponent();
	~InputComponent();

	virtual void Update(GameObject& player, int16_t ms);

	static InputComponent* GetBobInputComponent();
	static InputComponent* GetEveInputComponent();
protected:
	static InputComponent* GetPlayerInputComponent(uint8_t player);

	void Left(GameObject& player);
	void Right(GameObject& player);
	void Jump(GameObject& player);

	static uint8_t JoyStickCount();
};

