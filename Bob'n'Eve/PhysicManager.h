#pragma once

#include <Box2D/Dynamics/b2World.h>

class PhysicsComponent;

class PhysicManager
{
public:
	PhysicManager(float gravityX, float gravityY);
	virtual ~PhysicManager();

	void createBody(PhysicsComponent& gameObject, b2BodyDef* bodyDef);
private:
	b2World world_;
};

