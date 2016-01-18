#include "Finish.h"
#include "View.h"


Finish::Finish(InputComponent* input, PhysicsComponentBase* physics, GraphicsComponent* graphics)
	: GameObject(input, physics, graphics)
{
}


Finish::~Finish()
{
}

void Finish::Kill()
{
	View::Instance()->Destroy(this);
}
