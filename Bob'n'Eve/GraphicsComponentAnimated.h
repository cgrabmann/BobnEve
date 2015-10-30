#pragma once
#include "GraphicsComponentBase.h"

class GraphicsComponentAnimated : public GraphicsComponentBase
{
public:
	GraphicsComponentAnimated();
	virtual ~GraphicsComponentAnimated();

	virtual void Update(GameObject& object, int16_t ms) override;
	virtual void Draw(const GameObject& object, Renderer& renderer) const override;
};

