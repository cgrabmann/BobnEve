#pragma once
#include "PhysicBodyBase.h"
class PhysicBodyDynamic :
	public PhysicBodyBase
{
	friend class PhysicWorld;
public:
	void SetVelocity(const Vector2f& velocity) override;
	void SetPhysicScale(float scale) override;

protected:
	explicit PhysicBodyDynamic(const PhysicBodyDef& def);
	~PhysicBodyDynamic();

	void Move(const Vector2f& gravity, int32_t ms) override;
};

