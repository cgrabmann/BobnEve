#include "PhysicManager.h"

PhysicManager* PhysicManager::instance_ = NULL;

PhysicManager::PhysicManager(const Vector2f& gravity) : world_(gravity)
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

void PhysicManager::Update(float ms)
{
	world_.Step(ms / 1000.f);
}

void PhysicManager::SetGravity(const Vector2f& gravity)
{
	world_.SetGravity(gravity);
}