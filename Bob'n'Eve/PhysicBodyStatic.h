#pragma once
#include "PhysicBodyBase.h"
class PhysicBodyStatic :
	public PhysicBodyBase
{
	friend class PhysicWorld;
public:
	void SetVelocity(const Vector2f& velocity) override;
	void SetPhysicScale(float scale) override;

protected:
	explicit PhysicBodyStatic(const PhysicBodyDef& def);
	~PhysicBodyStatic();

	void Move(const Vector2f& gravity, int32_t ms) override;
};

