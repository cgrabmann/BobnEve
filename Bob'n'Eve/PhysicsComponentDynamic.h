#pragma once
#include "PhysicsComponentBase.h"

class PhysicsComponentDynamic : public PhysicsComponentBase
{
public:
	explicit PhysicsComponentDynamic(const PhysicBodyDef& bodyDef);
	~PhysicsComponentDynamic();
};

