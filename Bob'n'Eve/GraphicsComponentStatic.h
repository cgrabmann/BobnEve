#pragma once
#include "GraphicsComponentBase.h"

namespace sf{
	class Sprite;
}

class GraphicsComponentStatic :	public GraphicsComponentBase
{
public:
	GraphicsComponentStatic(sf::Sprite* sprite);
	virtual ~GraphicsComponentStatic();

	virtual void Update(GameObject& object, int16_t ms) override;
	virtual void Draw(const GameObject& object, Renderer& renderer) override;
};

