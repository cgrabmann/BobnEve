#include "PhysicsComponent.h"
#include "GameObject.h"
#include "Global.h"
#include "PhysicManager.h"


PhysicsComponent::PhysicsComponent(const Vector2f& position, bool dynamic)
{
	b2BodyDef bodyDef;
	if (dynamic)
	{
		bodyDef.type = b2_dynamicBody;
	}
	else
	{
		bodyDef.type = b2_staticBody;
	}
	bodyDef.position.Set(position.x, position.y);
	body_ = PhysicManager::Instance()->CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(0.5f, 0.5f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	if (dynamic)
	{
		fixtureDef.density = 1.f;
		fixtureDef.friction = 0;
	}
	else
	{
		fixtureDef.density = 0.f;
		fixtureDef.friction = 0;
	}

	body_->CreateFixture(&fixtureDef);
	body_->SetFixedRotation(true);
}

PhysicsComponent::~PhysicsComponent()
{
	PhysicManager::Instance()->DestroyBody(body_);
}

void PhysicsComponent::Update(GameObject& object, int16_t ms)
{
	b2Vec2 velocity = body_->GetLinearVelocity();

	//friction
	if (velocity.x < 0)
		velocity.x += 0.2f;
	if (velocity.x > 0)
		velocity.x -= 0.2f;
	if (velocity.x >= -0.05f && velocity.x <= 0.05f)
		velocity.x = 0.f;

	body_->SetLinearVelocity(velocity);

	//TODO: remove velocity calculation
	/*if (velocity_->y < 0)
		velocity_->y += 0.1f;
		if (velocity_->y > 0)
		velocity_->y -= 0.1f;
		if (velocity_->y >= -0.05f && velocity_->y <= 0.05f)
		velocity_->y = 0.f;

		position_->y += velocity_->y;*/
}

Vector2f PhysicsComponent::GetPosition() const
{
	return Vector2f(body_->GetPosition());
}

Vector2f PhysicsComponent::GetVelocity() const
{
	return Vector2f(body_->GetLinearVelocity());
}

Vector2f PhysicsComponent::GetOrientation() const
{
	if (GetPosition().y > Global::ScreenHeight / 2)
	{
		return Vector2f(1.f, -1.f);
	}
	return Vector2f(1.f, 1.f);
}

void PhysicsComponent::SetVelocity(const Vector2f& velocity)
{
	body_->SetLinearVelocity(velocity.ToBox2D());
}

void PhysicsComponent::SetVelocity(float velX, float velY)
{
	body_->SetLinearVelocity(b2Vec2(velX, velY));
}
