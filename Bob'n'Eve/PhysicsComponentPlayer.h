#pragma once
#include "PhysicsComponentBase.h"
#include "CollisionCallback.h"

class PhysicsComponentPlayer :
	public PhysicsComponentBase,
	CollisionCallback
{
public:
	explicit PhysicsComponentPlayer(PhysicBodyDef& bodyDef);
	virtual ~PhysicsComponentPlayer();

	virtual void Update(GameObject& object, int16_t ms) override;
	virtual void collidesWith(PhysicBodyBase& otherBody) override;

private:
	bool groundCollision_;
};

