#pragma once
#include <stdint.h>
#include <Box2D/Dynamics/b2Body.h>

class Renderer;

class Player
{
	friend class PhysicManager;
public:

	Player(float layer, int32_t id);
	virtual ~Player();

	virtual void Draw(Renderer* renderer) const;
	virtual void Update(int16_t ms);

	int32_t GetId() const;

protected:
	//z-buffer
	float layer_;
	int32_t id_;

	b2Body* body_;

	void setPhysicBody(b2Body* body);

	//image
	//physic object

};
