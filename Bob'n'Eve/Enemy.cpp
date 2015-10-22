#include "Enemy.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"


Enemy::Enemy(float layer, int32_t id)
	: layer_(layer), id_(id)
{
}

Enemy::~Enemy()
{
	
}

void Enemy::Draw(Renderer* renderer) const
{

}

void Enemy::Update(int16_t ms)
{
}

int32_t Enemy::GetId() const
{
	return id_;
}

void Enemy::setPhysicBody(b2Body* body)
{
	body_ = body;
}