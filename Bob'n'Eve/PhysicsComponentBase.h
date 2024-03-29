#pragma once
#include <cinttypes>
#include "Vector2f.h"

class b2Body;
class GameObject;

class PhysicsComponentBase
{
	friend class PhysicManager;
public:
	~PhysicsComponentBase();

	void Update(GameObject& object, int16_t ms);

	Vector2f GetPosition() const;
	Vector2f GetVelocity() const;
	Vector2f GetOrientation() const;

	void SetVelocity(const Vector2f& velocity);
	void SetVelocity(float velX, float velY);

protected:
	PhysicsComponentBase(b2BodyDef& bodyDef, const b2FixtureDef& fixtureDef);

	b2Body* body_;
};

