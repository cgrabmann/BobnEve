#include "PhysicsComponentBase.h"
#include "GameObject.h"
#include "Global.h"


PhysicsComponentBase::PhysicsComponentBase(Vector2f* position) : body_(nullptr), position_(position), velocity_(new Vector2f(0.f, 0.f))
{
}

PhysicsComponentBase::PhysicsComponentBase(float x, float y) : body_(nullptr), position_(new Vector2f(x, y)), velocity_(new Vector2f(0.f, 0.f))
{
}

PhysicsComponentBase::~PhysicsComponentBase()
{
	delete position_;
	delete velocity_;
}

void PhysicsComponentBase::Update(GameObject& object, int16_t ms)
{
	
}

const Vector2f& PhysicsComponentBase::GetPosition() const
{
	return *position_;
}

const Vector2f& PhysicsComponentBase::GetVelocity() const
{
	return *velocity_;
}

Vector2f PhysicsComponentBase::GetOrientation() const
{
	if (position_->y > Global::ScreenHeight / 2)
	{
		return Vector2f(1.f, -1.f);
	}
	return Vector2f(1.f, 1.f);
}

void PhysicsComponentBase::SetVelocity(const Vector2f& velocity)
{
	velocity_->x = velocity.x;
	velocity_->y = velocity.y;
}

void PhysicsComponentBase::SetVelocity(float velX, float velY)
{
	velocity_->x = velX;
	velocity_->y = velY;
}

void PhysicsComponentBase::setPhysicBody(b2Body* body)
{
	body_ = body;
}
