#pragma once
#include "PhysicsComponentBase.h"
#include "CollisionCallback.h"

class PhysicsComponentEnemy :
	public PhysicsComponentBase,
	CollisionCallback
{
public:
	explicit PhysicsComponentEnemy(PhysicBodyDef& bodyDef, bool killable);
	virtual ~PhysicsComponentEnemy();

	void Update(GameObject& object, int16_t ms) override;
	virtual void collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody) override;

private:
	bool groundCollision_;
	bool playerCollision_;
	bool killable_;
};

