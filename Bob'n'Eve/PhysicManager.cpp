#include "PhysicManager.h"

#include <Box2D/Common/b2Math.h>

PhysicManager::PhysicManager(b2Vec2& gravity) : world_(gravity)
{
}

PhysicManager::~PhysicManager()
{
}

//void PhysicManager::RegisterEntity(Player& player, b2BodyDef* bodyDef)
//{
//	player.setPhysicBody(world_.CreateBody(bodyDef));
//}