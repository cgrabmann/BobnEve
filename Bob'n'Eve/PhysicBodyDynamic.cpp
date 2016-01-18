#include "PhysicBodyDynamic.h"
#include "PhysicBodyStatic.h"
#include "Global.h"
#include "PhysicBodyDef.h"

void PhysicBodyDynamic::SetVelocity(const Vector2f& velocity)
{
	if (inCallback_)
	{
		velocityNew_ = velocity * Vector2f(1, physicScale_);
	} else
	{
		velocity_ = velocity * Vector2f(1, physicScale_);
	}
}

void PhysicBodyDynamic::SetPhysicScale(float scale)
{
	physicScale_ = scale;
}

PhysicBodyDynamic::PhysicBodyDynamic(const PhysicBodyDef& def) : PhysicBodyBase(def)
{
}

PhysicBodyDynamic::~PhysicBodyDynamic()
{
}

void PhysicBodyDynamic::Move(const Vector2f& gravity, float seconds)
{
	//Gravity
	velocity_.x += gravity.x * seconds;
	velocity_.y += gravity.y * seconds * physicScale_;

	//Friction
	if (velocity_.x < 0)
		velocity_.x += 10.f * seconds;
	if (velocity_.x > 0)
		velocity_.x -= 20.f * seconds;
	if (velocity_.x >= -1.f && velocity_.x <= 1.f)
		velocity_.x = 0.f;

	//Move
	bounds_.center.x += Global::TileWidth * velocity_.x * seconds;
	bounds_.center.y += Global::TileHeight * velocity_.y * seconds;
}

void PhysicBodyDynamic::CollideWithStatic(PhysicBodyStatic& otherBody)
{
	if (InSameIgnoreGroup(otherBody))
		return;

	velocityNew_ = velocity_;

	FloatRect otherBounds = otherBody.GetBounds();
	Vector2f overlap = bounds_.GetOverlap(otherBounds);

	float wy = (bounds_.halfSize.x + otherBounds.halfSize.x) * (bounds_.center.y - otherBounds.center.y);
	float hx = (bounds_.halfSize.y + otherBounds.halfSize.y) * (bounds_.center.x - otherBounds.center.x);

	if (wy > hx)
		if (wy > -hx)
			/* top */
		{
			if (!otherBody.collisionSides_[Sides::Bottom])
				return;

			overlap.x = 0;
			velocityNew_.y = 0;
		}
		else
			/* right */
		{
			if (!otherBody.collisionSides_[Sides::Left])
				return;

			overlap.y = 0;
			velocityNew_.x = 0;
		}
	else
		if (wy < -hx)
			/* bottom */
		{
			if (!otherBody.collisionSides_[Sides::Top])
				return;

			overlap.x = 0;
			velocityNew_.y = 0;
		}
		else
			/* left */
		{
			if (!otherBody.collisionSides_[Sides::Right])
				return;

			overlap.y = 0;
			velocityNew_.x = 0;
		}

	bounds_.center -= overlap;
}

void PhysicBodyDynamic::CollideWithDynamic(PhysicBodyDynamic& otherBody)
{
	if (InSameIgnoreGroup(otherBody))
		return;

	FloatRect otherBounds = otherBody.bounds_;
	otherBody.velocityNew_ = otherBody.velocity_;
	velocityNew_ = velocity_;

	Vector2f averageVelocity = velocityNew_ + otherBody.velocityNew_;
	averageVelocity /= 2;

	Vector2f overlap = bounds_.GetOverlap(otherBounds);
	overlap /= 2;

	float wy = (bounds_.halfSize.x + otherBounds.halfSize.x) * (bounds_.center.y - otherBounds.center.y);
	float hx = (bounds_.halfSize.y + otherBounds.halfSize.y) * (bounds_.center.x - otherBounds.center.x);

	if (wy > hx)
		if (wy > -hx)
			/* top */
		{
			if (!otherBody.collisionSides_[Sides::Bottom])
				return;

			overlap.x = 0;
			velocityNew_.y = averageVelocity.y;
			otherBody.velocityNew_.y = averageVelocity.y;
		}
		else
			/* right */
		{
			if (!otherBody.collisionSides_[Sides::Left])
				return;

			overlap.y = 0;
			velocityNew_.x = averageVelocity.x;
			otherBody.velocityNew_.x = averageVelocity.x;
		}
	else
		if (wy < -hx)
			/* bottom */
		{
			if (!otherBody.collisionSides_[Sides::Top])
				return;

			overlap.x = 0;
			velocityNew_.y = averageVelocity.y;
			otherBody.velocityNew_.y = averageVelocity.y;
		}
		else
			/* left */
		{
			if (!otherBody.collisionSides_[Sides::Right])
				return;

			overlap.y = 0;
			velocityNew_.x = averageVelocity.x;
			otherBody.velocityNew_.x = averageVelocity.x;
		}

	bounds_.center -= overlap;
	otherBody.bounds_.center += overlap;
}