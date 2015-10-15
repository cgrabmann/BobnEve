#pragma once
#include <atomic>

class Renderer;

class Entity
{
public:

	enum TypeEnum
	{
		PLAYER,
		ENEMY,
		PLATFORM,
		JUMPPAD,
		PASSTHROUGH
	};

	Entity(float layer, int8_t id, Entity::TypeEnum type);
	virtual ~Entity();

	virtual void Draw(Renderer& renderer);
	virtual void Update(int ms);

	int8_t GetId() const;
	void GetType(Entity::TypeEnum*& type);

protected:
	//z-buffer
	float layer_;
	int8_t id_;
	TypeEnum type_;

	//image
	//physic object

};
