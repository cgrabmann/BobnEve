#pragma once
#include <cinttypes>
#include "Vector2f.h"
#include "PhysicBodyBase.h"

struct PhysicBodyDef;
class b2Body;
class GameObject;

class PhysicsComponentBase
{
	friend class PhysicManager;
public:
	~PhysicsComponentBase();

	void Update(GameObject& object, int16_t ms);

	inline Vector2f PhysicsComponentBase::GetPosition() const
	{
		return body_->GetPosition();
	}

	inline Vector2f PhysicsComponentBase::GetVelocity() const
	{
		return body_->GetVelocity();
	}
	Vector2f GetOrientation() const;

	void SetVelocity(const Vector2f& velocity);
	void SetVelocity(float velX, float velY);

protected:
	PhysicsComponentBase(const PhysicBodyDef& bodyDef);

	PhysicBodyBase* body_;
};

