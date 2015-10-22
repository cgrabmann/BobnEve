#include "Platform.h"

#include <SFML/Graphics.hpp>

#include "Renderer.h"


Platform::Platform(float layer, int32_t id)
	: layer_(layer), id_(id)
{
}

Platform::~Platform()
{
	
}

void Platform::Draw(Renderer* renderer) const
{

}

void Platform::Update(int16_t ms)
{
}

int32_t Platform::GetId() const
{
	return id_;
}

void Platform::setPhysicBody(b2Body* body)
{
	body_ = body;
}