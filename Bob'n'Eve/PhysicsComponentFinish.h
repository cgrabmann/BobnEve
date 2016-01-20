#pragma once
#include "PhysicsComponentBase.h"
#include "CollisionCallback.h"

class PhysicsComponentFinish :
	public PhysicsComponentBase,
	CollisionCallback
{
public:
	explicit PhysicsComponentFinish(PhysicBodyDef& bodyDef);
	virtual ~PhysicsComponentFinish();

	void Update(GameObject& object, int16_t ms) override;
	virtual void collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody) override;

private:
	bool playerCollision_;
};

