#ifndef _ENTITY_COMPOSITE_H_
#define _ENTITY_COMPOSITE_H_

#include "entity.h"
#include <list>

class entity_composite : public entity
{
protected:
	std::list<entity> entities;

public:
	entity_composite();
	void draw(render_options options);
	void update(int ms);
	void add(entity e);
	void remove(entity e);
};

#endif