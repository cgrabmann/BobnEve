#pragma once
#include <stdint.h>
#include "GameObject.h"

class GraphicsComponent;
class PhysicsComponent;
class InputComponent;
class Renderer;

class Player : public GameObject
{
public:
	Player(InputComponent* input, PhysicsComponent* physics, GraphicsComponent* graphics);
	~Player();
protected:
};