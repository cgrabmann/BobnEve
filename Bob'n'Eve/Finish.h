#pragma once
#include "GameObject.h"
class Finish :
	public GameObject
{
public:
	Finish(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics);
	~Finish();

	virtual void Kill() override;
	virtual void Update(int16_t ms) override;
};

