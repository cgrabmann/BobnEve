#pragma once

#include <Box2D/Dynamics/b2World.h>

class Entity;

class PhysicManager
{
public:
	PhysicManager(float gravityX, float gravityY);
	virtual ~PhysicManager();

	void RegisterEntity(Entity& entity, b2BodyDef* bodyDef);
private:
	b2World world_;
};

