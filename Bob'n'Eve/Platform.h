#pragma once
#include <stdint.h>
#include "GameObject.h"

class GraphicsComponentBase;
class InputComponentBase;
class Renderer;

class Platform : public GameObject
{
public:
	Platform(InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics);
	Platform(b2Body* physicsBody, b2Vec2 orientation, InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics);
	~Platform();

	virtual void Draw(Renderer& renderer) const override;
	virtual void Update(int16_t ms) override;

protected:
};
