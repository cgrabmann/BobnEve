#pragma once
#include <stdint.h>
#include <Box2D/Dynamics/b2Body.h>

class Renderer;

class Entity
{
	friend class PhysicManager;
public:

	Entity(float layer, int32_t id);
	virtual ~Entity();

	virtual void Draw(Renderer& renderer);
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
