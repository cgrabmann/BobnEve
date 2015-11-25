#pragma once
#include "PhysicsComponentBase.h"

class PhysicsComponentStatic : public PhysicsComponentBase
{
public:
	explicit PhysicsComponentStatic(const PhysicBodyDef& bodyDef);
	~PhysicsComponentStatic();
};

