#pragma once
#include <SFML/include/SFML/System/Vector2.hpp>
#include <Box2D/Box2D.h>

class Vector2f
{
public:
	Vector2f();
	Vector2f(float x, float y);
	Vector2f(sf::Vector2f vec);
	Vector2f(b2Vec2 vec);
	~Vector2f();

	float x;
	float y;

	sf::Vector2f ToSFML() const;
	b2Vec2 ToBox2D() const;

	Vector2f operator+ (Vector2f vec);
	sf::Vector2f operator+ (sf::Vector2f vec);
	b2Vec2 operator+ (b2Vec2 vec);

	Vector2f operator- (Vector2f vec);
	sf::Vector2f operator- (sf::Vector2f vec);
	b2Vec2 operator- (b2Vec2 vec);
};

