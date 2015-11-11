#include "GameObject.h"
#include "PhysicsComponent.h"
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "Global.h"


GameObject::GameObject(InputComponent* input, PhysicsComponent* physics, GraphicsComponent* graphics) : layer_(1.f), input_(input), physics_(physics), graphics_(graphics)
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

Vector2f GameObject::GetPosition() const
{
	return physics_->GetPosition();
}

Vector2f GameObject::GetRenderPosition() const
{
	return (physics_->GetPosition() * Vector2f(Global::TileWidth, Global::TileHeight));
}

Vector2f GameObject::GetOrientation() const
{
	return physics_->GetOrientation();
}

Vector2f GameObject::GetVelocity() const
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