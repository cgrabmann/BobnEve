#pragma once
#include "Vector2f.h"
#include "FloatRect.h"
#include "PhysicBodyBase.h"

class Shape;

enum Sides
{
	Top, Right, Bottom, Left
};

struct PhysicBodyDef
{
	PhysicBody::Type type_ = PhysicBody::Type::STATIC;
	FloatRect bounds_;
	int8_t gravityScale_ = 1;
	std::vector<int8_t> collisionIgnoreGroups_;
	bool* collisionSides_ = new bool[4];
	CollisionCallback* callback_ = nullptr;
	std::string customId_;

	inline PhysicBodyDef& SetCallback(CollisionCallback* callback)
	{
		callback_ = callback;
		return *this;
	}
};