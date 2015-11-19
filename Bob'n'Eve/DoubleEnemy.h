#pragma once
#include "Enemy.h"
class DoubleEnemy : public Enemy
{
public:
	DoubleEnemy(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics, PhysicsComponentBase* physics2, GraphicsComponent* graphics2);
	~DoubleEnemy();

	virtual void Update(int16_t ms) override;
	virtual void Draw(Renderer& renderer) const override;

private:
	PhysicsComponentBase* physics2_;
	GraphicsComponent* graphics2_;
};

