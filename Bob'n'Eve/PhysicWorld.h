#pragma once
#include <cinttypes>
#include <vector>
#include "Vector2f.h"

struct PhysicBodyDef;
struct CollidingGroup;
class PhysicBodyBase;

class PhysicWorld
{
public:
	explicit PhysicWorld(const Vector2f& gravity);
	~PhysicWorld();

	void Step(int32_t ms);
	PhysicBodyBase* CreateBody(const PhysicBodyDef& def);
	void DestroyBody(PhysicBodyBase& body);

	void Reserve(size_t count);

private:
	std::vector<PhysicBodyBase*> bodies_;
	std::vector<CollidingGroup*> collisions_;
	Vector2f gravity_;

	void MoveBodies();
	void CheckCollisions();
	void ResolveCollisions();

	struct CollidingGroup
	{
		PhysicBodyBase* body1;
		PhysicBodyBase* body2;
	};
};

