#pragma once
#include <cinttypes>

class Renderer;
class GameObject;

class GraphicsComponentBase
{
public:
	GraphicsComponentBase();
	virtual ~GraphicsComponentBase();

	virtual void Update(GameObject& object, int16_t ms) = 0;
	virtual void Draw(const GameObject& object, Renderer& renderer) const = 0;

protected:
};

