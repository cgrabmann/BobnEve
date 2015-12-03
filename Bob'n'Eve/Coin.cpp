#include "Coin.h"
#include "View.h"

Coin::Coin(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics)
	: GameObject(input, physics, graphics, Vector2f(0,0))
{
}

Coin::~Coin()
{
}
