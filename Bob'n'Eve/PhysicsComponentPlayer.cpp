#include "PhysicsComponentPlayer.h"
#include "PhysicBodyDef.h"
#include "GameObject.h"
#include "PhysicManager.h"


PhysicsComponentPlayer::PhysicsComponentPlayer(PhysicBodyDef& bodyDef) : PhysicsComponentBase(bodyDef.SetCallback(this)), groundCollision_(false), gravitySwitched_(false), shouldDie_(false), lastUpdateMs_(0)
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
	std::vector<PhysicBodyBase*> toErase;
	lastUpdateMs_ = ms;
	if (!passThroughs_.empty())
	{
		for (auto entry = passThroughs_.begin(); entry != passThroughs_.end(); ++entry)
		{
			FloatRect temp = (*entry).first->GetBounds();
			temp.halfSize.y = temp.halfSize.y / 2;
			if (!gravitySwitched_ && temp.IsContaining(body_->GetPosition()))
			{
				body_->SetPhysicScale(body_->GetPhysicScale() * (-1));
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
		if (gravitySwitched_)
		{
			Vector2f vel = GetVelocity();
			vel.y -= PhysicManager::Instance()->GetGravity().y * float(ms) / 1000;
			SetVelocity(vel);
		}
	}
	else
	{
		if (gravitySwitched_)
		{
			gravitySwitched_ = false;
		}
	}
	object.SetOnGround(groundCollision_);
	groundCollision_ = false;
}

void PhysicsComponentPlayer::collidesWith(PhysicBodyBase& otherBody)
{
	if (otherBody.GetCustomId() == "Enemyk")
	{
		shouldDie_ = true;
	}
	if (!otherBody.InSameIgnoreGroup(*body_)
		&& otherBody.GetPosition().y * otherBody.GetPhysicScale() > body_->GetPosition().y * body_->GetPhysicScale())
	{
		groundCollision_ = true;
	}
	if (otherBody.GetCustomId() == "PassThrough" && otherBody.InSameIgnoreGroup(*body_))
	{
		passThroughs_[&otherBody] = 0;
	}
}