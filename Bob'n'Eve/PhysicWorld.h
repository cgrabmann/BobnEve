#pragma once
#include <cinttypes>
#include <vector>
#include "Vector2f.h"

struct PhysicBodyDef;
class PhysicBodyBase;

class PhysicWorld
{
public:
	explicit PhysicWorld(const Vector2f& gravity);
	~PhysicWorld();

	void Step(float seconds);
	PhysicBodyBase* CreateBody(const PhysicBodyDef& def);
	void DestroyBody(PhysicBodyBase& body);

	void Reserve(size_t count);

	class CollidingGroup
	{
	public:
		CollidingGroup(PhysicBodyBase* body1, PhysicBodyBase* body2) : body1_(body1), body2_(body2){}

		PhysicBodyBase* body1_;
		PhysicBodyBase* body2_;
	};

private:
	std::vector<PhysicBodyBase*> bodies_;
	std::vector<CollidingGroup*> collisions_;
	Vector2f gravity_;

	void MoveBodies(float seconds);
	bool CheckCollisions();
	void ResolveCollisions();
};

