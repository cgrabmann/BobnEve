#include "PhysicBodyBase.h"
#include "PhysicBodyDef.h"
#include "CollisionCallback.h"

bool PhysicBodyBase::IsColliding(const PhysicBodyBase& otherBody) const
{
	return bounds_.IsInsersecting(otherBody.bounds_);
}

void PhysicBodyBase::FinishCollision(PhysicBodyBase& otherBody)
{
	if (callback_ != nullptr)
		callback_->collidesWith(otherBody);
}

void PhysicBodyBase::AddCollisionIgnoreGroup(int8_t group)
{
	collisionIgnoreGroups_.push_back(group);
}

void PhysicBodyBase::RemoveCollisionIgnoreGroup(int8_t group)
{
	std::vector<int8_t>::iterator it = std::find(collisionIgnoreGroups_.begin(), collisionIgnoreGroups_.end(), group);
	if (it != collisionIgnoreGroups_.end())
		collisionIgnoreGroups_.erase(it);
}

bool PhysicBodyBase::IsInGroup(int8_t group) const
{
	std::vector<int8_t>::const_iterator it = std::find(collisionIgnoreGroups_.begin(), collisionIgnoreGroups_.end(), group);

	return it != collisionIgnoreGroups_.end();
}

void PhysicBodyBase::SetPhysicScale(float scale)
{
	physicScale_ = scale;
}

PhysicBodyBase::PhysicBodyBase(const PhysicBodyDef& def) : customId_(def.customId_), velocity_(0.f, 0.f), realVelocity_(0.f, 0.f),
	bounds_(def.bounds_), physicScale_(def.gravityScale_), callback_(def.callback_)
{
	collisionIgnoreGroups_ = def.collisionIgnoreGroups_;
	collisionSides_ = def.collisionSides_;
}


PhysicBodyBase::~PhysicBodyBase()
{
	delete[] collisionSides_;
}

bool PhysicBodyBase::InSameIgnoreGroup(const PhysicBodyBase& otherBody) const
{
	for (int i = 0; i < collisionIgnoreGroups_.size(); i++)
	{
		if (otherBody.IsInGroup(collisionIgnoreGroups_[i]))
			return true;
	}
	return false;
}