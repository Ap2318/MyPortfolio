#pragma once
#include"Coordinate.h"
#include "Direction.h"
class Paddle
{
private:
	utility::Coordinate position;
	Direction direction;
	int score;


public:
	Paddle(utility::Coordinate position, Direction direction);
	int getScore();
	void setScore(int score);

	utility::Coordinate getPosition();
	Direction getDirection();


	void move();
	void setDirection(Direction direction);
};

