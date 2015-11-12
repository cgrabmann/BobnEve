#pragma once
#include "PhysicsComponentBase.h"

class PhysicsComponentStatic : public PhysicsComponentBase
{
public:
	explicit PhysicsComponentStatic(const Vector2f& position);
	~PhysicsComponentStatic();

private:
	static b2BodyDef CreateBodyDef(const Vector2f& position);
	static b2PolygonShape InitShape();
	static b2FixtureDef InitFixtureDef();

	static b2PolygonShape s_shape_;
	static b2FixtureDef s_fixtureDef_;
};

