#include "Player.h"

Player::Player()
{
	this->score =0;

}

int Player::getScore()
{
	return this->score;
}

void Player::setScore(int score)
{
	this->score += score;
}
