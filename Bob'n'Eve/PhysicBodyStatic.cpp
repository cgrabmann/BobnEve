#include "PhysicBodyStatic.h"

PhysicBodyStatic::PhysicBodyStatic(const PhysicBodyDef& def) : PhysicBodyBase(def)
{
}

PhysicBodyStatic::~PhysicBodyStatic()
{
}

void PhysicBodyStatic::Move(const Vector2f& gravity, int32_t ms)
{
}

void PhysicBodyStatic::SetVelocity(const Vector2f& velocity)
{
}

void PhysicBodyStatic::SetPhysicScale(float scale)
{
}