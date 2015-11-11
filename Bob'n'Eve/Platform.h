#pragma once
#include <stdint.h>
#include "GameObject.h"

class GraphicsComponent;
class InputComponent;
class Renderer;

class Platform : public GameObject
{
public:
	Platform(InputComponent* input, PhysicsComponent* physics, GraphicsComponent* graphics);
	~Platform();

protected:
};
