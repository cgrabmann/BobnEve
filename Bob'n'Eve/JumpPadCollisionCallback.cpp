#include "Vector2f.h"
#include "PhysicBodyBase.h"
#include "JumpPadCollisionCallback.h"


JumpPadCollisionCallback::JumpPadCollisionCallback() : UpdateableCollisionCallback()
{
}


JumpPadCollisionCallback::~JumpPadCollisionCallback()
{
}

void JumpPadCollisionCallback::collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody)
{
	if (std::find(alreadyBounced.begin(), alreadyBounced.end(), &otherBody) == alreadyBounced.end())
	{
		Vector2f vel = otherBody.GetVelocity();
		vel.y = -vel.y;
		otherBody.SetVelocity(vel);
		alreadyBounced.push_back(&otherBody);
	}
}

void JumpPadCollisionCallback::update(GameObject& object, int16_t ms)
{
	alreadyBounced.clear();
}