#include "TrampolinCollisionCallback.h"
#include "Vector2f.h"
#include "PhysicBodyBase.h"


TrampolinCollisionCallback::TrampolinCollisionCallback()
{
}


TrampolinCollisionCallback::~TrampolinCollisionCallback()
{
}

void TrampolinCollisionCallback::collidesWith(PhysicBodyBase& otherBody)
{
	if (std::find(alreadyBounced.begin(), alreadyBounced.end(), &otherBody) == alreadyBounced.end())
	{
		Vector2f vel = otherBody.GetVelocity();
		vel.y = -vel.y;
		otherBody.SetVelocity(vel);
		alreadyBounced.push_back(&otherBody);
	}
}

void TrampolinCollisionCallback::update(GameObject& object, int16_t ms)
{
	alreadyBounced.clear();
}