#pragma once
#include <SFML/include/SFML/System/Vector2.hpp>
#include <Box2D/Box2D.h>

class Vector2f
{
public:
	Vector2f();
	Vector2f(const float& x, const float& y);
	Vector2f(const sf::Vector2f& vec);
	Vector2f(const b2Vec2& vec);
	~Vector2f();

	float x;
	float y;

	sf::Vector2f ToSFML() const;
	b2Vec2 ToBox2D() const;
};


Vector2f inline operator+ (const Vector2f& lVec, const Vector2f& rVec)
{
	return Vector2f(lVec.x + rVec.x, lVec.y + rVec.y);
}
sf::Vector2f inline operator+ (const Vector2f& lVec, const sf::Vector2f& rVec)
{
	return sf::Vector2f(lVec.x + rVec.x, lVec.y + rVec.y);
}
sf::Vector2f inline operator+ (const sf::Vector2f& lVec, const Vector2f& rVec)
{
	return sf::Vector2f(lVec.x + rVec.x, lVec.y + rVec.y);
}
b2Vec2 inline operator+ (const Vector2f& lVec, const b2Vec2& rVec)
{
	return b2Vec2(lVec.x + rVec.x, lVec.y + rVec.y);
}
b2Vec2 inline operator+ (const b2Vec2& lVec, const Vector2f& rVec)
{
	return b2Vec2(lVec.x + rVec.x, lVec.y + rVec.y);
}

Vector2f inline operator- (const Vector2f& lVec, const Vector2f& rVec)
{
	return Vector2f(lVec.x - rVec.x, lVec.y - rVec.y);
}
sf::Vector2f inline operator- (const Vector2f& lVec, const sf::Vector2f& rVec)
{
	return sf::Vector2f(lVec.x - rVec.x, lVec.y - rVec.y);
}
sf::Vector2f inline operator- (const sf::Vector2f& lVec, const Vector2f& rVec)
{
	return sf::Vector2f(lVec.x - rVec.x, lVec.y - rVec.y);
}
b2Vec2 inline operator- (const Vector2f& lVec, const b2Vec2& rVec)
{
	return b2Vec2(lVec.x - rVec.x, lVec.y - rVec.y);
}
b2Vec2 inline operator- (const b2Vec2& lVec, const Vector2f& rVec)
{
	return b2Vec2(lVec.x - rVec.x, lVec.y - rVec.y);
}

Vector2f inline operator* (const Vector2f& vec, const float& mult)
{
	return Vector2f(vec.x * mult, vec.y * mult);
}
Vector2f inline operator* (const float& mult, const Vector2f& vec)
{
	return Vector2f(vec.x * mult, vec.y * mult);
}

Vector2f inline operator/ (const Vector2f& vec, const float& mult)
{
	return Vector2f(vec.x / mult, vec.y / mult);
}
Vector2f inline operator/ (const float& mult, const Vector2f& vec)
{
	return Vector2f(vec.x / mult, vec.y / mult);
}



