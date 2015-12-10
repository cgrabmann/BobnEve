#include "PhysicManager.h"
#include <algorithm>

PhysicManager* PhysicManager::instance_ = NULL;

PhysicManager::PhysicManager(const Vector2f& gravity) : world_(gravity)
{
	timeStep_ = 20;
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
		instance_ = new PhysicManager(gravity);
}

PhysicBodyBase* PhysicManager::CreateBody(const PhysicBodyDef& bodyDef)
{
	return world_.CreateBody(bodyDef);
}

void PhysicManager::DestroyBody(PhysicBodyBase& body)
{
	world_.DestroyBody(body);
}

void PhysicManager::Update(int16_t ms)
{
	while (ms > 0)
	{
		world_.Step(std::min(ms, timeStep_) / 1000.f);
		ms -= timeStep_;
	}
}

void PhysicManager::SetGravity(const Vector2f& gravity)
{
	world_.SetGravity(gravity);
}