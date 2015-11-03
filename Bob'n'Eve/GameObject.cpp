#include "GameObject.h"


GameObject::GameObject(InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics) : position_(100, 100), physicsBody_(nullptr), velocity_(new b2Velocity()), orientation_(new b2Vec2(1.f,1.f)), layer_(1.f), input_(input), physics_(physics), graphics_(graphics)
{

}

GameObject::GameObject(b2Body* physicsBody, b2Vec2* orientation, InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics) : position_(100, 100), physicsBody_(physicsBody), velocity_(new b2Velocity()), orientation_(orientation), layer_(1.f), input_(input), physics_(physics), graphics_(graphics)
{

}

GameObject::~GameObject()
{

}

void GameObject::Update(int16_t ms)
{}

void GameObject::Draw(Renderer& renderer) const
{}

float GameObject::GetLayer() const
{
	return layer_;
}

sf::Vector2f GameObject::GetPosition() const
{
	return position_;
}

b2Body* GameObject::GetPhysicsBody() const
{
	return physicsBody_;
}

b2Velocity* GameObject::GetVelocity() const
{
	return velocity_;
}

b2Vec2* GameObject::GetOrientation() const
{
	return orientation_;
}