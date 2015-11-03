#include "PhysicsComponent.h"
#include <stddef.h>


PhysicsComponentBase::PhysicsComponentBase() : body_(NULL)
{
}


PhysicsComponentBase::~PhysicsComponentBase()
{
}

void PhysicsComponentBase::Update(GameObject& object, int16_t ms)
{
	
}

void PhysicsComponentBase::setPhysicBody(b2Body* body)
{
	body_ = body;
}
