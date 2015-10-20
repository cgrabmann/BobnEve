#include "PhysicManager.h"

#include <Box2D/Common/b2Math.h>

#include "Entity.h"

PhysicManager::PhysicManager(b2Vec2& gravity) : world_(gravity)
{
}

PhysicManager::~PhysicManager()
{
}

void PhysicManager::RegisterEntity(Entity& entity, b2BodyDef* bodyDef)
{
	entity.setPhysicBody(world_.CreateBody(bodyDef));
}