#include "PhysicsComponentDynamic.h"


PhysicsComponentDynamic::PhysicsComponentDynamic(const Vector2f& position) : PhysicsComponentBase(CreateBodyDef(position), s_fixtureDef_)
{
}


PhysicsComponentDynamic::~PhysicsComponentDynamic()
{
}

b2BodyDef PhysicsComponentDynamic::CreateBodyDef(const Vector2f& position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(position.x, position.y);
	return bodyDef;
}

b2PolygonShape PhysicsComponentDynamic::InitShape()
{
	b2PolygonShape shape;
	shape.SetAsBox(0.5f, 0.5f);
	return shape;
}

b2FixtureDef PhysicsComponentDynamic::InitFixtureDef()
{
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &s_shape_;
	fixtureDef.density = 1.f;
	fixtureDef.friction = 0.3f;

	return fixtureDef;
}

b2PolygonShape PhysicsComponentDynamic::s_shape_ = PhysicsComponentDynamic::InitShape();
b2FixtureDef PhysicsComponentDynamic::s_fixtureDef_ = PhysicsComponentDynamic::InitFixtureDef();