#include "PassThroughCollisionCallback.h"
#include "PhysicBodyBase.h"
#include "PhysicManager.h"


PassThroughCollisionCallback::PassThroughCollisionCallback() : UpdateableCollisionCallback()
{
}


PassThroughCollisionCallback::~PassThroughCollisionCallback()
{
}

void PassThroughCollisionCallback::collidesWith(PhysicBodyBase& thisBody, PhysicBodyBase& otherBody)
{
	if (otherBody.InSameIgnoreGroup(thisBody))
	{
		FloatRect temp = thisBody.GetBounds();
		temp.halfSize.y = temp.halfSize.y / 2;
		dynamics_[&otherBody].ms = 0;
		dynamics_[&otherBody].switchBounds = temp;
	}
}

void PassThroughCollisionCallback::update(GameObject& object, int16_t ms)
{
	std::vector<PhysicBodyBase*> toErase;
	if (!dynamics_.empty())
	{
		for (auto entry = dynamics_.begin(); entry != dynamics_.end(); ++entry)
		{
			PhysicBodyBase* body = (*entry).first;
			GravitySwitchInfo& info = (*entry).second;
			FloatRect temp = info.switchBounds;
			if (!info.switched && temp.IsContaining(body->GetPosition()))
			{
				body->SetPhysicScale(body->GetPhysicScale() * (-1));
				info.switched = true;
			}
			if (info.ms <= 20)
			{
				info.ms += ms;
				if (info.switched)
				{
					Vector2f vel = body->GetVelocity();
					vel.y -= PhysicManager::Instance()->GetGravity().y * float(ms) / 1000;
					body->SetVelocity(vel);
				}
			}
			else
			{
				toErase.push_back((*entry).first);
			}
		}
		for (auto entry : toErase)
		{
			dynamics_.erase(entry);
		}
	}
}