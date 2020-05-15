#include <iostream>
#include "game.h"

int main()
{

	setlocale(LC_ALL, "rus");

	char a=0;

	while (a != 'x' && a != '0')
	{
		std::cout << "Choose your character: ";
		std::cin >> a;
	}

	Game game = initGame(a);
	while (!updateGame(&game))
	{
		updateDisplay(game);
		if (game.isUserTurn)
			userTurn(&game);
		else
			botTurn(&game);
		updateDisplay(game);
	}

	switch (game.status)
	{
	case BOT_WIN: 
		std::cout << "The bot won!";
		break;
	case USER_WIN:
		std::cout << "You won!";
		break;
	case NOT_WIN:
		std::cout << "Draw!";
		break;
	default:
		std::cout << "err!";
		break;
	}

}