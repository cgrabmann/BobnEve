#include "Coin.h"
#include "View.h"

Coin::Coin(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics, size_t enemyId)
	: Enemy(input, physics, graphics, enemyId)
{
}

Coin::~Coin()
{
}

void Coin::Kill()
{
	View::Instance()->DeleteEnemy(this);
}
