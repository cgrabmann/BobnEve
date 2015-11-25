#include "Enemy.h"
#include "View.h"

Enemy::Enemy(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics, size_t enemyId)
	: GameObject(input, physics, graphics), enemyId_(enemyId)
{

}

Enemy::~Enemy()
{
	
}

void Enemy::Kill()
{
	View::Instance()->DeleteEnemyById(enemyId_);
}
