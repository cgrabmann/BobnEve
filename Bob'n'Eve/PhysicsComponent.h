#pragma once
#include <cinttypes>
#include "Vector2f.h"

class b2Body;
class GameObject;

class PhysicsComponent
{
	friend class PhysicManager;
public:
	explicit PhysicsComponent(const Vector2f& position, bool dynamic);
	~PhysicsComponent();

	void Update(GameObject& object, int16_t ms);

	Vector2f GetPosition() const;
	Vector2f GetVelocity() const;
	Vector2f GetOrientation() const;

	void SetVelocity(const Vector2f& velocity);
	void SetVelocity(float velX, float velY);

protected:

	b2Body* body_;
};
