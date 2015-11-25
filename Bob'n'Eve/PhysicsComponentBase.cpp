#include "PhysicsComponentBase.h"
#include "GameObject.h"
#include "PhysicManager.h"
#include "PhysicBodyBase.h"


PhysicsComponentBase::PhysicsComponentBase(const PhysicBodyDef& bodyDef) : body_(PhysicManager::Instance()->CreateBody(bodyDef))
{
}

PhysicsComponentBase::~PhysicsComponentBase()
{
	PhysicManager::Instance()->DestroyBody(*body_);
}

void PhysicsComponentBase::Update(GameObject& object, int16_t ms)
{
}

Vector2f PhysicsComponentBase::GetOrientation() const
{
	Vector2f velocity = GetVelocity();
	Vector2f orientation(1,1);

	if (velocity.x > 0)
	{
		orientation.x = 1.0f;
	}
	if (velocity.x < 0)
	{
		orientation.x = -1.0f;
	}
	return orientation;
}

void PhysicsComponentBase::SetVelocity(const Vector2f& velocity)
{
	SetVelocity(velocity.x, velocity.y);
}

void PhysicsComponentBase::SetVelocity(float velX, float velY)
{
	body_->SetVelocity(Vector2f(velX, velY));
}
