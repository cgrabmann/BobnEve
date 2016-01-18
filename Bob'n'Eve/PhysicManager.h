#pragma once
#include <stddef.h>
#include "PhysicWorld.h"

struct PhysicBodyDef;
class PhysicBodyBase;
class PhysicsComponentBase;
class Vector2f;

class PhysicManager
{
public:
	static PhysicManager* Instance();
	static void CreateInstance(const Vector2f& grafity);

	PhysicBodyBase* CreateBody(const PhysicBodyDef& bodyDef);
	void DestroyBody(PhysicBodyBase& body);

	void Update(float ms);

	void SetGravity(const Vector2f& gravity);
	inline const Vector2f& GetGravity() const
	{
		return world_.GetGravity();
	}

private:
	static PhysicManager* instance_;

	PhysicManager(const Vector2f& gravity);
	~PhysicManager();

	PhysicWorld world_;

	class CGuard
	{
	public:
		~CGuard()
		{
			if (NULL != PhysicManager::instance_)
			{
				delete PhysicManager::instance_;
				PhysicManager::instance_ = NULL;
			}
		}
	};
};

