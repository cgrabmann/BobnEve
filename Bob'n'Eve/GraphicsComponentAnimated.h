#pragma once
#include "GraphicsComponentStatic.h"
#include <vector>

namespace sf{
	class Sprite;
}

class GraphicsComponentAnimated : public GraphicsComponentStatic
{
public:
	GraphicsComponentAnimated(std::vector<sf::Sprite*> sprites, std::vector<int16_t> msPerFrame);
	GraphicsComponentAnimated(std::vector<sf::Sprite*> sprites, int16_t msPerFrame);
	virtual ~GraphicsComponentAnimated();

	virtual void Update(GameObject& object, int16_t ms) override;
	
protected:
	std::vector<sf::Sprite*> sprites_;
	int32_t index_;
	int16_t msCount_; 
	std::vector<int16_t> msPerFrame_;
};

