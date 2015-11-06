#pragma once
#include "GraphicsComponentStatic.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Vector2f.h"
#include <SFML/include/SFML/Graphics/Sprite.hpp>


GraphicsComponentStatic::GraphicsComponentStatic(sf::Sprite* sprite) : GraphicsComponentBase(sprite)
{
}

GraphicsComponentStatic::~GraphicsComponentStatic()
{
}

void GraphicsComponentStatic::Update(GameObject& object, int16_t ms)
{

}

void GraphicsComponentStatic::Draw(const GameObject& object, Renderer& renderer)
{
	UpdateSprite(object, renderer, *sprite_);
	//draw
	renderer.GetTarget().draw(*sprite_);
}

