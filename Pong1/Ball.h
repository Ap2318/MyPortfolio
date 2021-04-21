#pragma once
#include"Coordinate.h"
#include  "Direction.h"
class Ball
{
private:
	utility::Coordinate position;
	Direction direction;
	int score;


public:
	Ball(utility::Coordinate position, Direction direction);
	int getScore();
	void setScore(int score);

	utility::Coordinate getPosition();
	Direction getDirection();


	void move();
	void setDirection(Direction direction);
};

