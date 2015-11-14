#include "PhysicBodyBase.h"
#include "PhysicBodyDef.h"
#include "CollisionResolver.h"
#include "CollisionResolverSimple.h"


const Vector2f& PhysicBodyBase::GetPosition() const
{
	return position_;
}

const Vector2f& PhysicBodyBase::GetVelocity() const
{
	return velocity_;
}

bool PhysicBodyBase::IsColliding(const PhysicBodyBase& otherBody) const
{
	Vector2f distance = position_ - otherBody.position_;
	if (distance.x < 0)
		distance.x *= -1;
	if (distance.y < 0)
		distance.y *= -1;

	if (distance.x <= (halfSize_.x + otherBody.halfSize_.x)
		&& distance.y <= (halfSize_.y + otherBody.halfSize_.y))
		return true;
	return false;
}

void PhysicBodyBase::SetPhysicScale(float scale)
{
	physicScale_ = scale;
}

PhysicBodyBase::PhysicBodyBase(const PhysicBodyDef& def) : position_(def.position_),
velocity_(0.f, 0.f), halfSize_(def.halfSize_), mass_(def.mass_), physicScale_(1.f), resolver_((def.resolver_ == nullptr) ? new CollisionResolverSimple() : def.resolver_)
{
}


PhysicBodyBase::~PhysicBodyBase()
{
}

void PhysicBodyBase::ResolveCollision(PhysicBodyBase& otherBody)
{
	resolver_->Resolve(*this, otherBody);
}