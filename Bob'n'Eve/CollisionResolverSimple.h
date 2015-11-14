#pragma once
#include "CollisionResolver.h"

class CollisionResolverSimple : public CollisionResolver
{
public:
	CollisionResolverSimple();
	~CollisionResolverSimple();

	void Resolve(PhysicBodyBase& body1, PhysicBodyBase& body2) override;
};

