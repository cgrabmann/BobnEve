#include "GraphicsComponentStatic.h"
#include "Renderer.h"
#include "GameObject.h"


GraphicsComponentStatic::GraphicsComponentStatic(sf::Sprite* sprite) : sprite_(sprite)
{
}


GraphicsComponentStatic::~GraphicsComponentStatic()
{
}

void GraphicsComponentStatic::Update(GameObject& object, int16_t ms)
{
	sprite_->setPosition(object.GetPosition());
}

void GraphicsComponentStatic::Draw(const GameObject& object, Renderer& renderer) const
{
	renderer.GetTarget().draw(*sprite_);
}

