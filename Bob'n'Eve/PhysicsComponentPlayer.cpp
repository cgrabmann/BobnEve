#include "PhysicsComponentPlayer.h"
#include "PhysicBodyDef.h"
#include "GameObject.h"


PhysicsComponentPlayer::PhysicsComponentPlayer(PhysicBodyDef& bodyDef) : PhysicsComponentBase(bodyDef.SetCallback(this)), groundCollision_(false), gravitySwitched_(false)
{
}


PhysicsComponentPlayer::~PhysicsComponentPlayer()
{
}

void PhysicsComponentPlayer::Update(GameObject& object, int16_t ms)
{
	std::vector<PhysicBodyBase*> toErase;
	/*bool passThroughsWasEmpty_ = true;
	for (auto entry = passThroughs_.begin(); entry != passThroughs_.end(); ++entry)
	{
		if (!object.IsOnGround() && passThroughsWasEmpty_)
			passThroughsWasEmpty_ = false;
		if ((*entry).second <= 20 && !object.IsOnGround())
		{
			(*entry).second += ms;
		}
		else
		{
			toErase.push_back((*entry).first);
		}
	}
	for (auto entry : toErase)
	{
		passThroughs_.erase(entry);
	}
	if (passThroughs_.empty()){
		object.SetOnGround(groundCollision_);
		if (!passThroughsWasEmpty_)
		{
			body_->SetPhysicScale(body_->GetPhysicScale() * (-1));
		}
	}*/
	if (!passThroughs_.empty())
	{
		for (auto entry = passThroughs_.begin(); entry != passThroughs_.end(); ++entry)
		{
			FloatRect temp = (*entry).first->GetBounds();
			temp.halfSize.y = temp.halfSize.y / 4 * 3;
			if (!gravitySwitched_ && temp.IsContaining(body_->GetPosition()))
			{
				gravitySwitched_ = true;
			}
			if ((*entry).second <= 20)
			{
				(*entry).second += ms;
			}
			else
			{
				toErase.push_back((*entry).first);
			}
		}
		for (auto entry : toErase)
		{
			passThroughs_.erase(entry);
		}
	}
	else
	{
		if (gravitySwitched_)
		{
			body_->SetPhysicScale(body_->GetPhysicScale() * (-1));
			gravitySwitched_ = false;
		}
	}
	object.SetOnGround(groundCollision_);
	groundCollision_ = false;
}

void PhysicsComponentPlayer::collidesWith(PhysicBodyBase& otherBody)
{
	if ((otherBody.GetCustomId() == "Platform" || otherBody.GetCustomId() == "Bob" || otherBody.GetCustomId() == "Eve" || otherBody.GetCustomId() == "JumpPad")
		&& otherBody.GetPosition().y * otherBody.GetPhysicScale() > body_->GetPosition().y * body_->GetPhysicScale())
	{
		groundCollision_ = true;
	}
	if (otherBody.GetCustomId() == "PassThrough" && otherBody.InSameIgnoreGroup(*body_))
	{
		passThroughs_[&otherBody] = 0;
	}
}