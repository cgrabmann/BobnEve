#pragma once
#include "PhysicBodyBase.h"
class PhysicBodyDynamic :
	public PhysicBodyBase
{
	friend class PhysicWorld;
public:
	void SetVelocity(const Vector2f& velocity) override;
	void SetPhysicScale(float scale) override;
	inline virtual void CollideWith(PhysicBodyBase& otherBody) override
	{
		otherBody.CollideWithDynamic(*this);
	};
	virtual void CollideWithStatic(PhysicBodyStatic& otherBody) override;
	virtual void CollideWithDynamic(PhysicBodyDynamic& otherBody) override;

protected:
	explicit PhysicBodyDynamic(const PhysicBodyDef& def);
	~PhysicBodyDynamic();

	virtual void Move(const Vector2f& gravity, int32_t ms) override;
};

