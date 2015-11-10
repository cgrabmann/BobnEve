#pragma once

#include <Box2D/Dynamics/b2World.h>

class PhysicsComponentBase;
class Vector2f;

class PhysicManager
{
public:
	static PhysicManager* Instance();
	static void SetGravity(Vector2f& grafity);

	void createBody(PhysicsComponentBase& gameObject, b2BodyDef* bodyDef);
private:
	static PhysicManager* instance_;
	static b2Vec2 gravity_;

	PhysicManager();
	~PhysicManager();

	b2World world_;

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

