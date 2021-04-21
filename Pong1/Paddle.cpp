#include "Paddle.h"

Paddle::Paddle(utility::Coordinate position, Direction direction)
	:position(position), direction(direction)
{}


utility::Coordinate	Paddle::getPosition()
{
	return position;
}

Direction Paddle::getDirection()
{
	return direction;
}

void Paddle::move()
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
void Paddle::setDirection(Direction direction)
{

	this->direction = direction;
}

int Paddle::getScore()
{
	return this->score;
}

void Paddle::setScore(int score)
{
	this->score += score;
}