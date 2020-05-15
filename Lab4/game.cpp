#include <iostream>
#include <ctime>
#include "game.h"


Game initGame(char userChar)
{
	srand(time(NULL));
	Game game;

	game.status = PLAY;
	
	game.userChar = userChar;
	if (userChar == 'x')
		game.botChar = '0';
	else
		game.botChar = 'x';

	for (char i = 0; i < 3; i++)
		for (char j = 0; j < 3; j++)
			game.board[i][j] = ' ';

	if (rand() % 2)
	{
		game.isUserTurn = true;
	}
	else
	{
		game.isUserTurn = false;
	}

	
	return game;
}

void updateDisplay(const Game game)
{
	system("cls");

	std::cout << "\ta\tb\tc\n1\t"<<game.board[0][0]<<"\t" << game.board[0][1] << "\t" << game.board[0][2] <<
		"\n2\t" << game.board[1][0] << "\t" << game.board[1][1] << "\t" << game.board[1][2] <<
		"\n3\t" << game.board[2][0] << "\t" << game.board[2][1] << "\t" << game.board[2][2] << "\n";

	return;
}

void botTurn(Game* game)
{
	short num_X=0, num_Y=0, j2=0;

	for (short i = 0; i < 3; i++)
		for (short j = 0; j < 3; j++)
			if (game->board[i][j] != ' ')
				j2++;
	if (j2 == 0)
	{
		game->board[1][1] = game->botChar;
		return;
	}

	j2 = 0;

	for (short i = 0; i < 3; i++)
	{
		if (game->board[i][i] == game->userChar)
			num_X++;
		if (game->board[i][i] == ' ')
		{ 
			num_Y++;
			j2 = i;
		}
	}
	if ( (num_X == 2) && (num_Y == 1) )
	{
		game->board[j2][j2] = game->botChar;
		return;
	}

	num_X = 0;
	num_Y = 0;
	for (short i = 0; i < 3; i++)
	{
		if (game->board[i][2-i] == game->userChar)
			num_X++;
		if (game->board[i][2-i] == ' ')
		{
			num_Y++;
			j2 = i;
		}
	}
	if ((num_X == 2) && (num_Y == 1))
	{
		game->board[j2][2-j2] = game->botChar;
		return;
	}


	for (short i = 0; i < 3; i++)
	{
		num_X = 0;
		num_Y = 0;

		for (short j = 0; j < 3; j++)
		{
			j2 = j;

			if (game->board[i][j] == game->userChar)
			{ 
				num_X++;
				if (num_X == 2)
				{
					j = 2; 

					while (j >= 0)
					{
						if (game->board[i][j] == ' ')
						{
							game->board[i][j] = game->botChar;
							return;
						}

						j--;
					}
				}
				j = j2;
			}

			if (game->board[j][i] == game->userChar)				
			{
				num_Y++;
				if (num_Y == 2)
				{
					j = 2;

					while (j >= 0)
					{
						if (game->board[j][i] == ' ')
						{
							game->board[j][i] = game->botChar;
							return;
						}

						j--;
					}
				}
				j = j2;
			}


		}
	}


	do
	{
		num_X = rand() % 3;
		num_Y = rand() % 3;

		if (game->board[num_X][num_Y] == ' ')
		{
			game->board[num_X][num_Y] = game->botChar;
			return;
		}

	} while (true);

}

void userTurn(Game* game)
{
	char a;
	short b;

	bool wrong = 1;

	std::cout << "User turn, pls enter x, y: ";
	do
	{
		std::cin >> a >> b;
		
		switch (a)
		{
		case 'a': a = 0;
			break;
		case 'b': a = 1;
			break;
		case 'c': a = 2;
			break;
		default:
			std::cout << "wrong a\n";
			break;
		}

		switch (b)
		{
		case 1: b--;
			break;
		case 2: b--;
			break;
		case 3: b--;
			break;
		default:
			std::cout << "wrong b\n";
			break;
		}


		if  (game->board[b][a] == ' ')
			wrong = 0;
		else
			std::cout << "wrong place!\n";


	} while (wrong);

	game->board[b][a] = game->userChar;

}

bool updateGame(Game* game)
{
	for (short i = 0; i < 3; i++)
	{
		if (game->board[i][0] == 'x' || game->board[i][0] == '0')
		{
			if ( (game->board[i][1] == game->board[i][0]) && (game->board[i][2] == game->board[i][0]) )
			{ 
				if (game->board[i][0] == game->userChar)
					game->status = USER_WIN;
				else 
					game->status = BOT_WIN;
				return true;
			}
		}

	
		if (game->board[0][i] == 'x' || game->board[0][i] == '0')
		{
			if ((game->board[1][i] == game->board[0][i]) && (game->board[2][i] == game->board[0][i]))
			{ 
				if (game->board[0][i] == game->userChar)
					game->status = USER_WIN;
				else
					game->status = BOT_WIN;
				return true;
			}
		}
	}

	if (game->board[0][0] == 'x' || game->board[0][0] == '0')
	{
		if ((game->board[1][1] == game->board[0][0]) && (game->board[2][2] == game->board[0][0]))
		{ 
			if (game->board[2][2] == game->userChar)
				game->status = USER_WIN;
			else
				game->status = BOT_WIN;
			return true;
		}
	}
	
	if (game->board[2][0] == 'x' || game->board[2][0] == '0')
	{
		if ((game->board[1][1] == game->board[0][2]) && (game->board[1][1] == game->board[2][0]))
		{ 
			if (game->board[1][1] == game->userChar)
				game->status = USER_WIN;
			else
				game->status = BOT_WIN;
			return true;
		}
	}
	
	

	bool draw = 1;
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
			if (game->board[i][j] == ' ')
				draw = 0;
	}
	if (draw)
	{
		game->status = NOT_WIN;
		return true;
	}

	game->isUserTurn = !game->isUserTurn;
	return false;
}
