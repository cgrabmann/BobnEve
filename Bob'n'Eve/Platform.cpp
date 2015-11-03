#include "Platform.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"


Platform::Platform(b2Body* physicsBody, b2Vec2* orientation, InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics)
	: GameObject(physicsBody, orientation, input, physics, graphics)
{

}

Platform::Platform(InputComponentBase* input, PhysicsComponentBase* physics, GraphicsComponentBase* graphics)
	: GameObject(input, physics, graphics)
{

}

Platform::~Platform()
{
	
}

void Platform::Draw(Renderer& renderer) const
{

}

void Platform::Update(int16_t ms)
{

}