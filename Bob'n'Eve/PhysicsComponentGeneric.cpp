#include "PhysicsComponentGeneric.h"
#include "PhysicBodyDef.h"
#include "UpdateableCollisionCallback.h"

PhysicsComponentGeneric::PhysicsComponentGeneric(PhysicBodyDef& bodyDef, UpdateableCollisionCallback* callback) : PhysicsComponentBase(bodyDef.SetCallback(callback)),
callback_(callback)
{
	callback_->add();
}

PhysicsComponentGeneric::~PhysicsComponentGeneric()
{
	callback_->remove();
}

void PhysicsComponentGeneric::Update(GameObject& object, int16_t ms)
{
	callback_->update(object, ms);
}