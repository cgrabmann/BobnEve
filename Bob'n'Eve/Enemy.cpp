#include "Enemy.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"


Enemy::Enemy(b2Body* physicsBody, b2Vec2* orientation, InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics)
	: GameObject(physicsBody, orientation, input, physics, graphics)
{

}

Enemy::Enemy(InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics)
	: GameObject(input, physics, graphics)
{

}

Enemy::~Enemy()
{
	
}

void Enemy::Draw(Renderer& renderer) const
{

}

void Enemy::Update(int16_t ms)
{

}