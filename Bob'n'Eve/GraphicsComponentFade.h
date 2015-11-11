#pragma once
#include "GraphicsComponentAnimated.h"
class GraphicsComponentFade :
	public GraphicsComponentAnimated
{
public:
	GraphicsComponentFade(std::vector<sf::Sprite*> sprites, int16_t msPerFrame);

	virtual void Update(GameObject& object, int16_t ms) override;
	virtual void Draw(const GameObject& object, Renderer& renderer) override;

private:
	uint32_t lastIndex_;
	sf::Sprite* lastSprite_;
	uint8_t alpha_, lastAlpha_;
};

