#pragma once
#include "DoubleEnemy.h"
#include "PhysicsComponentBase.h"
#include "GraphicsComponent.h"


DoubleEnemy::DoubleEnemy(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics, PhysicsComponentBase* physics2, GraphicsComponent* graphics2) : 
Enemy(input, physics, graphics), physics2_(physics2), graphics2_(graphics)
{
}


DoubleEnemy::~DoubleEnemy()
{
}

void DoubleEnemy::Update(int16_t ms)
{
	Enemy::Update(ms);

	physics2_->Update(*this, ms);
	graphics2_->Update(*this, ms);
}

void DoubleEnemy::Draw(Renderer& renderer) const
{
	Enemy::Draw(renderer);

	graphics2_->Draw(*this, renderer);
}
