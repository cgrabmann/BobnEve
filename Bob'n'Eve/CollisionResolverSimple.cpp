#include "CollisionResolverSimple.h"


CollisionResolverSimple::CollisionResolverSimple()
{
}


CollisionResolverSimple::~CollisionResolverSimple()
{
}

float CollisionResolverSimple::SolveValue(PhysicBodyBase& body1, PhysicBodyBase& body2) const
{
	return 0.0f;
}

void CollisionResolverSimple::Resolve(PhysicBodyBase& body1, PhysicBodyBase& body2) const
{
}
