#include "PhysicManager.h"

#include <Box2D/Common/b2Math.h>
#include "GameObject.h"
#include "PhysicsComponent.h"

PhysicManager* PhysicManager::instance_ = NULL;

PhysicManager::PhysicManager(const b2Vec2& gravity) : world_(gravity)
{
}

PhysicManager::~PhysicManager()
{
}

PhysicManager* PhysicManager::Instance()
{
	return instance_;
}

void PhysicManager::CreateInstance(const Vector2f& gravity)
{
	static CGuard g;   // Speicherbereinigung
	if (!instance_)
		instance_ = new PhysicManager(gravity.ToBox2D());
}

b2Body* PhysicManager::CreateBody(b2BodyDef* bodyDef)
{
	return world_.CreateBody(bodyDef);
}

void PhysicManager::DestroyBody(b2Body* body)
{
	world_.DestroyBody(body);
}

void PhysicManager::Update(float32 seconds)
{
	world_.Step(seconds, 6, 2);
}