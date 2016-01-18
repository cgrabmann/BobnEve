#pragma once
#include "PhysicsComponentBase.h"
#include "CollisionCallback.h"

class PhysicsComponentCoin :
	public PhysicsComponentBase,
		CollisionCallback
{
public:
	explicit PhysicsComponentCoin(PhysicBodyDef& bodyDef);
	~PhysicsComponentCoin();

	virtual void Update(GameObject& object, int16_t ms) override;
	virtual void collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody) override;

private:
	bool playerCollision_;
};

