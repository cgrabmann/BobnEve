#pragma once
class PhysicBodyBase;

class CollisionResolver
{
public:
	CollisionResolver();
	virtual ~CollisionResolver();

	virtual void Resolve(PhysicBodyBase& body1, PhysicBodyBase& body2) = 0;
};

