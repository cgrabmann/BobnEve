#include "PhysicsComponentPlayer.h"
#include "PhysicBodyDef.h"
#include "GameObject.h"


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
	if (otherBody.GetCustomId() == "Enemyk")
	{
		shouldDie_ = true;
	}
	float cosAngel = (otherBody.GetPosition() - thisBody.GetPosition()).dot(Vector2f(0,thisBody.GetPhysicScale()));
	if (!groundCollision_ &&
		!otherBody.InSameIgnoreGroup(*body_)
		&& otherBody.GetPosition().y * otherBody.GetPhysicScale() > body_->GetPosition().y * body_->GetPhysicScale() // check correct y position
		//&& cosAngel > -0.707 && cosAngel < 0.707 // check correct x position
	)
	{
		groundCollision_ = true;
	}
}