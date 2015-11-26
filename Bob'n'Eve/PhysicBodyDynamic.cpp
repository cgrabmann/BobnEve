#include "PhysicBodyDynamic.h"
#include "PhysicBodyStatic.h"
#include <SFML/include/SFML/Window/Keyboard.hpp>
#include "Global.h"

void PhysicBodyDynamic::SetVelocity(const Vector2f& velocity)
{
	velocity_ = velocity;
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
	velocity_.y += gravity.y * seconds;

	//Friction
	if (velocity_.x < 0)
		velocity_.x += 10.f * seconds;
	if (velocity_.x > 0)
		velocity_.x -= 20.f * seconds;
	if (velocity_.x >= -1.f && velocity_.x <= 1.f)
		velocity_.x = 0.f;

	//Move
	bounds_.center.x += Global::TileWidth * velocity_.x * seconds;
	bounds_.center.y += Global::TileHeight * velocity_.y * seconds * physicScale_;
}

void PhysicBodyDynamic::CollideWithStatic(PhysicBodyStatic& otherBody)
{
	if (InSameIgnoreGroup(otherBody))
		return;

	FloatRect otherBounds = otherBody.GetBounds();
	Vector2f overlap = bounds_.GetOverlap(otherBounds);

	float wy = ((bounds_.halfSize.x + otherBounds.halfSize.x) * 2) * (bounds_.center.y - otherBounds.center.y);
	float hx = ((bounds_.halfSize.y + otherBounds.halfSize.y) * 2) * (bounds_.center.x - otherBounds.center.x);

	if (wy > hx)
		if (wy > -hx)
			/* top */
		{
			overlap.x = 0;
			velocity_.y = 0;
		}
		else
			/* left */
		{
			overlap.y = 0;
			velocity_.x = 0;
		}
	else
		if (wy < -hx)
			/* bottom */
		{
			overlap.x = 0;
			velocity_.y = 0;
		}
		else
			/* right */
		{
			overlap.y = 0;
			velocity_.x = 0;
		}

	bounds_.center -= overlap;
}

void PhysicBodyDynamic::CollideWithDynamic(PhysicBodyDynamic& otherBody)
{
	if (InSameIgnoreGroup(otherBody))
		return;

	FloatRect otherBounds = otherBody.bounds_;
	Vector2f otherVelocity = otherBody.velocity_;

	Vector2f averageVelocity = velocity_ * physicScale_ + otherVelocity * otherBody.physicScale_;
	averageVelocity /= 2;

	Vector2f overlap = bounds_.GetOverlap(otherBounds);
	overlap /= 2;

	float wy = ((bounds_.halfSize.x + otherBounds.halfSize.x) * 2) * (bounds_.center.y - otherBounds.center.y);
	float hx = ((bounds_.halfSize.y + otherBounds.halfSize.y) * 2) * (bounds_.center.x - otherBounds.center.x);

	if (wy > hx)
		if (wy > -hx)
			/* top */
		{
			overlap.x = 0;
			velocity_.y = averageVelocity.y; 
			otherBody.velocity_.y = averageVelocity.y;
		}
		else
			/* left */
		{
			overlap.y = 0;
			velocity_.x = averageVelocity.x;
			otherBody.velocity_.x = averageVelocity.x;
		}
	else
		if (wy < -hx)
			/* bottom */
		{
			overlap.x = 0;
			velocity_.y = averageVelocity.y;
			otherBody.velocity_.y = averageVelocity.y;
		}
		else
			/* right */
		{
			overlap.y = 0;
			velocity_.x = averageVelocity.x;
			otherBody.velocity_.x = averageVelocity.x;
		}

	bounds_.center -= overlap;
	otherBody.bounds_.center += overlap;
}