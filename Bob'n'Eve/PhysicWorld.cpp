#include "PhysicWorld.h"
#include "PhysicBodyBase.h"
#include "PhysicBodyDef.h"
#include "PhysicBodyStatic.h"
#include "PhysicBodyDynamic.h"


PhysicWorld::PhysicWorld(const Vector2f& gravity) : gravity_(gravity)
{
	staticBodies_.reserve(256);
}


PhysicWorld::~PhysicWorld()
{
	for (std::vector<PhysicBodyBase*>::iterator it = dynamicBodies_.begin(); it != dynamicBodies_.end(); ++it)
	{
		delete *it;
	}
	for (std::vector<PhysicBodyBase*>::iterator it = staticBodies_.begin(); it != staticBodies_.end(); ++it)
	{
		delete *it;
	}
}

void PhysicWorld::Step(float seconds)
{
	MoveBodies(seconds);
	for (size_t j = 0; j < 3; ++j)
	{
		if (!CheckCollisions())
			break;
		ResolveCollisions();
	}
}

PhysicBodyBase* PhysicWorld::CreateBody(const PhysicBodyDef& def)
{
	PhysicBodyBase* body;

	switch (def.type_)
	{
	case (PhysicBody::Type::STATIC) :
		body = new PhysicBodyStatic(def);
		staticBodies_.push_back(body);
		break;
	case (PhysicBody::Type::DYNAMIC) :
	default:
		body = new PhysicBodyDynamic(def);
		dynamicBodies_.push_back(body);
		break;
	}

	return body;
}

void PhysicWorld::DestroyBody(PhysicBodyBase& body)
{
	std::vector<PhysicBodyBase*>::iterator it;
	it = std::find(dynamicBodies_.begin(), dynamicBodies_.end(), &body);
	if (it != dynamicBodies_.end())
	{
		dynamicBodies_.erase(it);
		delete &body;
		return;
	}

	it = std::find(staticBodies_.begin(), staticBodies_.end(), &body);
	if (it != staticBodies_.end())
	{
		staticBodies_.erase(it);
		delete &body;
	}
}

void PhysicWorld::Reserve(size_t count)
{
	staticBodies_.reserve(count);
	collisions_.reserve(count / 2);
}

void PhysicWorld::SetGravity(const Vector2f& gravity)
{
	gravity_ = gravity;
}

void PhysicWorld::MoveBodies(float seconds)
{
	for (std::vector<PhysicBodyBase*>::iterator it = dynamicBodies_.begin(); it != dynamicBodies_.end(); ++it)
	{
		(*it)->Move(gravity_, seconds);
	}
}

bool PhysicWorld::CheckCollisions()
{
	bool collision = false;

	for (std::vector<PhysicBodyBase*>::iterator it = dynamicBodies_.begin(); it != dynamicBodies_.end(); ++it)
	{
		for (std::vector<PhysicBodyBase*>::iterator otherIt = it + 1; otherIt != dynamicBodies_.end(); ++otherIt)
		{
			if ((*it)->IsColliding(*(*otherIt)))
			{
				collision = true;
				collisions_.push_back(new CollidingGroup((*it), (*otherIt)));
			}
		}
		for (std::vector<PhysicBodyBase*>::iterator otherIt = staticBodies_.begin(); otherIt != staticBodies_.end(); ++otherIt)
		{
			if ((*it)->IsColliding(*(*otherIt)))
			{
				collision = true;
				collisions_.push_back(new CollidingGroup((*it), (*otherIt)));
			}
		}
	}

	return collision;
}

void PhysicWorld::ResolveCollisions()
{
	size_t count = collisions_.size();
	for (size_t i = 0; i < count; ++i)
	{
		CollidingGroup* group = collisions_.at(i);
		group->body1_->CollideWith(*group->body2_);
		group->body1_->FinishCollision(*group->body2_);
		group->body2_->FinishCollision(*group->body1_);
		delete group;
	}
	collisions_.clear();
}