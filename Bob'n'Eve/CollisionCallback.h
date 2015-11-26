#pragma once
class PhysicBodyBase;

class CollisionCallback
{
public:
	CollisionCallback() {}
	virtual ~CollisionCallback() {};

	virtual void collidesWith(PhysicBodyBase& otherBody) = 0;
};

