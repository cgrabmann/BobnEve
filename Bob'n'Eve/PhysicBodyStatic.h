#pragma once
#include "PhysicBodyBase.h"
#include "PhysicBodyDynamic.h"

class PhysicBodyStatic :
	public PhysicBodyBase
{
	friend class PhysicWorld;
public:
	inline void SetVelocity(const Vector2f& velocity) override {};
	inline void SetPhysicScale(float scale) override {};
	inline virtual void CollideWith(PhysicBodyBase& otherBody) override
	{
		otherBody.CollideWithStatic(*this);
	};
	inline virtual void CollideWithStatic(PhysicBodyStatic& otherBody) override {};
	inline virtual void CollideWithDynamic(PhysicBodyDynamic& otherBody) override 
	{
		otherBody.CollideWithStatic(*this);
	};

protected:
	explicit PhysicBodyStatic(const PhysicBodyDef& def);
	~PhysicBodyStatic();

	inline void Move(const Vector2f& gravity, int32_t ms) override {};
};

