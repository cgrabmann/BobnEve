#include "PhysicManager.h"

#include <Box2D/Common/b2Math.h>

#include "Entity.h"

PhysicManager::PhysicManager(float gravityX, float gravityY) : world_(b2Vec2(gravityX, gravityY))
{
}

PhysicManager::~PhysicManager()
{
}

void PhysicManager::RegisterEntity(Entity& entity, b2BodyDef* bodyDef)
{
	entity.setPhysicBody(world_.CreateBody(bodyDef));
}