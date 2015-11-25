#pragma once
#include <SFML/include/SFML/System/Vector2.hpp>
#include <Box2D/Box2D.h>

class Vector2f
{
public:
	Vector2f();
	explicit Vector2f(const float& x, const float& y);
	explicit Vector2f(const sf::Vector2f& vec);
	explicit Vector2f(const b2Vec2& vec);
	~Vector2f();

	float x;
	float y;

	b2Vec2 ToBox2D() const;
	sf::Vector2f ToSFML() const;
};

// += Operators
inline Vector2f& operator+= (Vector2f& lVec, const Vector2f& rVec)
{
	lVec.x += rVec.x;
	lVec.y += rVec.y;
	return lVec;
}
inline Vector2f& operator+= (Vector2f& lVec, const sf::Vector2f& rVec)
{
	lVec.x += rVec.x;
	lVec.y += rVec.y;
	return lVec;
}
inline sf::Vector2f& operator+= (sf::Vector2f& lVec, const Vector2f& rVec)
{
	lVec.x += rVec.x;
	lVec.y += rVec.y;
	return lVec;
}

// + Operators
inline Vector2f operator+ (const Vector2f& lVec, const Vector2f& rVec)
{
	return Vector2f(lVec.x + rVec.x, lVec.y + rVec.y);
}
inline Vector2f operator+ (const Vector2f& lVec, const sf::Vector2f& rVec)
{
	return Vector2f(lVec.x + rVec.x, lVec.y + rVec.y);
}
inline sf::Vector2f operator+ (const sf::Vector2f& lVec, const Vector2f& rVec)
{
	return sf::Vector2f(lVec.x + rVec.x, lVec.y + rVec.y);
}

// -= Operators
inline Vector2f& operator-= (Vector2f& lVec, const Vector2f& rVec)
{
	lVec.x -= rVec.x;
	lVec.y -= rVec.y;
	return lVec;
}
inline Vector2f& operator-= (Vector2f& lVec, const sf::Vector2f& rVec)
{
	lVec.x -= rVec.x;
	lVec.y -= rVec.y;
	return lVec;
}
inline sf::Vector2f& operator-= (sf::Vector2f& lVec, const Vector2f& rVec)
{
	lVec.x -= rVec.x;
	lVec.y -= rVec.y;
	return lVec;
}

// - Operators
inline Vector2f operator- (const Vector2f& lVec, const Vector2f& rVec)
{
	return Vector2f(lVec.x - rVec.x, lVec.y - rVec.y);
}
inline Vector2f operator- (const Vector2f& lVec, const sf::Vector2f& rVec)
{
	return Vector2f(lVec.x - rVec.x, lVec.y - rVec.y);
}
inline sf::Vector2f operator- (const sf::Vector2f& lVec, const Vector2f& rVec)
{
	return sf::Vector2f(lVec.x - rVec.x, lVec.y - rVec.y);
}

// *= Operators
inline Vector2f& operator*= (Vector2f& vec, const float& mult)
{
	vec.x *= mult;
	vec.y *= mult;
	return vec;
}
inline Vector2f& operator*= (const float& mult, Vector2f& vec)
{
	return (vec *= mult);
}
inline Vector2f& operator*= (Vector2f& lVec, const Vector2f& rVec)
{
	lVec.x *= rVec.x;
	lVec.y *= rVec.y;
	return lVec;
}

// * Operators
inline Vector2f operator* (const Vector2f& vec, const float& mult)
{
	return Vector2f(vec.x * mult, vec.y * mult);
}
inline Vector2f operator* (const float& mult, const Vector2f& vec)
{
	return vec * mult;
}
inline Vector2f operator* (const Vector2f& lVec, const Vector2f& rVec)
{
	return Vector2f(lVec.x * rVec.x, lVec.y * rVec.y);
}

// /= Operators
inline Vector2f& operator/= (Vector2f& vec, const float& mult)
{
	vec.x /= mult;
	vec.y /= mult;
	return vec;
}
inline Vector2f& operator/= (const float& mult, Vector2f& vec)
{
	return (vec /= mult);
}
inline Vector2f& operator/= (Vector2f& lVec, const Vector2f& rVec)
{
	lVec.x /= rVec.x;
	lVec.y /= rVec.y;
	return lVec;
}

// / Operators
inline Vector2f operator/ (const Vector2f& vec, const float& mult)
{
	return Vector2f(vec.x / mult, vec.y / mult);
}
inline Vector2f operator/ (const float& mult, const Vector2f& vec)
{
	return vec / mult;
}
inline Vector2f operator/ (const Vector2f& lVec, const Vector2f& rVec)
{
	return Vector2f(lVec.x / rVec.x, lVec.y / rVec.y);
}

inline Vector2f& operator/= (Vector2f& vec, float dif){
	vec.x /= dif;
	vec.y /= dif;
	return vec;
}



