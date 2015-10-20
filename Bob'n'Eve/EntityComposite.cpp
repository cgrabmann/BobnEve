#include "EntityComposite.h"

#include "Renderer.h"

EntityComposite::EntityComposite(float layer, int32_t id, Entity::TypeEnum type) : Entity(layer, id, type)
{
}

EntityComposite::~EntityComposite()
{
}

void EntityComposite::Update(int16_t ms)
{
}

void EntityComposite::Draw(Renderer& renderer)
{
	Entity::Draw(renderer);
}

void EntityComposite::Add(Entity* e)
{
}

void EntityComposite::Remove(Entity* e)
{
}