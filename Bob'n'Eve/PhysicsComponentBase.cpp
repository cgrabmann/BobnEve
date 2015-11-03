#include <stddef.h>
#include "PhysicsComponentBase.h"
#include "GameObject.h"
#include "Global.h"


PhysicsComponentBase::PhysicsComponentBase() : body_(nullptr)
{
}


PhysicsComponentBase::~PhysicsComponentBase()
{
}

void PhysicsComponentBase::Update(GameObject& object, int16_t ms)
{
	if (object.GetPosition().y > Global::ScreenHeight / 2)
	{
		object.SetOrientation(0, -1.f);
	}
	else
	{
		object.SetOrientation(0, 1.f);
	}
}

void PhysicsComponentBase::setPhysicBody(b2Body* body)
{
	body_ = body;
}
