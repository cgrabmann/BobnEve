#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics, size_t enemyId, Vector2f speed);
	~Enemy();

	size_t GetId() const { return enemyId_; }

	virtual void Kill() override;
protected:
	size_t enemyId_;
};
