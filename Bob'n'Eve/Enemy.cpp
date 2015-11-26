#include "Enemy.h"
#include "View.h"

Enemy::Enemy(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics, size_t enemyId, Vector2f speed)
	: GameObject(input, physics, graphics, speed), enemyId_(enemyId)
{

}

Enemy::~Enemy()
{
	
}

void Enemy::Kill()
{
	View::Instance()->DeleteEnemyById(enemyId_);
}
