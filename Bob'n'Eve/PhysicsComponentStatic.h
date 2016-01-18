#pragma once
#include "PhysicsComponentBase.h"

class PhysicsComponentStatic : public PhysicsComponentBase
{
public:
	explicit PhysicsComponentStatic(const PhysicBodyDef& bodyDef);
	~PhysicsComponentStatic();

	virtual inline Vector2f GetVelocity() const override
	{
		return Vector2f(0, 0);
	}
	virtual Vector2f GetOrientation() const override
	{
		return Vector2f(1, 1);
	}

	virtual void SetVelocity(const Vector2f& velocity) override
	{	}
	virtual void SetVelocity(float velX, float velY) override
	{	}
};

