#pragma once
#include"Coordinate.h"
class Map
{
private:
	utility::Coordinate topLeft;
	utility::Coordinate bottomRight;

public:
	Map(utility::Coordinate size);
	Map(utility::Coordinate topLeft, utility::Coordinate bottomRight);

	void setMap(utility::Coordinate topLeft, utility::Coordinate bottomRight);
	void setTopLeft(utility::Coordinate topLeft);
	void setBottomRight(utility::Coordinate bottomRight);

	utility::Coordinate getTopLeft() const;
	utility::Coordinate getBottomRight() const;
	utility::Coordinate getTopRight() const;
	utility::Coordinate getBottomLeft() const;
	utility::Coordinate getSize() const;

	int getTop() const;
	int getLeft() const;
	int getBottom() const;
	int getRight() const;

private:
	utility::Coordinate validateTopLeft(utility::Coordinate topLeft) const;
	utility::Coordinate validateBottomRight(utility::Coordinate bottomRight) const;
};

