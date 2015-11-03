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

b2Vec2 Vector2f::ToBox2D() const
{
	return b2Vec2(x, y);
}

Vector2f Vector2f::operator+(Vector2f vec)
{
	return Vector2f(x + vec.x, y + vec.y);
}

sf::Vector2f Vector2f::operator+(sf::Vector2f vec)
{
	return sf::Vector2f(x + vec.x, y + vec.y);
}

b2Vec2 Vector2f::operator+(b2Vec2 vec)
{
	return b2Vec2(x + vec.x, y + vec.y);
}

Vector2f Vector2f::operator-(Vector2f vec)
{
	return Vector2f(x - vec.x, y - vec.y);
}

sf::Vector2f Vector2f::operator-(sf::Vector2f vec)
{
	return sf::Vector2f(x - vec.x, y - vec.y);
}

b2Vec2 Vector2f::operator-(b2Vec2 vec)
{
	return b2Vec2(x - vec.x, y - vec.y);
}



