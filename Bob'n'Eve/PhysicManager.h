#pragma once

#include <Box2D/Dynamics/b2World.h>

class Entity;

class PhysicManager
{
public:
	PhysicManager(b2Vec2& gravity);
	virtual ~PhysicManager();

	void RegisterEntity(Entity& entity, b2BodyDef* bodyDef);
private:
	b2World world_;
};

