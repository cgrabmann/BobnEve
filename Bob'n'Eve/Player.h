#pragma once
#include <stdint.h>
#include <Box2D/Dynamics/b2Body.h>
#include "GameObject.h"

class InputComponentBase;
class GraphicsComponent;
class Renderer;

class Player : public GameObject
{
	friend class PhysicManager;
public:
	Player(InputComponentBase* input, PhysicsComponent* physics, GraphicsComponent* graphics);
	~Player();

	virtual void Draw(Renderer& renderer) const override;
	virtual void Update(int16_t ms) override;

	virtual void MoveLeft();
	virtual void MoveRight();
	virtual void Jump();

protected:
	InputComponentBase* input_;
	PhysicsComponent* physics_;
	GraphicsComponent* graphics_;
};