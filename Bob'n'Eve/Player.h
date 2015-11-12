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
	Player(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics);
	~Player();
protected:
};