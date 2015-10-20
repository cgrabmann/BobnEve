#pragma once

#include <list>
#include "Entity.h"

class EntityComposite : public Entity
{
public:
	EntityComposite(float layer, int32_t id, Entity::TypeEnum type);
	virtual ~EntityComposite();

	void Update(int16_t ms) override;
	void Draw(Renderer& renderer) override;

	void Add(Entity* e);
	void Remove(Entity* e);

protected:
	std::list<Entity> entities_;
};