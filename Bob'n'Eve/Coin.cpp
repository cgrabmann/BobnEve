#include "Coin.h"
#include "View.h"

Coin::Coin(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics)
	: GameObject(input, physics, graphics, Vector2f(0,0))
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
		View::Instance()->Destroy(this);
	}
}

void Coin::Kill()
{
	kill_ = true;
}
