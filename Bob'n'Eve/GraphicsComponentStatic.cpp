#pragma once
#include "GraphicsComponentStatic.h"
#include "Renderer.h"
#include "GameObject.h"


GraphicsComponentStatic::GraphicsComponentStatic(sf::Sprite* sprite) : GraphicsComponentBase(sprite)
{
}

GraphicsComponentStatic::~GraphicsComponentStatic()
{
}

void GraphicsComponentStatic::Update(GameObject& object, int16_t ms)
{
}

void GraphicsComponentStatic::Draw(const GameObject& object, Renderer& renderer) const
{
	//Global scale
	sprite_->setScale(renderer.GetScale());
	//Mirror with scale of -1
	sprite_->scale(object.GetOrientation().ToSFML());
	//set position in view
	sprite_->setPosition(object.GetPosition().ToSFML());
	//draw
	renderer.GetTarget().draw(*sprite_);
}

