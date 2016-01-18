#pragma once
#include "CollisionCallback.h"
#include <cinttypes>

class GameObject;

class UpdateableCollisionCallback
	: public CollisionCallback
{
public:
	explicit UpdateableCollisionCallback()
		: ownedBy(0)
	{
	}

	virtual void collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody) override = 0;
	virtual void update(GameObject& object, int16_t ms) = 0;

	void add()
	{
		ownedBy++;
	}

	void remove()
	{
		ownedBy--;
		if (ownedBy <= 0)
		{
			delete this;
		}
	}

private:
	uint32_t ownedBy;
};