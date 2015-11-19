#pragma once
#include "GraphicsComponent.h"
#include "Renderer.h"
#include "GameObject.h"
#include <SFML/include/SFML/Graphics/Sprite.hpp>


GraphicsComponent::GraphicsComponent(bool running) : sprite_(), isRunning_(running)
{
}

GraphicsComponent::GraphicsComponent(sf::Sprite* sprite, bool running) : sprite_(sprite), isRunning_(running)
{
}

GraphicsComponent::~GraphicsComponent()
{
}

void GraphicsComponent::Update(GameObject& object, int16_t ms)
{
}

void GraphicsComponent::Draw(const GameObject& object, Renderer& renderer)
{
	UpdateSprite(object, renderer, *sprite_);

	renderer.GetTarget().draw(*sprite_);
}

void GraphicsComponent::UpdateSprite(const GameObject& object, Renderer& renderer, sf::Sprite& sprite)
{
	//Global scale
	sprite.setScale(renderer.GetScale());
	//Mirror with scale of -1
	sprite.scale(object.GetOrientation().ToSFML());
	//set position in view
	sprite.setPosition(object.GetRenderPosition().ToSFML());
}
