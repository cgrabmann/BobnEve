#include "GraphicsComponent.h"
#include <SFML/include/SFML/Graphics/CircleShape.hpp>
#include "Renderer.h"
#include "GameObject.h"


GraphicsComponent::GraphicsComponent(sf::Color renderColor) : renderColor_(renderColor)
{
}


GraphicsComponent::~GraphicsComponent()
{
}

void GraphicsComponent::Update(GameObject& object, int16_t ms)
{
	
}

void GraphicsComponent::Draw(const GameObject& object, Renderer& renderer) const
{
	//DEBUG
	sf::CircleShape shape(100.f); //testobject
	shape.setFillColor(renderColor_);
	shape.setPosition(object.GetPosition());
	renderer.GetWindow().draw(shape);
}


