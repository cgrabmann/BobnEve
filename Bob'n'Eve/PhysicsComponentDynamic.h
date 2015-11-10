#pragma once
#include "PhysicsComponentBase.h"

class PhysicsComponentDynamic : public PhysicsComponentBase
{
public:
	explicit PhysicsComponentDynamic(const Vector2f& position);
	~PhysicsComponentDynamic();
};

