#include "GameObject.h"
#include "PhysicsComponentBase.h"
#include "GraphicsComponentBase.h"
#include "InputComponentBase.h"


GameObject::GameObject(InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics) : layer_(1.f), input_(input), physics_(physics), graphics_(graphics)
{

}

GameObject::~GameObject()
{

}

void GameObject::Update(int16_t ms)
{
	input_->Update(*this, ms);
	physics_->Update(*this, ms);
	graphics_->Update(*this, ms);
}

void GameObject::Draw(Renderer& renderer) const
{
	graphics_->Draw(*this, renderer);
}

float GameObject::GetLayer() const
{
	return layer_;
}

const Vector2f& GameObject::GetPosition() const
{
	return physics_->GetPosition();
}

Vector2f GameObject::GetOrientation() const
{
	return physics_->GetOrientation();
}

const Vector2f& GameObject::GetVelocity() const
{
	return physics_->GetVelocity();
}

void GameObject::SetVelocity(Vector2f const & vec)
{
	physics_->SetVelocity(vec);
}

void GameObject::SetVelocity(float x, float y)
{
	physics_->SetVelocity(x, y);
}