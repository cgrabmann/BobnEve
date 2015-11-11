#pragma once

#include "GraphicsComponentFade.h"
#include <SFML/include/SFML/Graphics/Color.hpp>
#include "Renderer.h"
#include <SFML/include/SFML/Graphics/Sprite.hpp>


GraphicsComponentFade::GraphicsComponentFade(std::vector<sf::Sprite*> sprites, int16_t msPerFrame, bool mirror) : GraphicsComponentAnimated(sprites, msPerFrame, mirror), lastIndex_(sprites.size() - 1), lastSprite_(sprites.at(lastIndex_)), alpha(255)
{
}

void GraphicsComponentFade::Update(GameObject& object, int16_t ms)
{
	int32_t tempIndex = index_;
	GraphicsComponentAnimated::Update(object, ms);

	if (tempIndex != index_)
	{
		lastIndex_ = tempIndex;
	}

	lastSprite_ = sprites_[lastIndex_];
	alpha = 255 * msCount_ / msPerFrame_.at(index_);
}

void GraphicsComponentFade::Draw(const GameObject& object, Renderer& renderer)
{
	UpdateSprite(object, renderer, *sprite_);
	UpdateSprite(object, renderer, *lastSprite_);

	sprite_->setColor(sf::Color(255, 255, 255, alpha));
	lastSprite_->setColor(sf::Color(255, 255, 255, 255 - alpha));

	//draw
	renderer.GetTarget().draw(*sprite_);
	renderer.GetTarget().draw(*lastSprite_);
}
