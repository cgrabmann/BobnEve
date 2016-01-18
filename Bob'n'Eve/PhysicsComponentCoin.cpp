#include "PhysicsComponentCoin.h"
#include "PhysicBodyDef.h"
#include "GameObject.h"

PhysicsComponentCoin::PhysicsComponentCoin(PhysicBodyDef& bodyDef) : PhysicsComponentBase(bodyDef.SetCallback(this)), playerCollision_(false)
{
}

PhysicsComponentCoin::~PhysicsComponentCoin()
{
}

void PhysicsComponentCoin::Update(GameObject& object, int16_t ms)
{
	if (playerCollision_)
	{
		object.Kill();
	}
}

void PhysicsComponentCoin::collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody)
{
	if (otherBody.GetCustomId() == "Bob" || otherBody.GetCustomId() == "Eve")
	{
		playerCollision_ = true;
	}
}