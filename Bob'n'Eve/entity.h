#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "render_options.h"

class entity
{
protected:
	//z-buffer
	float layer;
public:
	entity();
	void draw(render_options options);
	void update(int ms);
};

#endif