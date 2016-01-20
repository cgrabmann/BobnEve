#include "Enemy.h"
#include "Map.h"

Enemy::Enemy(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics, size_t enemyId, Vector2f speed)
	: GameObject(input, physics, graphics, speed), enemyId_(enemyId)
{

}

Enemy::~Enemy()
{
	
}

void Enemy::Update(int16_t ms)
{
	if (IsOnGround())
	{
		Up();
	}
	GameObject::Update(ms);
}

void Enemy::Kill()
{
	Map::Instance()->Destroy(this);
}
