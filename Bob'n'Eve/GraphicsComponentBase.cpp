#pragma once
#include "GraphicsComponentBase.h"
#include "Renderer.h"
#include "GameObject.h"
#include <SFML/include/SFML/Graphics/Sprite.hpp>


GraphicsComponentBase::GraphicsComponentBase() : sprite_()
{
}

GraphicsComponentBase::GraphicsComponentBase(sf::Sprite* sprite) : sprite_(sprite)
{
}

GraphicsComponentBase::~GraphicsComponentBase()
{
}

void GraphicsComponentBase::Draw(const GameObject& object, Renderer& renderer)
{
	UpdateSprite(object, renderer, *sprite_);
}

void GraphicsComponentBase::UpdateSprite(const GameObject& object, Renderer& renderer, sf::Sprite& sprite)
{
	//Global scale
	sprite.setScale(renderer.GetScale());
	//Mirror with scale of -1
	sprite.scale(object.GetOrientation().ToSFML());
	//set position in view
	sprite.setPosition(object.GetRenderPosition().ToSFML());
}
