#include "Finish.h"
#include "Map.h"


Finish::Finish(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics)
	: GameObject(input, physics, graphics)
{
}


Finish::~Finish()
{
}

void Finish::Kill()
{
	Map::Instance()->Destroy(this);
}

void Finish::Update(int16_t ms)
{
	GameObject::Update(ms);
}
