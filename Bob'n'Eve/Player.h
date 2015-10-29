#pragma once
#include <stdint.h>
#include <Box2D/Dynamics/b2Body.h>
#include "GameObject.h"

class GraphicsComponentBase;
class InputComponent;
class Renderer;

class Player : public GameObject
{
	friend class PhysicManager;
public:
	Player(InputComponent* input, PhysicsComponent* physics, GraphicsComponentBase* graphics);
	~Player();

	virtual void Draw(Renderer& renderer) const override;
	virtual void Update(int16_t ms) override;

	virtual void MoveLeft();
	virtual void MoveRight();
	virtual void Jump();

protected:
	InputComponent* input_;
	PhysicsComponent* physics_;
	GraphicsComponentBase* graphics_;
};