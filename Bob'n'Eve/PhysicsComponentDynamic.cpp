#include "PhysicsComponentDynamic.h"
#include "PhysicBodyDef.h"
#include <assert.h>


PhysicsComponentDynamic::PhysicsComponentDynamic(const PhysicBodyDef& bodyDef) : PhysicsComponentBase(bodyDef)
{
	assert(bodyDef.type_ == PhysicBody::DYNAMIC);
}


PhysicsComponentDynamic::~PhysicsComponentDynamic()
{
}