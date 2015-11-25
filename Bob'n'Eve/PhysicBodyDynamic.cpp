#include "PhysicBodyDynamic.h"
#include "PhysicBodyStatic.h"

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
	position_.x += velocity_.x * seconds;
	position_.y += velocity_.y * seconds;

	position_.x += gravity.x * seconds;
	position_.y += gravity.y * seconds * physicScale_;
}

void PhysicBodyDynamic::CollideWithStatic(PhysicBodyStatic& otherBody)
{
	if (InSameIgnoreGroup(otherBody))
		return;

	const Vector2f& otherPos = otherBody.GetPosition();
	const Vector2f& otherHalfSize = otherBody.GetHalfSize();

	if (IsCollidingY(otherBody)){
		//y
		if (velocity_.y * physicScale_ > 0)
			position_.y = otherPos.y - otherHalfSize.y - halfSize_.y;
		else if (velocity_.y * physicScale_ < 0)
			position_.y = otherPos.y + otherHalfSize.y + halfSize_.y;
		//gravity
		else if (physicScale_ > 0)
			position_.y = otherPos.y - otherHalfSize.y - halfSize_.y;
		else
			position_.y = otherPos.y + otherHalfSize.y + halfSize_.y;
		velocity_.y = 0;
	}
	else
	{
		//x
		if (velocity_.x > 0)
			position_.x = otherPos.x - otherHalfSize.x - halfSize_.x;
		else if (velocity_.x < 0)
			position_.x = otherPos.x + otherHalfSize.x + halfSize_.x;
		velocity_.x = 0;
	}
}

void PhysicBodyDynamic::CollideWithDynamic(PhysicBodyDynamic& otherBody)
{
	if (InSameIgnoreGroup(otherBody))
		return;

	Vector2f& otherPos = otherBody.position_;
	Vector2f& otherVel = otherBody.velocity_;
	const Vector2f& otherHalfSize = otherBody.GetHalfSize();

	//x
	if (velocity_.x > 0)
		position_.x = otherPos.x - otherHalfSize.x - halfSize_.x;
	else if (velocity_.x < 0)
		position_.x = otherPos.x + otherHalfSize.x + halfSize_.x;
	velocity_.x = 0;

	//y
	if (velocity_.y * physicScale_ > 0)
		position_.y = otherPos.y - otherHalfSize.y - halfSize_.y;
	else if(velocity_.y * physicScale_ < 0)
		position_.y = otherPos.y + otherHalfSize.y + halfSize_.y;
	velocity_.y = 0;


	Vector2f velAvg = velocity_ + otherVel;
	velAvg /= 2;
	velocity_ = velAvg;
	otherVel = velAvg;
}