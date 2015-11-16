#pragma once
class PhysicBodyBase;

class CollisionResolver
{
public:
	CollisionResolver();
	virtual ~CollisionResolver();

	virtual float SolveValue(PhysicBodyBase& body1, PhysicBodyBase& body2) const = 0;
	virtual void Resolve(PhysicBodyBase& body1, PhysicBodyBase& body2) const = 0;
};

