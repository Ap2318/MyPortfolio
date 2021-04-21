#include "Game.h"

using namespace utility;

Game::Game() // TODO: Initialize all instance variables
	: map(Coordinate(0,0),Coordinate(30, 25)),
	paddle1(Coordinate(1, 1), Direction::Down),
	paddle2(Coordinate(29, 1), Direction::Down),
	ball(Coordinate(15, 1), Direction::DownRight),
	player1 (),
	player2 (),
	gameOver(false),
	writer(),
	reader()
{ }

void Game::start()
{
	Paddle paddle1 = Paddle(Coordinate(1, 1), Direction::Down);
	Paddle paddle2 = Paddle(Coordinate(28, 1), Direction::Down);
	Ball ball = Ball(Coordinate(15, 1), Direction::Down);
	Map map = Map(Coordinate(0,0),Coordinate(30, 45));
	writer.drawRectangle(Coordinate(0, 0), Coordinate(30, 25));
	player1 = Player();
	player2= Player();


	while (!reader.isEscapePressed())
	{
		update();
		writer.setCursorVisible(false);
		if (gameOver)
		{
			writer.write("Game Over");
			return;
		}
	}
}


void Game::update()
{
	// Keyboard input is updated more frequently than paddle1 movement
	// Keyboard input is updated once every 20 ms (50 fps)
	// Game movement is updated only once every 160 ms (6.25 fps)

	for (int i = 0; i < 7; i++)
	{
		updateGameMovement();
		updateInput();
		Sleep(200); // Sleep for 20 milliseconds
	}

	updateInput();
	updateGameMovement();
	Sleep(20); // Sleep for 20 milliseconds
}

void Game::updateInput()
{
	//ConsoleReader reader = ConsoleReader();
	// TODO
	// If player is pressing any arrow key,
	// then set the paddle1's direction accordingly
	if (reader.isLeftArrowPressed())
	{
		paddle2.setDirection(Direction::Up);
	}
	else if (reader.isRightArrowPressed())
	{
		paddle2.setDirection(Direction::Down);
	}
	else if (reader.isUpArrowPressed())
	{
		paddle1.setDirection(Direction::Up);
	}
	else if (reader.isDownArrowPressed())
	{
		paddle1.setDirection(Direction::Down);
	}

}

void Game::updateGameMovement()
{
	bool reset = false;

	bool increaseScore1 = (ball.getPosition().X <= map.getLeft());
	bool increaseScore2 = (ball.getPosition().X >= map.getRight());

	if (increaseScore1)
	{
		player1.setScore(1);
		writer.write(std::to_string(player1.getScore()));

	}
	else if (increaseScore2)
	{
		player2.setScore(1);
		writer.write(std::to_string(player2.getScore()));
	}


	if (reset)
	{
		gameOver = true;
	}
	else
	{
		writer.setCharacterAtPosition(paddle1.getPosition(), ' ');
		writer.setCharacterAtPosition(paddle2.getPosition(), ' ');
		writer.setCharacterAtPosition(ball.getPosition(), ' ');

		paddle1.move();
		paddle2.move();
		ball.move();
		writer.setCharacterAtPosition(paddle1.getPosition(), '\xB2');
		writer.setCharacterAtPosition(paddle2.getPosition(), '\xB2');
		writer.setCharacterAtPosition(ball.getPosition(), 'o');



	}

	bool bounceGame =
		paddle1.getPosition().Y - 1 <= map.getTop()
		|| paddle1.getPosition().Y + 1 >= map.getBottom();

	bool bounceGame1 = paddle2.getPosition().Y - 1 <= map.getTop()
		|| paddle2.getPosition().Y + 1 >= map.getBottom();

	bool bounceBall = (ball.getPosition().Y - 1 <= map.getTop()
		|| ball.getPosition().Y + 1 >= map.getBottom() || paddle1.getPosition().X + 1 == ball.getPosition().X
		|| paddle2.getPosition().X - 1 == ball.getPosition().X || ball.getPosition().X - 1 <= map.getLeft()
		|| ball.getPosition().X + 1 >= map.getRight());

	if (bounceGame)
	{
		if (paddle1.getDirection() == Direction::Up)
		{
			paddle1.setDirection(Direction::Down);


		}
		else if (paddle1.getDirection() == Direction::Down)
		{
			paddle1.setDirection(Direction::Up);

		}

	}
	if (bounceGame1)
	{
		if (paddle2.getDirection() == Direction::Up)
		{
			paddle2.setDirection(Direction::Down);
		}
		else if (paddle2.getDirection() == Direction::Down)
		{
			paddle2.setDirection(Direction::Up);
		}
	}
	if (bounceBall)
	{

		if (ball.getDirection() == Direction::DownLeft)
		{
			ball.setDirection(Direction::UpLeft);
		}
		else if (ball.getDirection() == Direction::UpLeft)
		{
			ball.setDirection(Direction::UpRight);
		}
		else if (ball.getDirection() == Direction::UpRight)
		{
			ball.setDirection(Direction::DownRight);
		}
		else if (ball.getDirection() == Direction::DownRight)
		{
			ball.setDirection(Direction::DownLeft);
		}
	}
}

	