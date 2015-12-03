#pragma once
#include "GameObject.h"

class Coin :
	public GameObject
{
public:
	Coin(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics);
	~Coin();
protected:
};

