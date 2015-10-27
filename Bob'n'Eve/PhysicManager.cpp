#include "PhysicManager.h"

#include <Box2D/Common/b2Math.h>

PhysicManager::PhysicManager(float gravityX, float gravityY) : world_(b2Vec2(gravityX, gravityY))
{
}

PhysicManager::~PhysicManager()
{
}

//void PhysicManager::RegisterEntity(Player& player, b2BodyDef* bodyDef)
//{
//	player.setPhysicBody(world_.CreateBody(bodyDef));
//}