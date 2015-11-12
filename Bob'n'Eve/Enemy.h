#pragma once
#include <stdint.h>
#include "GameObject.h"

class GraphicsComponent;
class InputComponent;
class Renderer;

class Enemy : public GameObject
{
public:
	Enemy(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics);
	~Enemy();

protected:
};
