#include "Map.h"

using utility::Coordinate;
using utility::Math;

Map::Map(utility::Coordinate size)
	: Map(Coordinate(0, 0), Coordinate(size.X - 1, size.Y - 1))
{ }

Map::Map(Coordinate topLeft, Coordinate bottomRight)
	: topLeft(topLeft), bottomRight(validateBottomRight(bottomRight))
{ }

void Map::setMap(Coordinate topLeft, Coordinate bottomRight)
{
	this->topLeft = topLeft;
	setBottomRight(bottomRight);
}

void Map::setTopLeft(Coordinate topLeft)
{
	this->topLeft = validateTopLeft(topLeft);
}

void Map::setBottomRight(Coordinate bottomRight)
{
	this->bottomRight = validateBottomRight(bottomRight);
}

Coordinate Map::getTopLeft() const
{
	return topLeft;
}

Coordinate Map::getBottomRight() const
{
	return bottomRight;
}

Coordinate Map::getTopRight() const
{
	return Coordinate(bottomRight.X, topLeft.Y);
}

Coordinate Map::getBottomLeft() const
{
	return Coordinate(topLeft.X, bottomRight.Y);
}

Coordinate Map::getSize() const
{
	return Coordinate(bottomRight.X - topLeft.X + 1, bottomRight.Y - topLeft.Y + 1);
}

int Map::getTop() const
{
	return topLeft.Y;
}

int Map::getLeft() const
{
	return topLeft.X;
}

int Map::getBottom() const
{
	return bottomRight.Y;
}

int Map::getRight() const
{
	return bottomRight.X;
}

utility::Coordinate Map::validateTopLeft(utility::Coordinate topLeft) const
{
	// Size must not be less than (1, 1)
	// Top-left cannot be more to the right or to the bottom than bottom-right

	if (topLeft.X > bottomRight.X)
		topLeft.X = bottomRight.X;
	if (topLeft.Y > bottomRight.Y)
		topLeft.Y = bottomRight.Y;
	return topLeft;
}

utility::Coordinate Map::validateBottomRight(utility::Coordinate bottomRight) const
{
	// Size must not be less than (1, 1)
	// Bottom-right cannot be more to the left or to the top than top-left

	if (bottomRight.X < topLeft.X)
		bottomRight.X = topLeft.X;
	if (bottomRight.Y < topLeft.Y)
		bottomRight.Y = topLeft.Y;
	return bottomRight;
}