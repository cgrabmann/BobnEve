#pragma once
#include <stddef.h>
#include "PhysicWorld.h"
#include <cstdint>

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

	void Update(int16_t ms);

	void SetGravity(const Vector2f& gravity);
private:
	static PhysicManager* instance_;

	PhysicManager(const Vector2f& gravity);
	~PhysicManager();

	PhysicWorld world_;
	int16_t timeStep_;

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

