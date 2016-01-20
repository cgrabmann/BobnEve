#include "PhysicsComponentEnemy.h"
#include "PhysicBodyDef.h"
#include "GameObject.h"

PhysicsComponentEnemy::PhysicsComponentEnemy(PhysicBodyDef& bodyDef) : PhysicsComponentBase(bodyDef.SetCallback(this)), groundCollision_(false), playerCollision_(false)
{
}

PhysicsComponentEnemy::~PhysicsComponentEnemy()
{
}

void PhysicsComponentEnemy::Update(GameObject& object, int16_t ms)
{
	if (playerCollision_)
	{
		object.Kill();
	}

	object.SetOnGround(groundCollision_);
	groundCollision_ = false;
}

void PhysicsComponentEnemy::collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody)
{
	if (!otherBody.InSameIgnoreGroup(*body_) && otherBody.GetPosition().y * otherBody.GetPhysicScale() > body_->GetPosition().y * body_->GetPhysicScale())
	{
		groundCollision_ = true;
	}
	if (thisBody.GetCustomId() == "Enemy" && (otherBody.GetCustomId() == "Bob" || otherBody.GetCustomId() == "Eve"))
	{
		playerCollision_ = true;
	}
}