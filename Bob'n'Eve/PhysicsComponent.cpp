#include "PhysicsComponent.h"
#include <stddef.h>


PhysicsComponent::PhysicsComponent() : body_(NULL)
{
}


PhysicsComponent::~PhysicsComponent()
{
}

void PhysicsComponent::Update(GameObject& object, int16_t ms)
{
	
}

void PhysicsComponent::setPhysicBody(b2Body* body)
{
	body_ = body;
}
