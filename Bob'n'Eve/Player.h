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
	~Player();
protected:
};