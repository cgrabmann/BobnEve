#pragma once
#include <stdint.h>
#include "GameObject.h"

class Renderer;

class Platform : public GameObject
{
	friend class PhysicManager;
public:
	Platform();
	~Platform();

	virtual void Draw(Renderer& renderer) const override;
	virtual void Update(int16_t ms) override;

protected:
};
