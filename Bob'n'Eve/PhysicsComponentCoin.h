#pragma once
#include "CollisionCallback.h"
#include "PhysicsComponentStatic.h"

class PhysicsComponentCoin :
	public PhysicsComponentStatic,
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

