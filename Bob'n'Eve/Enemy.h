#pragma once
#include <stdint.h>
#include "GameObject.h"

class GraphicsComponentBase;
class InputComponentBase;
class Renderer;

class Enemy : public GameObject
{
public:
	Enemy(InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics);
	~Enemy();

protected:
};
