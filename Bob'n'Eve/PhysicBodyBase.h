#pragma once
#include "Vector2f.h"

struct PhysicBodyDef;
class CollisionResolver;

class PhysicBodyBase
{
	friend class PhysicWorld;
public:
	const Vector2f& GetPosition() const;
	const Vector2f& GetVelocity() const;
	bool IsColliding(const PhysicBodyBase& otherBody) const;

	virtual void SetVelocity(const Vector2f& velocity) = 0;
	virtual void SetPhysicScale(float scale) = 0;

protected:
	explicit PhysicBodyBase(const PhysicBodyDef& def);
	virtual ~PhysicBodyBase();

	virtual void Move(const Vector2f& gravity, int32_t ms) = 0;
	void ResolveCollision(PhysicBodyBase& otherBody);

	Vector2f velocity_;
	Vector2f position_;
	Vector2f halfSize_;
	int8_t mass_;
	float physicScale_;
	CollisionResolver* resolver_;
};

class PhysicBody
{
public:
	enum Type{
		STATIC,
		DYNAMIC
	};
};