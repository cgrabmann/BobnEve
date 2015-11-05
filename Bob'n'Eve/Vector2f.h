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



