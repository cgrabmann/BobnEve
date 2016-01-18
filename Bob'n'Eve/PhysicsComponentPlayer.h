#pragma once
#include "PhysicsComponentBase.h"
#include "CollisionCallback.h"
#include <unordered_map>

class PhysicsComponentPlayer :
	public PhysicsComponentBase,
	CollisionCallback
{
public:
	explicit PhysicsComponentPlayer(PhysicBodyDef& bodyDef);
	virtual ~PhysicsComponentPlayer();

	virtual void Update(GameObject& object, int16_t ms) override;
	virtual void collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody) override;

private:
	bool groundCollision_;
	bool gravitySwitched_;
	bool shouldDie_;
	std::unordered_map<PhysicBodyBase*, int16_t> passThroughs_;
};

