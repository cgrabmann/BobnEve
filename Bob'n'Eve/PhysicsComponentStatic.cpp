#include "PhysicsComponentStatic.h"


PhysicsComponentStatic::PhysicsComponentStatic(const Vector2f& position) : PhysicsComponentBase(CreateBodyDef(position), s_fixtureDef_)
{
}


PhysicsComponentStatic::~PhysicsComponentStatic()
{
}

b2BodyDef PhysicsComponentStatic::CreateBodyDef(const Vector2f& position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(position.x, position.y);
	return bodyDef;
}

b2PolygonShape PhysicsComponentStatic::InitShape()
{
	b2PolygonShape shape;
	shape.SetAsBox(0.5f, 0.5f);

	return shape;
}

b2FixtureDef PhysicsComponentStatic::InitFixtureDef()
{
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &s_shape_;
	fixtureDef.density = 0.f;
	fixtureDef.friction = 0.f;

	return fixtureDef;
}

b2PolygonShape PhysicsComponentStatic::s_shape_ = PhysicsComponentStatic::InitShape();
b2FixtureDef PhysicsComponentStatic::s_fixtureDef_ = PhysicsComponentStatic::InitFixtureDef();