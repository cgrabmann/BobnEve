#include "PhysicsComponentFinish.h"
#include "PhysicBodyDef.h"
#include "GameObject.h"

PhysicsComponentFinish::PhysicsComponentFinish(PhysicBodyDef& bodyDef) : PhysicsComponentBase(bodyDef.SetCallback(this)), playerCollision_(false)
{
}

PhysicsComponentFinish::~PhysicsComponentFinish()
{
}

void PhysicsComponentFinish::Update(GameObject& object, int16_t ms)
{
	if (playerCollision_)
	{
		object.Kill();
	}
}

void PhysicsComponentFinish::collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody)
{
	if (otherBody.GetCustomId() == "Bob" || otherBody.GetCustomId() == "Eve")
	{
		playerCollision_ = true;
	}
}