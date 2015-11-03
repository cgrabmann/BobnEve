#pragma once
#include "Vector2f.h"

Vector2f::Vector2f() : x(0), y(0)
{	
}

Vector2f::Vector2f(float x, float y) : x(x), y(y)
{
}

Vector2f::Vector2f(sf::Vector2f vec) : x(vec.x), y(vec.y)
{
}

Vector2f::Vector2f(b2Vec2 vec) : x(vec.x), y(vec.y)
{
}

Vector2f::~Vector2f()
{	
}

sf::Vector2f Vector2f::ToSFML() const
{
	return sf::Vector2f(x, y);
}

b2Vec2 Vector2f::ToB2Vec() const
{
	return b2Vec2(x, y);
}


