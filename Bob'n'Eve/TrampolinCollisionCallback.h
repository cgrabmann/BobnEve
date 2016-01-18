#pragma once
#include "UpdateableCollisionCallback.h"
#include <vector>

class TrampolinCollisionCallback :
	public UpdateableCollisionCallback
{
public:
	TrampolinCollisionCallback();
	virtual ~TrampolinCollisionCallback();

	virtual void collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody) override;
	virtual void update(GameObject& object, int16_t ms) override;

private:
	std::vector<PhysicBodyBase*> alreadyBounced;
};

