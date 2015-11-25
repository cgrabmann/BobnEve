#include "FloatRect.h"
#include <cmath>


bool FloatRect::IsInsersecting(const FloatRect& otherRect) const
{
	return (abs(center.x - otherRect.center.x) < halfSize.x + otherRect.halfSize.x) &&
		(abs(center.y - otherRect.center.y) < halfSize.y + otherRect.halfSize.y);
}

Vector2f FloatRect::GetOverlap(const FloatRect& otherRect) const
{
	Vector2f overlap(0, 0);

	//collided this-left
	if (center.x < otherRect.center.x)
	{
		overlap.x = (center.x + halfSize.x) - (otherRect.center.x - otherRect.halfSize.x);
	}
	else
	{
		overlap.x = (center.x - halfSize.x) - (otherRect.center.x + otherRect.halfSize.x);
	}

	if (center.y < otherRect.center.y)
	{
		overlap.y = (center.y + halfSize.y) - (otherRect.center.y - otherRect.halfSize.y);
	}
	else
	{
		overlap.y = (center.y - halfSize.y) - (otherRect.center.y + otherRect.halfSize.y);
	}

	return overlap;
}
