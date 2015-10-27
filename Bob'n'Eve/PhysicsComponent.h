#pragma once
#include <cinttypes>

class GameObject;

class PhysicsComponent
{
public:
	PhysicsComponent();
	~PhysicsComponent();

	void Update(GameObject& object, int16_t ms);
};

