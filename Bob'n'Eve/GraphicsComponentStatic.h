#pragma once
#include "GraphicsComponentBase.h"
#include <SFML/include/SFML/Graphics/Sprite.hpp>

class GraphicsComponentStatic :	public GraphicsComponentBase
{
public:
	GraphicsComponentStatic(sf::Sprite* sprite);
	virtual ~GraphicsComponentStatic();

	virtual void Update(GameObject& object, int16_t ms) override;
	virtual void Draw(const GameObject& object, Renderer& renderer) const override;

private:
	sf::Sprite* sprite_;
};

