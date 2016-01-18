#pragma once
#include "UpdateableCollisionCallback.h"
#include <unordered_map>
#include "FloatRect.h"

class PassThroughCollisionCallback :
	public UpdateableCollisionCallback
{
public:
	PassThroughCollisionCallback();
	virtual ~PassThroughCollisionCallback();

	virtual void collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody) override;
	virtual void update(GameObject& object, int16_t ms) override;

	struct GravitySwitchInfo
	{
		int16_t ms = 0;
		bool switched = false;
		FloatRect switchBounds;
	};

private:
	std::unordered_map<PhysicBodyBase*, GravitySwitchInfo> dynamics_;
};

