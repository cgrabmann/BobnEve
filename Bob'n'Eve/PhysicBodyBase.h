#pragma once
#include "Vector2f.h"
#include <vector>

class PhysicBodyDynamic;
class PhysicBodyStatic;
struct PhysicBodyDef;
class CollisionResolver;

class PhysicBodyBase
{
	friend class PhysicWorld;
public:
	inline const Vector2f& GetPosition() const
	{
		return position_;
	};
	inline const Vector2f& GetVelocity() const
	{
		return velocity_;
	};
	inline const Vector2f& GetHalfSize() const
	{
		return halfSize_;
	};
	bool IsColliding(const PhysicBodyBase& otherBody) const;
	void AddCollisionIgnoreGroup(int8_t group);
	void RemoveCollisionIgnoreGroup(int8_t group);
	bool IsInGroup(int8_t group);

	virtual void CollideWith(PhysicBodyBase& otherBody) = 0;
	virtual void CollideWithStatic(PhysicBodyStatic& otherBody) = 0;
	virtual void CollideWithDynamic(PhysicBodyDynamic& otherBody) = 0;

	virtual void SetVelocity(const Vector2f& velocity) = 0;
	virtual void SetPhysicScale(float scale) = 0;

protected:
	explicit PhysicBodyBase(const PhysicBodyDef& def);
	virtual ~PhysicBodyBase();

	virtual void Move(const Vector2f& gravity, int32_t ms) = 0;

	bool IsCollidingX(const PhysicBodyBase& otherBody) const;
	bool IsCollidingY(const PhysicBodyBase& otherBody) const;

	Vector2f velocity_;
	Vector2f position_;
	Vector2f halfSize_;
	float physicScale_;
	std::vector<int8_t> collisionIgnorGroups_;
};

class PhysicBody
{
public:
	enum Type{
		STATIC,
		DYNAMIC
	};
};