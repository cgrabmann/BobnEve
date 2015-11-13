#pragma once
#include "GraphicsComponent.h"
#include <vector>

class Frame;

namespace sf{
	class Sprite;
}

class GraphicsComponentAnimated : public GraphicsComponent
{
public:
	GraphicsComponentAnimated(std::vector<Frame*> frames, bool mirror = true);
	virtual ~GraphicsComponentAnimated();

	virtual void Update(GameObject& object, int16_t ms) override;
	//virtual void Draw(const GameObject& object, Renderer& renderer) override;
	
protected:
	std::vector<uint8_t> indizes;
	std::vector<Frame*> frames_;
	int32_t index_;
	int16_t msCount_; 
	uint16_t displayTime_;
	bool mirror_, mirroring_;
};

