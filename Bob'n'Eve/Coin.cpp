#include "Coin.h"
#include "View.h"

Coin::Coin(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics, size_t enemyId)
	: Enemy(input, physics, graphics, enemyId, Vector2f(0,0))
{
}

Coin::~Coin()
{
}

void Coin::Update(int16_t ms)
{
	GameObject::Update(ms);
	if (kill_)
	{
		View::Instance()->DeleteEnemy(this);
	}
}

void Coin::Kill()
{
	kill_ = true;
}
