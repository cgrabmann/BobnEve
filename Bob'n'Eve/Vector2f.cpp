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

sf::Vector2f Vector2f::ToSFML() const
{
	return sf::Vector2f(x, y);
}

b2Vec2 Vector2f::ToBox2D() const
{
	return b2Vec2(x, y);
}

Vector2f Vector2f::operator+(const Vector2f& vec) const
{
	return Vector2f(x + vec.x, y + vec.y);
}

sf::Vector2f Vector2f::operator+(const sf::Vector2f& vec) const
{
	return sf::Vector2f(x + vec.x, y + vec.y);
}

b2Vec2 Vector2f::operator+(const b2Vec2& vec) const
{
	return b2Vec2(x + vec.x, y + vec.y);
}

Vector2f Vector2f::operator-(const Vector2f& vec) const
{
	return Vector2f(x - vec.x, y - vec.y);
}

sf::Vector2f Vector2f::operator-(const sf::Vector2f& vec) const
{
	return sf::Vector2f(x - vec.x, y - vec.y);
}

b2Vec2 Vector2f::operator-(const b2Vec2& vec) const
{
	return b2Vec2(x - vec.x, y - vec.y);
}

Vector2f Vector2f::operator*(const float& mult) const
{
	return Vector2f(x * mult, y * mult);
}

Vector2f Vector2f::operator/(const float& div) const
{
	return Vector2f(x / div, y / div);
}

