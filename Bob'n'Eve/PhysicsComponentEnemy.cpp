#include "PhysicsComponentEnemy.h"
#include "PhysicBodyDef.h"
#include "GameObject.h"

PhysicsComponentEnemy::PhysicsComponentEnemy(PhysicBodyDef& bodyDef) : PhysicsComponentBase(bodyDef.SetCallback(this)), groundCollision_(false)
{
}

PhysicsComponentEnemy::~PhysicsComponentEnemy()
{
}

void PhysicsComponentEnemy::Update(GameObject& object, int16_t ms)
{
	object.SetOnGround(groundCollision_);
	groundCollision_ = false;
}

void PhysicsComponentEnemy::collidesWith(PhysicBodyBase& otherBody)
{
	if (otherBody.GetCustomId() == "Platform" && otherBody.GetPosition().y * otherBody.GetPhysicScale() > body_->GetPosition().y * body_->GetPhysicScale())
	{
		groundCollision_ = true;
	}
}