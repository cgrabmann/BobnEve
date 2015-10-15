#pragma once

#include <list>
#include "Entity.h"

class EntityComposite : public Entity
{
public:
	EntityComposite(float layer, int id, Entity::TypeEnum type);
	virtual ~EntityComposite();

	void Update(int ms) override;
	void Draw(Renderer& renderer) override;

	void Add(Entity* e);
	void Remove(Entity* e);

protected:
	std::list<Entity> entities_;
};