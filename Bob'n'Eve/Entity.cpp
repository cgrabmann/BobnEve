#include "Entity.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"


Entity::Entity(float layer, int32_t id)
	: layer_(layer), id_(id)
{
}

Entity::~Entity()
{
	
}

void Entity::Draw(Renderer& renderer)
{
	sf::CircleShape shape(100.f); //testobject
	shape.setFillColor(sf::Color::Green);
	renderer.Draw(shape);
}

void Entity::Update(int16_t ms)
{
}

int32_t Entity::GetId() const
{
	return id_;
}

void Entity::setPhysicBody(b2Body* body)
{
	body_ = body;
}