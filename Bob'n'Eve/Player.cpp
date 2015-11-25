#pragma once
#include "Player.h"
#include "GraphicsComponent.h"

Player::Player(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* idleGraphics, GraphicsComponent* jumpGraphics, GraphicsComponent* runGraphics)
	: GameObject(input, physics, idleGraphics)
{
	idleGraphics_ = idleGraphics;
	jumpGraphics_ = jumpGraphics;
	runGraphics_ = runGraphics;
}

Player::~Player()
{
	delete idleGraphics_;
	delete jumpGraphics_;
	delete runGraphics_;
}

void Player::Update(int16_t ms)
{
	if (GetVelocity().x != 0)
	{
		if (GetVelocity().y != 0)
		{
			GameObject::graphics_ = jumpGraphics_;
		}
		else
		{
			GameObject::graphics_ = runGraphics_;
		}
	}
	else
	{
		GameObject::graphics_ = idleGraphics_;
	}

	GameObject::Update(ms);
}
