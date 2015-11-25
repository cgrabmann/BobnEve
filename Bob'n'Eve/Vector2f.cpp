#pragma once
#include "Vector2f.h"

Vector2f::Vector2f() : x(0), y(0)
{	
}

Vector2f::Vector2f(const float& x, const float& y) : x(x), y(y)
{
}

Vector2f::Vector2f(const sf::Vector2f& vec) : x(vec.x), y(vec.y)
{
}

Vector2f::Vector2f(const b2Vec2& vec) : x(vec.x), y(vec.y)
{
}

Vector2f::~Vector2f()
{	
}

b2Vec2 Vector2f::ToBox2D() const
{
	return b2Vec2(x, y);
}

sf::Vector2f Vector2f::ToSFML() const
{
	return sf::Vector2f(x, y);
}
