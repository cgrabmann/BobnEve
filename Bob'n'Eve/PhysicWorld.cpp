#include "PhysicWorld.h"
#include "PhysicBodyBase.h"
#include "PhysicBodyDef.h"
#include "PhysicBodyStatic.h"
#include "PhysicBodyDynamic.h"


PhysicWorld::PhysicWorld(const Vector2f& gravity) : gravity_(gravity)
{
}


PhysicWorld::~PhysicWorld()
{
	for (std::vector<PhysicBodyBase*>::iterator it = bodies_.begin(); it != bodies_.end(); ++it)
	{
		delete *it;
	}
}

PhysicBodyBase* PhysicWorld::CreateBody(const PhysicBodyDef& def)
{
	PhysicBodyBase* body;

	switch (def.type_)
	{
	case (PhysicBody::Type::STATIC):
		body = new PhysicBodyStatic(def);
	case (PhysicBody::Type::DYNAMIC) :
		body = new PhysicBodyDynamic(def);
	}

	bodies_.push_back(body);

	return body;
}

void PhysicWorld::DestroyBody(PhysicBodyBase& body)
{
	std::vector<PhysicBodyBase*>::iterator it;
	it = std::find(bodies_.begin(), bodies_.end(), &body);
	if (it != bodies_.end())
	{
		bodies_.erase(it);
		delete &body;
	}
}

void PhysicWorld::Reserve(size_t count)
{
	bodies_.reserve(count);
	collisions_.reserve(count / 2);
}