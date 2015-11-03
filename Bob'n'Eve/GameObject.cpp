#include "GameObject.h"


GameObject::GameObject(InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics) : position_(100, 750), physicsBody_(nullptr), orientation_(1.f, 1.f), layer_(1.f), input_(input), physics_(physics), graphics_(graphics)
{

}

GameObject::GameObject(b2Body* physicsBody, b2Vec2 orientation, InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics) : position_(100, 100), physicsBody_(physicsBody), orientation_(orientation), layer_(1.f), input_(input), physics_(physics), graphics_(graphics)
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

Vector2f GameObject::GetPosition() const
{
	return position_;

	//TODO: use box2d
	return physicsBody_->GetPosition();
}

b2Body* GameObject::GetPhysicsBody() const
{
	return physicsBody_;
}

Vector2f GameObject::GetOrientation() const
{
	return orientation_;
}

void GameObject::SetOrientation(Vector2f const vec)
{
	orientation_ = vec.ToBox2D();
}

void GameObject::SetOrientation(float x, float y)
{
	if (x != 0)
	{
		orientation_.x = x;
	}

	if (y != 0)
	{
		orientation_.y = y;
	}
}