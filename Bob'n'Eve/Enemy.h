#pragma once
#include <stdint.h>
#include <Box2D/Dynamics/b2Body.h>
#include "GameObject.h"

class GraphicsComponentBase;
class InputComponentBase;
class Renderer;

class Enemy : public GameObject
{
	friend class PhysicManager;
public:
	Enemy(InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics);
	Enemy(b2Body* physicsBody, b2Vec2 orientation, InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics);
	~Enemy();

	virtual void Draw(Renderer& renderer) const override;
	virtual void Update(int16_t ms) override;

protected:
};
