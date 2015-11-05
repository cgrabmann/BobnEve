#pragma once
#include <cinttypes>
#include "Vector2f.h"

class b2Body;
class GameObject;

class PhysicsComponentBase
{
	friend class PhysicManager;
public:
	explicit PhysicsComponentBase(Vector2f* position);
	explicit PhysicsComponentBase(float x, float y);
	~PhysicsComponentBase();

	void Update(GameObject& object, int16_t ms);

	const Vector2f& GetPosition() const;
	const Vector2f& GetVelocity() const;

	Vector2f GetOrientation() const;

	void SetVelocity(const Vector2f& velocity);
	void SetVelocity(float velX, float velY);

protected:

	b2Body* body_;
	void setPhysicBody(b2Body* body);
	//temp
	Vector2f* position_;
	Vector2f* velocity_;
};

