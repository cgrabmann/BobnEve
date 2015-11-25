#pragma once
#include "Enemy.h"

class Coin :
	public Enemy
{
public:
	Coin(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics, size_t enemyId);
	~Coin();

	virtual void Kill() override;
protected:
};

