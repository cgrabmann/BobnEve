#include "PhysicsComponentGeneric.h"
#include "PhysicBodyDef.h"
#include "UpdateableCollisionCallback.h"

PhysicsComponentGeneric::PhysicsComponentGeneric(PhysicBodyDef& bodyDef, UpdateableCollisionCallback* callback) : PhysicsComponentBase(bodyDef.SetCallback(callback)),
callback_(callback)
{
	if (callback_)
		callback_->add();
}

PhysicsComponentGeneric::~PhysicsComponentGeneric()
{
	if (callback_)
		callback_->remove();
}

void PhysicsComponentGeneric::Update(GameObject& object, int16_t ms)
{
	if (callback_)
		callback_->update(object, ms);
}