#pragma once
#include <stdint.h>
#include "GameObject.h"

class GraphicsComponent;
class InputComponent;
class Renderer;

class Platform : public GameObject
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="input">1 InputComponent</param>
	/// <param name="physics">1 PhysicsComponent</param>
	/// <param name="graphics">1 GraphicsComponents</param>
	Platform(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics);
	~Platform();

protected:
};
