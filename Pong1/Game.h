#pragma once
#include "Console.h"
#include "ConsoleWriter.h"
#include "ConsoleReader.h"
#include "Map.h"
#include"Ball.h"
#include"Paddle.h"
#include"Direction.h"
#include"Player.h"
class Game
{
private:
	Map map;
	Paddle paddle1;
	Paddle	paddle2;
	Ball ball;
	Player player1;
	Player player2;
	bool gameOver;

	utility::ConsoleWriter writer;
	utility::ConsoleReader reader;

public:
	Game();
	void start();

private:
	void update();
	void updateInput();
	void updateGameMovement();
};

