#pragma once
#include "Platform.h"
class JumpPad :
	public Platform
{
public:
	JumpPad(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics);
	~JumpPad();
};

