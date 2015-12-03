#include "PhysicsComponentStatic.h"
#include "PhysicBodyDef.h"
#include <assert.h>


PhysicsComponentStatic::PhysicsComponentStatic(const PhysicBodyDef& bodyDef) : PhysicsComponentBase(bodyDef)
{
	assert(bodyDef.type_ == PhysicBody::STATIC);
}


PhysicsComponentStatic::~PhysicsComponentStatic()
{
}