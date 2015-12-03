#pragma once
#include <SFML/include/SFML/System/Vector2.hpp>

class Vector2f
{
public:
	Vector2f() : x(0), y(0) {}
	explicit Vector2f(const float& x, const float& y) : x(x), y(y) {}
	explicit Vector2f(const sf::Vector2f& vec) : x(vec.x), y(vec.y) {}

	float x;
	float y;

	sf::Vector2f ToSFML() const
	{
		return sf::Vector2f(x, y);
	}
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
	Vector2f out(lVec);
	return out += rVec;
}
inline Vector2f operator+ (const Vector2f& lVec, const sf::Vector2f& rVec)
{
	Vector2f out(lVec);
	return out += rVec;
}
inline sf::Vector2f operator+ (const sf::Vector2f& lVec, const Vector2f& rVec)
{
	sf::Vector2f out(lVec);
	return out += rVec;
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
	Vector2f out(lVec);
	return out += rVec;
}
inline Vector2f operator- (const Vector2f& lVec, const sf::Vector2f& rVec)
{
	Vector2f out(lVec);
	return out += rVec;
}
inline sf::Vector2f operator- (const sf::Vector2f& lVec, const Vector2f& rVec)
{
	sf::Vector2f out(lVec);
	return out += rVec;
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
	Vector2f out(vec);
	return out *= mult;
}
inline Vector2f operator* (const float& mult, const Vector2f& vec)
{
	return (vec * mult);
}
inline Vector2f operator* (const Vector2f& lVec, const Vector2f& rVec)
{
	Vector2f out(lVec);
	return out *= rVec;
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
	Vector2f out(vec);
	return out /= mult;
}
inline Vector2f operator/ (const float& mult, const Vector2f& vec)
{
	return (vec / mult);
}
inline Vector2f operator/ (const Vector2f& lVec, const Vector2f& rVec)
{
	Vector2f out(lVec);
	return out /= rVec;
}
