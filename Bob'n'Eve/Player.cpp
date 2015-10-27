#include "Player.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "GraphicsComponent.h"


Player::Player(InputComponent* input, PhysicsComponent* physics, GraphicsComponent* graphics)
	: GameObject(), input_(input), physics_(physics), graphics_(graphics)
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