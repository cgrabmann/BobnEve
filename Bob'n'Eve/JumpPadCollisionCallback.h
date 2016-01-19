#pragma once
#include "UpdateableCollisionCallback.h"
#include <unordered_map>

class JumpPadCollisionCallback :
	public UpdateableCollisionCallback
{
public:
	JumpPadCollisionCallback();
	virtual ~JumpPadCollisionCallback();

	virtual void collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody) override;
	virtual void update(GameObject& object, int16_t ms) override;

private:
	std::unordered_map<PhysicBodyBase*, float> standingOnPad;
	std::unordered_map<PhysicBodyBase*, float> standingUnderPad;
};

