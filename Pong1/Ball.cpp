#include "Ball.h"

Ball::Ball(utility::Coordinate position, Direction direction)
	:position(position), direction(direction)
{}


utility::Coordinate	Ball::getPosition()
{
	return position;
}

Direction Ball::getDirection()
{
	return direction;
}

void Ball::move()
{
	if (direction == Direction::Up)
	{
		position.Y -= 1;
	}
	else if (direction == Direction::Down)
	{
		position.Y += 1;
	}
	else if (direction == Direction::Right)
	{
		position.X += 1;
	}
	else if (direction == Direction::Left)
	{
		position.X -= 1;
	}
	else if (direction == Direction::UpLeft)
	{
		position.X--;
		position.Y--;
	}
	else if (direction == Direction::DownLeft)
	{
		position.X--;
		position.Y++;
	}
	else if (direction == Direction::DownRight)
	{
		position.X++;
		position.Y++;
	}
	else if (direction == Direction::UpRight)
	{
		position.X++;
		position.Y--;
	}

}
void Ball::setDirection(Direction direction)
{

	this->direction = direction;
}

int Ball::getScore()
{
	return this->score;
}

void Ball::setScore(int score)
{
	this->score += score;
}
