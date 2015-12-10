#include "GameObject.h"
#include "PhysicsComponentBase.h"
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "Global.h"


GameObject::GameObject(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics, Vector2f speed) : layer_(1.f), onGround_(false),
	kill_(false), speed_(speed), input_(input), physics_(physics), graphics_(graphics)
{

}

GameObject::~GameObject()
{
	delete input_;
	delete physics_;
	delete graphics_;
}

void GameObject::Update(int16_t ms)
{
	if (input_)
		input_->Update(*this, ms);
	if (physics_)
		physics_->Update(*this, ms);
	if (graphics_)
		graphics_->Update(*this, ms);
}

void GameObject::Draw(Renderer& renderer) const
{
	if (graphics_)
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
	return (physics_->GetPosition());// *Vector2f(Global::TileWidth, Global::TileHeight));
}

Vector2f GameObject::GetOrientation() const
{
	return physics_->GetOrientation();
}

bool GameObject::IsOnGround() const
{
	return onGround_;
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

void GameObject::SetOnGround(bool onGround)
{
	onGround_ = onGround;
}

void GameObject::Left()
{
	const Vector2f& velocity = GetVelocity();
	SetVelocity(-speed_.x, velocity.y);
}

void GameObject::Right()
{
	const Vector2f& velocity = GetVelocity();
	SetVelocity(speed_.x, velocity.y);
}

void GameObject::Up()
{
	if (IsOnGround()){
		const Vector2f& velocity = GetVelocity();
		SetVelocity(velocity.x, -speed_.y);
	}
}

void GameObject::Kill()
{
}
