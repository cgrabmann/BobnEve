#pragma once
#include "Vector2f.h"
#include "FloatRect.h"
#include "PhysicBodyBase.h"

class Shape;

struct PhysicBodyDef
{
	PhysicBody::Type type_ = PhysicBody::Type::STATIC;
	FloatRect bounds;
	int8_t gravityScale_ = 1;
	int8_t collisionIgnorGroup_ = 0;
};