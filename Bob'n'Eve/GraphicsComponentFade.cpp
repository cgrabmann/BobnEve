#pragma once

#include "GraphicsComponentFade.h"
#include <SFML/include/SFML/Graphics/Color.hpp>
#include "Renderer.h"
#include <SFML/include/SFML/Graphics/Sprite.hpp>
#include <math.h>


GraphicsComponentFade::GraphicsComponentFade(std::vector<sf::Sprite*> sprites, int16_t msPerFrame) : GraphicsComponentAnimated(sprites, msPerFrame), lastIndex_(sprites.size() - 1), lastSprite_(sprites.at(lastIndex_)), alpha_(255), lastAlpha_(0)
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

	//alpha = msCount_ * 255.f / msPerFrame;
	//alpha = pow(2, msCount_ * 8.f / msPerFrame) - 1;

	int32_t base = 255 * 255;
	float t = msCount_ * 1.f / msPerFrame;

	alpha_ = sqrtf(base * t);
	lastAlpha_ = sqrtf(base * (1 - t));
}

void GraphicsComponentFade::Draw(const GameObject& object, Renderer& renderer)
{
	UpdateSprite(object, renderer, *sprite_);
	UpdateSprite(object, renderer, *lastSprite_);

	sprite_->setColor(sf::Color(255, 255, 255, alpha_));
	lastSprite_->setColor(sf::Color(255, 255, 255, lastAlpha_));

	//draw
	renderer.GetTarget().draw(*sprite_);
	renderer.GetTarget().draw(*lastSprite_);
}
