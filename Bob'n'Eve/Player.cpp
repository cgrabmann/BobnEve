#pragma once
#include "Player.h"
#include "GraphicsComponent.h"
#include "View.h"

Player::Player(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* idleGraphics, GraphicsComponent* jumpGraphics, GraphicsComponent* runGraphics, Vector2f speed)
	: GameObject(input, physics, idleGraphics, speed)
{
	idleGraphics_ = idleGraphics;
	jumpGraphics_ = jumpGraphics;
	runGraphics_ = runGraphics;
}

Player::~Player()
{
	if (graphics_ != idleGraphics_)
		delete idleGraphics_;
	if (graphics_ != jumpGraphics_)
		delete jumpGraphics_;
	if (graphics_ != runGraphics_)
		delete runGraphics_;
}

void Player::Update(int16_t ms)
{
	Vector2f vel = GetVelocity();
	if (vel.x != 0)
	{
		if (vel.y != 0)
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

void Player::Kill()
{
	View::Instance()->Destroy(this);
}
