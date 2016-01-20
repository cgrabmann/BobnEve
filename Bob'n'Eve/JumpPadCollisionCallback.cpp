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

	if (otherBody.GetCustomId() == "Enemy" || otherBody.GetCustomId() == "EnemyK")
		return;

	float yOffset = thisBody.GetPosition().y - otherBody.GetPosition().y;

	if (yOffset > 0)
	{
		if (standingOnPad.count(&otherBody) == 0)
		{
			standingOnPad[&otherBody] = otherBody.GetVelocity().y;
		}
	}
	else
	{
		if (standingUnderPad.count(&otherBody) == 0)
		{
			standingUnderPad[&otherBody] = otherBody.GetVelocity().y;
		}
	}
	
}

void JumpPadCollisionCallback::update(GameObject& object, int16_t ms)
{
	if (standingOnPad.empty() || standingUnderPad.empty())
	{
		standingOnPad.clear();
		standingUnderPad.clear();
		return;
	}

	float velOn = 0.f;
	float velUnder = 0.f;
	for (std::unordered_map<PhysicBodyBase*, float>::iterator it = standingOnPad.begin(); it != standingOnPad.end(); ++it)
	{
		if (velOn < (*it).second)
			velOn = (*it).second;
	}
	for (std::unordered_map<PhysicBodyBase*, float>::iterator it = standingUnderPad.begin(); it != standingUnderPad.end(); ++it)
	{
		if (velUnder < (*it).second)
			velUnder = (*it).second;

		Vector2f vel = (*it).first->GetVelocity();
		vel.y = -velOn;
		(*it).first->SetVelocity(vel);
	}
	for (std::unordered_map<PhysicBodyBase*, float>::iterator it = standingOnPad.begin(); it != standingOnPad.end(); ++it)
	{
		Vector2f vel = (*it).first->GetVelocity();
		vel.y = -velUnder;
		(*it).first->SetVelocity(vel);
	}

	standingOnPad.clear();
	standingUnderPad.clear();
}