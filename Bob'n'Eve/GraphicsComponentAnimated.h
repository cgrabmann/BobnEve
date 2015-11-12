#pragma once
#include "GraphicsComponent.h"
#include <vector>

namespace sf{
	class Sprite;
}

class GraphicsComponentAnimated : public GraphicsComponent
{
public:
	GraphicsComponentAnimated(std::vector<sf::Sprite*> sprites, std::vector<int16_t> msPerFrame, bool mirror = true);
	GraphicsComponentAnimated(std::vector<sf::Sprite*> sprites, int16_t msPerFrame, bool mirror = true);
	virtual ~GraphicsComponentAnimated();

	virtual void Update(GameObject& object, int16_t ms) override;
	//virtual void Draw(const GameObject& object, Renderer& renderer) override;
	
protected:
	std::vector<sf::Sprite*> sprites_;
	int32_t index_;
	int16_t msCount_; 
	std::vector<int16_t> msPerFrame_;
	bool mirror_, mirroring_;
};

