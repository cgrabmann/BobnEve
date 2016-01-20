#include "PhysicsComponentPlayer.h"
#include "PhysicBodyDef.h"
#include "GameObject.h"

#define PI 3.14159265

const float PhysicsComponentPlayer::cos45 = cos(38.6598 * PI / 180.f);

PhysicsComponentPlayer::PhysicsComponentPlayer(PhysicBodyDef& bodyDef) : PhysicsComponentBase(bodyDef.SetCallback(this)), groundCollision_(false), shouldDie_(false)
{
}


PhysicsComponentPlayer::~PhysicsComponentPlayer()
{
}

void PhysicsComponentPlayer::Update(GameObject& object, int16_t ms)
{
	if (shouldDie_)
	{
		object.Kill();
		return;
	}
	object.SetOnGround(groundCollision_);
	groundCollision_ = false;
}

void PhysicsComponentPlayer::collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody)
{
	if (otherBody.GetCustomId() == "EnemyK")
	{
		shouldDie_ = true;
	}
	float cosAngel = (otherBody.GetPosition() - thisBody.GetPosition()).normalize().dot(Vector2f(0,thisBody.GetPhysicScale()).normalize());
	if (!groundCollision_ &&
		!otherBody.InSameIgnoreGroup(*body_)
		&& otherBody.GetPosition().y * otherBody.GetPhysicScale() > body_->GetPosition().y * body_->GetPhysicScale() // check correct y position
		&& (cosAngel > cos45 || cosAngel < -cos45) // check correct x position
	)
	{
		groundCollision_ = true;
	}
}