#pragma once
#include "CollisionResolver.h"

class CollisionResolverSimple : public CollisionResolver
{
public:
	CollisionResolverSimple();
	~CollisionResolverSimple();

	float SolveValue(PhysicBodyBase& body1, PhysicBodyBase& body2) const override;
	void Resolve(PhysicBodyBase& body1, PhysicBodyBase& body2) const override;
};

