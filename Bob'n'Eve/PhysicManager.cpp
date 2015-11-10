#include "PhysicManager.h"

#include <Box2D/Common/b2Math.h>
#include "GameObject.h"
#include "PhysicsComponentBase.h"

PhysicManager* PhysicManager::instance_ = NULL;
b2Vec2 PhysicManager::gravity_(0.f, 0.f);

PhysicManager::PhysicManager() : world_(gravity_)
{
}

PhysicManager::~PhysicManager()
{
}

PhysicManager* PhysicManager::Instance()
{
	static CGuard g;   // Speicherbereinigung
	if (!instance_)
		instance_ = new PhysicManager();
	return instance_;
}

void PhysicManager::SetGravity(Vector2f& gravity)
{
	gravity_ = gravity.ToBox2D();
}

void PhysicManager::createBody(PhysicsComponentBase& physicsComponent, b2BodyDef* bodyDef)
{
	physicsComponent.setPhysicBody(world_.CreateBody(bodyDef));
}