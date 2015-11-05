#pragma once
#include <stdint.h>
#include "GameObject.h"

class GraphicsComponentBase;
class InputComponentBase;
class Renderer;

class Platform : public GameObject
{
public:
	Platform(InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics);
	~Platform();

protected:
};
