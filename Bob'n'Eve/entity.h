#pragma once

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

private:


protected:
	//z-buffer
	float layer_;
	int id_;
	TypeEnum type_;

	//image
	//physic object

public:

	Entity(float layer, int id, Entity::TypeEnum type);
	virtual ~Entity();

	virtual void Draw(Renderer& renderer);
	virtual void Update(int ms);

	int GetId() const;
	void GetType(Entity::TypeEnum*& type);
};
