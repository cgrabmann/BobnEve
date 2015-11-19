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


	GraphicsComponentAnimated(std::vector<Frame*> frames, bool mirror = true, bool running = true);
	virtual ~GraphicsComponentAnimated();

	virtual void Update(GameObject& object, int16_t ms) override;
	//virtual void Draw(const GameObject& object, Renderer& renderer) override;

	virtual void Stop() override { isRunning_ = false; index_ = 0; }
	virtual void ReStart() override { isRunning_ = true; index_ = 0; }
	virtual void Reset() override { index_ = 0; }

protected:
	std::vector<uint8_t> indizes;
	std::vector<Frame*> frames_;
	int32_t index_;
	int16_t msCount_; 
	uint16_t displayTime_;
	bool mirror_, mirroring_;
};

