#pragma once
#include <stdint.h>
#include "GameObject.h"

class GraphicsComponent;
class PhysicsComponentBase;
class InputComponent;
class Renderer;

class Player : public GameObject
{
public:
	Player(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* idleGraphics, GraphicsComponent* jumpGraphics, GraphicsComponent* runGraphics);
	~Player();
	
	virtual void Update(int16_t ms) override;
protected:
	GraphicsComponent* idleGraphics_;
	GraphicsComponent* jumpGraphics_;
	GraphicsComponent* runGraphics_;
};