#pragma once
#include "DoubleEnemy.h"
#include "PhysicsComponentBase.h"
#include "GraphicsComponent.h"


DoubleEnemy::DoubleEnemy(InputComponent* input, PhysicsComponentBase* physics1, GraphicsComponent* graphics1, PhysicsComponentBase* physics2, GraphicsComponent* graphics2) : 
Enemy(input, physics1, graphics1), physics2_(physics2), graphics2_(graphics1)
{
}


DoubleEnemy::~DoubleEnemy()
{
	delete physics2_;
	delete graphics2_;
}

void DoubleEnemy::Update(int16_t ms)
{
	if (!isActive_)
		return;

	Enemy::Update(ms);

	if (physics2_)
	physics2_->Update(*this, ms);
	if (graphics2_)
	graphics2_->Update(*this, ms);
}

void DoubleEnemy::Draw(Renderer& renderer) const
{
	if (!isActive_)
		return;

	Enemy::Draw(renderer);

	if (graphics2_)
	graphics2_->Draw(*this, renderer);
}
