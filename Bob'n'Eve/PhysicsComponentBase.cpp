#include "PhysicsComponentBase.h"
#include "GameObject.h"
#include "Global.h"
#include "PhysicManager.h"


PhysicsComponentBase::PhysicsComponentBase(b2BodyDef& bodyDef, const b2FixtureDef& fixtureDef)
{
	body_ = PhysicManager::Instance()->CreateBody(&bodyDef);
	body_->CreateFixture(&fixtureDef);
	body_->SetFixedRotation(true);
}

PhysicsComponentBase::~PhysicsComponentBase()
{
	PhysicManager::Instance()->DestroyBody(body_);
}

void PhysicsComponentBase::Update(GameObject& object, int16_t ms)
{
	b2Vec2 velocity = body_->GetLinearVelocity();

	if (velocity.x < 0)
		velocity.x += 0.01f * ms;
	if (velocity.x > 0)
		velocity.x -= 0.01f * ms;
	if (velocity.x >= -0.1f && velocity.x <= 0.1f)
		velocity.x = 0.f;

	body_->SetLinearVelocity(velocity);

		//TODO: remove velocity calculation
	/*if (velocity_->y < 0)
		velocity_->y += 0.1f;
	if (velocity_->y > 0)
		velocity_->y -= 0.1f; 
	if (velocity_->y >= -0.05f && velocity_->y <= 0.05f)
		velocity_->y = 0.f;

	position_->x += velocity_->x;
	position_->y += velocity_->y;*/
}

Vector2f PhysicsComponentBase::GetPosition() const
{
	return Vector2f(body_->GetPosition());
}

Vector2f PhysicsComponentBase::GetVelocity() const
{
	return Vector2f(body_->GetLinearVelocity());
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
	body_->SetLinearVelocity(b2Vec2(velX, velY));
}
