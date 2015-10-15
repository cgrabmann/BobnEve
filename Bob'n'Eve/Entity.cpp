#include "Entity.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"


Entity::Entity(float layer, int8_t id, Entity::TypeEnum type)
	: layer_(layer), id_(id), type_(type)
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

void Entity::Update(int ms)
{
}

int8_t Entity::GetId() const
{
	return id_;
}

void Entity::GetType(Entity::TypeEnum*& type)
{
	type = &this->type_;
}