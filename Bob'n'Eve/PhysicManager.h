#pragma once

#include <Box2D/Dynamics/b2World.h>

class PhysicsComponent;
class Vector2f;

class PhysicManager
{
public:
	static PhysicManager* Instance();
	static void CreateInstance(const Vector2f& grafity);

	b2Body* CreateBody(b2BodyDef* bodyDef);
	void DestroyBody(b2Body* body);

	void Update(float32 seconds);
private:
	static PhysicManager* instance_;

	PhysicManager(const b2Vec2& gravity);
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

