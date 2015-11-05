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

Vector2f operator+ (const Vector2f& lVec, const Vector2f& rVec)
{
	return Vector2f(lVec.x + rVec.x, lVec.y + rVec.y);
}
sf::Vector2f operator+ (const Vector2f& lVec, const sf::Vector2f& rVec)
{
	return sf::Vector2f(lVec.x + rVec.x, lVec.y + rVec.y);
}
sf::Vector2f operator+ (const sf::Vector2f& lVec, const Vector2f& rVec)
{
	return sf::Vector2f(lVec.x + rVec.x, lVec.y + rVec.y);
}
b2Vec2 operator+ (const Vector2f& lVec, const b2Vec2& rVec)
{
	return b2Vec2(lVec.x + rVec.x, lVec.y + rVec.y);
}
b2Vec2 operator+ (const b2Vec2& lVec, const Vector2f& rVec)
{
	return b2Vec2(lVec.x + rVec.x, lVec.y + rVec.y);
}

Vector2f operator- (const Vector2f& lVec, const Vector2f& rVec)
{
	return Vector2f(lVec.x - rVec.x, lVec.y - rVec.y);
}
sf::Vector2f operator- (const Vector2f& lVec, const sf::Vector2f& rVec)
{
	return sf::Vector2f(lVec.x - rVec.x, lVec.y - rVec.y);
}
sf::Vector2f operator- (const sf::Vector2f& lVec, const Vector2f& rVec)
{
	return sf::Vector2f(lVec.x - rVec.x, lVec.y - rVec.y);
}
b2Vec2 operator- (const Vector2f& lVec, const b2Vec2& rVec)
{
	return b2Vec2(lVec.x - rVec.x, lVec.y - rVec.y);
}
b2Vec2 operator- (const b2Vec2& lVec, const Vector2f& rVec)
{
	return b2Vec2(lVec.x - rVec.x, lVec.y - rVec.y);
}

Vector2f operator* (const Vector2f& vec, const float& mult)
{
	return Vector2f(vec.x * mult, vec.y * mult);
}
Vector2f operator* (const float& mult, const Vector2f& vec)
{
	return Vector2f(vec.x * mult, vec.y * mult);
}

Vector2f operator/ (const Vector2f& vec, const float& mult)
{
	return Vector2f(vec.x / mult, vec.y / mult);
}
Vector2f operator/ (const float& mult, const Vector2f& vec)
{
	return Vector2f(vec.x / mult, vec.y / mult);
}
