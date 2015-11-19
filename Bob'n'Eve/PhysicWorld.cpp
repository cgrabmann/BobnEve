#include "PhysicWorld.h"
#include "PhysicBodyBase.h"
#include "PhysicBodyDef.h"
#include "PhysicBodyStatic.h"
#include "PhysicBodyDynamic.h"
#include "CollisionResolver.h"


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

void PhysicWorld::Step(int32_t ms)
{
	MoveBodies(ms);
	for (uint32_t i = 0; i < 3; ++i)
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
		break;
	case (PhysicBody::Type::DYNAMIC) :
		body = new PhysicBodyDynamic(def);
		break;
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

void PhysicWorld::MoveBodies(int32_t ms)
{
	for (std::vector<PhysicBodyBase*>::iterator it = bodies_.begin(); it != bodies_.end(); ++it)
	{
		(*it)->Move(gravity_, ms);
	}
}

bool PhysicWorld::CheckCollisions()
{
	bool collision = false;

	for (std::vector<PhysicBodyBase*>::iterator it = bodies_.begin(); it != bodies_.end(); ++it)
	{
		for (std::vector<PhysicBodyBase*>::iterator otherIt = ++it; otherIt != bodies_.end(); ++it)
		{
			if ((*it)->IsColliding(*(*it)))
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
		float resolveValue1 = group->body1_->GetResolver().SolveValue(*(group->body1_), *(group->body2_));
		float resolveValue2 = group->body2_->GetResolver().SolveValue(*(group->body1_), *(group->body2_));

		if (resolveValue1 >= resolveValue2)
		{
			group->body1_->GetResolver().Resolve(*(group->body1_), *(group->body2_));
		}
		else
		{
			group->body2_->GetResolver().Resolve(*(group->body1_), *(group->body2_));
		}
		delete group;
	}
	collisions_.clear();
}