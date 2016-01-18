#include "PhysicsComponentEnemy.h"
#include "PhysicBodyDef.h"
#include "GameObject.h"

PhysicsComponentEnemy::PhysicsComponentEnemy(PhysicBodyDef& bodyDef, bool killable) : PhysicsComponentBase(bodyDef.SetCallback(this)), groundCollision_(false), playerCollision_(false),
	killable_(killable)
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
	if (otherBody.GetCustomId() == "Platform" && otherBody.GetPosition().y * otherBody.GetPhysicScale() > body_->GetPosition().y * body_->GetPhysicScale())
	{
		groundCollision_ = true;
	}
	if (killable_ && (otherBody.GetCustomId() == "Bob" || otherBody.GetCustomId() == "Eve"))
	{
		playerCollision_ = true;
	}
}