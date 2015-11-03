#pragma once
#include <cinttypes>

class b2Body;
class GameObject;

class PhysicsComponentBase
{
	friend class PhysicManager;
public:
	PhysicsComponentBase();
	~PhysicsComponentBase();

	void Update(GameObject& object, int16_t ms);

protected:

	b2Body* body_;
	void setPhysicBody(b2Body* body);
};

