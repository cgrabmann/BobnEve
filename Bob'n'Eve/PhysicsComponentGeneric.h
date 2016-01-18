#pragma once
#include "PhysicsComponentBase.h"

class UpdateableCollisionCallback;

class PhysicsComponentGeneric :
	public PhysicsComponentBase
{
public:
	explicit PhysicsComponentGeneric(PhysicBodyDef& bodyDef, UpdateableCollisionCallback* callback);
	virtual ~PhysicsComponentGeneric();

	virtual void Update(GameObject& object, int16_t ms) override;
private:
	UpdateableCollisionCallback* callback_;
};

