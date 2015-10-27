#pragma once
#include <stdint.h>
#include <Box2D/Dynamics/b2Body.h>
#include "GameObject.h"

class Renderer;

class Enemy : public GameObject
{
	friend class PhysicManager;
public:
	Enemy();
	~Enemy();

	virtual void Draw(Renderer& renderer) const override;
	virtual void Update(int16_t ms) override;

protected:
};
