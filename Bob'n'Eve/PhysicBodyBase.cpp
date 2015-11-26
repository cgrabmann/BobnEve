#include "PhysicBodyBase.h"
#include "PhysicBodyDef.h"
#include <cstdint>

bool PhysicBodyBase::IsColliding(const PhysicBodyBase& otherBody) const
{
	if (InSameIgnoreGroup(otherBody))
		return false;
	if (bounds_.IsInsersecting(otherBody.bounds_))
		return true;
	return false;
}

void PhysicBodyBase::AddCollisionIgnoreGroup(int8_t group)
{
	collisionIgnorGroups_.push_back(group);
}

void PhysicBodyBase::RemoveCollisionIgnoreGroup(int8_t group)
{
	std::vector<int8_t>::iterator it = std::find(collisionIgnorGroups_.begin(), collisionIgnorGroups_.end(), group);
	if (it != collisionIgnorGroups_.end())
		collisionIgnorGroups_.erase(it);
}

bool PhysicBodyBase::IsInGroup(int8_t group) const
{
	std::vector<int8_t>::const_iterator it = std::find(collisionIgnorGroups_.begin(), collisionIgnorGroups_.end(), group);
	if (it != collisionIgnorGroups_.end())
		return true;
	return false;
}

void PhysicBodyBase::SetPhysicScale(float scale)
{
	physicScale_ = scale;
}

PhysicBodyBase::PhysicBodyBase(const PhysicBodyDef& def) : velocity_(0.f, 0.f), realVelocity_(0.f, 0.f),
	bounds_(def.bounds), physicScale_(def.gravityScale_)
{
	collisionIgnorGroups_ = def.collisionIgnorGroups_;
}


PhysicBodyBase::~PhysicBodyBase()
{
}

bool PhysicBodyBase::InSameIgnoreGroup(const PhysicBodyBase& otherBody) const
{
	for (int i = 0; i < collisionIgnorGroups_.size(); i++)
	{
		if (otherBody.IsInGroup(collisionIgnorGroups_[i]))
			return true;
	}
	return false;
}