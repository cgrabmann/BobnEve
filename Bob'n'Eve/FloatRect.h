#pragma once
#include "Vector2f.h"

class FloatRect
{
public:
	FloatRect() : center(), halfSize() {}
	FloatRect(const float& x, const float& y, const float& width, const float& height) : center(x, y), halfSize(width / 2, height / 2) {}
	FloatRect(Vector2f center, Vector2f halfSize) : center(center), halfSize(halfSize) {}

	Vector2f center;
	Vector2f halfSize;

	bool IsInsersecting(const FloatRect& otherRect) const;

	Vector2f GetOverlap(const FloatRect& otherRect) const;

	enum Direction {
		UP,
		RIGHT,
		DOWN,
		LEFT
	};
};