#pragma once

#include "GraphicsComponentFade.h"
#include <SFML/include/SFML/Graphics/Color.hpp>
#include "Renderer.h"
#include <SFML/include/SFML/Graphics/Sprite.hpp>
#include "Frame.h"


GraphicsComponentFade::GraphicsComponentFade(std::vector<Frame*> frames, bool mirror, bool running) : GraphicsComponentAnimated(frames, mirror, running), lastIndex_(frames.size() - 1), lastSprite_(frames.at(lastIndex_)->sprite), alpha_(255), lastAlpha_(0)
{
}

void GraphicsComponentFade::Update(GameObject& object, int16_t ms)
{
	if (!isRunning_)
		return;

	int32_t tempIndex = index_;
	GraphicsComponentAnimated::Update(object, ms);

	if (tempIndex != index_)
	{
		lastIndex_ = tempIndex;
		lastSprite_ = frames_[lastIndex_]->sprite;
	}

	int32_t base = 255 * 255;
	float t = msCount_ * 1.f / frames_[index_]->displayTime;

	alpha_ = sqrtf(base * t);
	lastAlpha_ = sqrtf(base * (1 - t));
}

void GraphicsComponentFade::Draw(const GameObject& object, Renderer& renderer)
{
	if (!sprite_ || !isVisible_)
		return;

	UpdateSprite(object, renderer, *sprite_);
	UpdateSprite(object, renderer, *lastSprite_);

	sprite_->setColor(sf::Color(255, 255, 255, alpha_));
	lastSprite_->setColor(sf::Color(255, 255, 255, lastAlpha_));

	//draw
	renderer.GetTarget().draw(*sprite_);
	renderer.GetTarget().draw(*lastSprite_);
}
