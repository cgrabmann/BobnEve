#include "Player.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"


Player::Player(b2Body* physicsBody, b2Vec2 orientation, InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics)
	: GameObject(physicsBody, orientation, input, physics, graphics)
{

}

Player::Player(InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics)
	: GameObject(input, physics, graphics)
{

}

Player::~Player()
{
	
}

void Player::Update(int16_t ms)
{	
	input_->Update(*this, ms);
	physics_->Update(*this, ms);
	graphics_->Update(*this, ms);
}

void Player::Draw(Renderer& renderer) const
{
	graphics_->Draw(*this, renderer);
}


void Player::Jump()
{
	this->position_.y -= 10;
}

void Player::MoveLeft()
{
	this->position_.x -= 10;
}

void Player::MoveRight()
{
	this->position_.x += 10;
}