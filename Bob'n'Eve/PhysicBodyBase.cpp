#include "PhysicBodyBase.h"
#include "PhysicBodyDef.h"

bool PhysicBodyBase::IsColliding(const PhysicBodyBase& otherBody) const
{
	if (InSameIgnoreGroup(otherBody))
		return false;
	if (IsCollidingX(otherBody) && IsCollidingY(otherBody))
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
	position_(def.position_), halfSize_(def.halfSize_), physicScale_(1.f)
{
	collisionIgnorGroups_.push_back(def.collisionIgnorGroup_);
}


PhysicBodyBase::~PhysicBodyBase()
{
}

bool PhysicBodyBase::IsCollidingX(const PhysicBodyBase& otherBody) const
{
	float distance = position_.x - otherBody.position_.x;
	if (distance < 0)
		distance *= -1;

	if (distance < (halfSize_.x + otherBody.halfSize_.x))
		return true;
	return false;
}

bool PhysicBodyBase::IsCollidingY(const PhysicBodyBase& otherBody) const
{
	float distance = position_.y - otherBody.position_.y;
	if (distance < 0)
		distance *= -1;

	if (distance < (halfSize_.y + otherBody.halfSize_.y))
		return true;
	return false;
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