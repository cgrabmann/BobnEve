#pragma once

#include "GraphicsComponentFade.h"
#include <SFML/include/SFML/Graphics/Color.hpp>
#include "Renderer.h"
#include <SFML/include/SFML/Graphics/Sprite.hpp>


GraphicsComponentFade::GraphicsComponentFade(std::vector<sf::Sprite*> sprites, int16_t msPerFrame) : GraphicsComponentAnimated(sprites, msPerFrame), lastIndex_(sprites.size() - 1), lastSprite_(sprites.at(lastIndex_)), alpha(255)
{
}

void GraphicsComponentFade::Update(GameObject& object, int16_t ms)
{
	msCount_ += ms;
	uint16_t msPerFrame = msPerFrame_.at(index_);

	if (msCount_ >= msPerFrame)
	{
		msCount_ -= msPerFrame;
		lastIndex_ = index_;
		index_++;
		index_ %= sprites_.size();

		lastSprite_ = sprite_;
		sprite_ = sprites_.at(index_);
	}
	alpha = 255 * msCount_ / msPerFrame;
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
