#pragma once
#include <stdint.h>
#include <Box2D/Dynamics/b2Body.h>

class Renderer;

class Entity
{
	friend class PhysicManager;
public:

	enum TypeEnum
	{
		PLAYER,
		ENEMY,
		PLATFORM,
		JUMPPAD,
		PASSTHROUGH
	};

	Entity(float layer, int32_t id, Entity::TypeEnum type);
	virtual ~Entity();

	virtual void Draw(Renderer& renderer);
	virtual void Update(int16_t ms);

	int32_t GetId() const;
	void GetType(Entity::TypeEnum*& type);

protected:
	//z-buffer
	float layer_;
	int32_t id_;
	TypeEnum type_;

	b2Body* body_;

	void setPhysicBody(b2Body* body);

	//image
	//physic object

};
