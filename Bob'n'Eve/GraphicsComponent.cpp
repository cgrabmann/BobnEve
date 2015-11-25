#pragma once
#include "GraphicsComponent.h"
#include "Renderer.h"
#include "GameObject.h"
#include <SFML/include/SFML/Graphics/Sprite.hpp>


GraphicsComponent::GraphicsComponent() : GraphicsComponent(nullptr, true)
{
}

GraphicsComponent::GraphicsComponent(sf::Sprite* sprite, bool running) : sprite_(sprite), isRunning_(running), isVisible_(true)
{
}

GraphicsComponent::~GraphicsComponent()
{
	delete sprite_;
}

void GraphicsComponent::Update(GameObject& object, int16_t ms)
{
}

void GraphicsComponent::Draw(const GameObject& object, Renderer& renderer)
{
	if (!sprite_ || !isVisible_)
		return;

	UpdateSprite(object, renderer, *sprite_);

	renderer.GetTarget().draw(*sprite_);
}

void GraphicsComponent::UpdateSprite(const GameObject& object, const Renderer& renderer, sf::Sprite& sprite)
{
	//Global scale
	sprite.setScale(renderer.GetScale().ToSFML());
	//Mirror with scale of -1
	sprite.scale(object.GetOrientation().ToSFML());
	//set position in view
	sprite.setPosition((object.GetRenderPosition() * renderer.GetScale()).ToSFML());
}
