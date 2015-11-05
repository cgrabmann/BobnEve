#pragma once
#include "PhysicsComponentBase.h"

class PhysicsComponentGravity :
	public PhysicsComponentBase
{
	friend class PhysicManager;
public:
	explicit PhysicsComponentGravity(Vector2f* position) : PhysicsComponentBase(position){}
	explicit PhysicsComponentGravity(float x, float y) : PhysicsComponentBase(x, y){}
	~PhysicsComponentGravity();

	void Update(GameObject& object, int16_t ms) override;
};

