#pragma once
#include "Vector2f.h"
#include "PhysicBodyBase.h"

class Shape;

struct PhysicBodyDef
{
	PhysicBody::Type type_ = PhysicBody::Type::STATIC;
	Vector2f position_ = Vector2f(0.f, 0.f);
	Vector2f halfSize_ = Vector2f(0.5f, 0.5f);
	int8_t gravityScale_ = 1;
	int8_t mass_ = 0;
	CollisionResolver* resolver_ = nullptr;
	int8_t collisionIgnorGroup_ = 0;
};