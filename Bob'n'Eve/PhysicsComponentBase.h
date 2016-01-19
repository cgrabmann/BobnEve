#pragma once
#include <cinttypes>
#include "Vector2f.h"
#include "PhysicBodyBase.h"

struct PhysicBodyDef;
class b2Body;
class GameObject;

class PhysicsComponentBase
{
public:
	virtual ~PhysicsComponentBase();

	virtual void Update(GameObject& object, int16_t ms);

	inline Vector2f GetPosition() const
	{
		return body_->GetPosition();
	}

	virtual inline Vector2f PhysicsComponentBase::GetVelocity() const
	{
		return body_->GetVelocity();
	}
	virtual Vector2f GetOrientation() const;

	virtual void SetVelocity(const Vector2f& velocity);
	virtual void SetVelocity(float velX, float velY);

protected:
	explicit PhysicsComponentBase(const PhysicBodyDef& bodyDef);

	PhysicBodyBase* body_;
};

