#include "PhysicManager.h"

#include <Box2D/Common/b2Math.h>
#include "GameObject.h"
#include "PhysicsComponent.h"

PhysicManager::PhysicManager(float gravityX, float gravityY) : world_(b2Vec2(gravityX, gravityY))
{
}

PhysicManager::~PhysicManager()
{
}

void PhysicManager::createBody(PhysicsComponentBase& physicsComponent, b2BodyDef* bodyDef)
{
	physicsComponent.setPhysicBody(world_.CreateBody(bodyDef));
}