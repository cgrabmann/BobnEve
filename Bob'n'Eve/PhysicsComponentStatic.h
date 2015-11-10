#pragma once
#include "PhysicsComponentBase.h"

class PhysicsComponentStatic : public PhysicsComponentBase
{
public:
	explicit PhysicsComponentStatic(const Vector2f& position);
	~PhysicsComponentStatic();
};

