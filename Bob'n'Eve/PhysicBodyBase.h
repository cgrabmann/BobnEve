#pragma once
#include "Vector2f.h"
#include "FloatRect.h"
#include <vector>
#include <cinttypes>

class PhysicBodyDynamic;
class PhysicBodyStatic;
class CollisionCallback;
struct PhysicBodyDef;

class PhysicBodyBase
{
	friend class PhysicWorld;
	friend class PhysicBodyDynamic;
public:
	inline Vector2f GetPosition() const
	{
		return bounds_.center;
	}

	inline float GetPhysicScale() const
	{
		return	physicScale_;
	}
	inline Vector2f GetSize() const
	{
		return bounds_.halfSize;
	};
	inline const FloatRect& GetBounds() const
	{
		return bounds_;
	};
	inline const Vector2f& GetVelocity() const
	{
		return velocity_ * Vector2f(1, physicScale_);
	};
	inline bool IsContaining(const Vector2f& point) const
	{
		return bounds_.IsContaining(point);
	}
	bool IsColliding(const PhysicBodyBase& otherBody) const;
	void IssueCollisionCallback(PhysicBodyBase& otherBody);
	void FinishCollision();
	void AddCollisionIgnoreGroup(int8_t group);
	void RemoveCollisionIgnoreGroup(int8_t group);
	bool IsInGroup(int8_t group) const;
	bool InSameIgnoreGroup(const PhysicBodyBase& otherBody) const;
	inline const std::string& GetCustomId() const
	{
		return customId_;
	}

	virtual void CollideWith(PhysicBodyBase& otherBody) = 0;
	virtual void CollideWithStatic(PhysicBodyStatic& otherBody) = 0;
	virtual void CollideWithDynamic(PhysicBodyDynamic& otherBody) = 0;

	virtual void SetVelocity(const Vector2f& velocity) = 0;
	virtual void SetPhysicScale(float scale) = 0;

protected:
	explicit PhysicBodyBase(const PhysicBodyDef& def);
	virtual ~PhysicBodyBase();

	virtual void Move(const Vector2f& gravity, float seconds) = 0;

	std::string customId_;

	Vector2f velocity_;
	Vector2f velocityNew_;
	Vector2f realVelocity_;
	FloatRect bounds_;
	float physicScale_;
	std::vector<int8_t> collisionIgnoreGroups_;
	bool* collisionSides_;
	CollisionCallback* callback_;
	bool inCallback_;
};

class PhysicBody
{
public:
	enum Type{
		STATIC,
		DYNAMIC
	};
};