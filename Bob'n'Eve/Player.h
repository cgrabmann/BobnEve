#pragma once
#include <stdint.h>
#include "GameObject.h"

class GraphicsComponentBase;
class PhysicsComponentBase;
class InputComponentBase;
class Renderer;

class Player : public GameObject
{
public:
	Player(InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics);
	Player(b2Body* physicsBody, b2Vec2 orientation, InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics);
	~Player();

	virtual void Draw(Renderer& renderer) const override;
	virtual void Update(int16_t ms) override;

	virtual void MoveLeft();
	virtual void MoveRight();
	virtual void Jump();

protected:
};