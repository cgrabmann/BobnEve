#include "PhysicBodyDynamic.h"

void PhysicBodyDynamic::SetVelocity(const Vector2f& velocity)
{
	velocity_ = velocity;
}

void PhysicBodyDynamic::SetPhysicScale(float scale)
{
	physicScale_ = scale;
}

PhysicBodyDynamic::PhysicBodyDynamic(const PhysicBodyDef& def) : PhysicBodyBase(def)
{
}

PhysicBodyDynamic::~PhysicBodyDynamic()
{
}

void PhysicBodyDynamic::Move(const Vector2f& gravity, int32_t ms)
{
	position_.x += velocity_.x * ms;
	position_.y += velocity_.y * ms;

	position_.x += gravity.x * ms * mass_;
	position_.y += gravity.y * ms * mass_ * physicScale_;
}