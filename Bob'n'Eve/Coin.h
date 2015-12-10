#pragma once
#include "GameObject.h"

class Coin :
	public GameObject
{
public:
	Coin(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics);
	~Coin();

	virtual void Update(int16_t ms) override;
	virtual void Kill() override;
protected:
};

