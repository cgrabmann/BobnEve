#pragma once
#include <cinttypes>

class b2Body;
class GameObject;

class PhysicsComponent
{
	friend class PhysicManager;
public:
	PhysicsComponent();
	~PhysicsComponent();

	void Update(GameObject& object, int16_t ms);

protected:

	b2Body* body_;
	void setPhysicBody(b2Body* body);
};

