#ifndef _VIEW_H_
#define _VIEW_H_

#include "entity_composite.h"

class view : public entity_composite
{
protected:

public:
	view();
	void init();
	void draw(render_options options);
	void update(int ms);
	void add(entity e);
	void remove(entity e);
};

#endif