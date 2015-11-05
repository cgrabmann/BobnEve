#include "PhysicsComponentGravity.h"

void PhysicsComponentGravity::Update(GameObject& object, int16_t ms)
{
	//TODO: remove velocity calculation
	if (velocity_->x < 0)
		velocity_->x += 0.1f;
	if (velocity_->x > 0)
		velocity_->x -= 0.1f;
	if (velocity_->x >= -0.05f && velocity_->x <= 0.05f)
		velocity_->x = 0.f;

	//gravity
	velocity_->y += 9.81f * ms / 1000;

	position_->x += velocity_->x;
	position_->y += velocity_->y;
}
