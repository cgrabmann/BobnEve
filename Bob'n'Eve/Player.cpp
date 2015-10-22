#include "Player.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"


Player::Player(float layer, int32_t id)
	: layer_(layer), id_(id)
{
}

Player::~Player()
{
	
}

void Player::Draw(Renderer* renderer) const
{

}

void Player::Update(int16_t ms)
{
}

int32_t Player::GetId() const
{
	return id_;
}

void Player::setPhysicBody(b2Body* body)
{
	body_ = body;
}