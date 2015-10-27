#include "GameObject.h"


GameObject::GameObject() : position_(100, 100), layer_(1.f)
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