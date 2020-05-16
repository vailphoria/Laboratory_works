МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе №4<br/> по дисциплине "Программирование"
<br/>

студенти 1 курса группы ПИ-б-о-191(2)  
Забелиной Валерии Павловны
направления подготовки 09.03.04 "Программная инженерия"  
<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>

Симферополь, 2019

## Лабораторная работа №4
Иксики-нолики\
\
**Цель:** 
1. Закрепить навыки работы с перечислениями;
2. Закрепить навыки работы с структурами;
3. Освоить методы составления многофайловых программ.
\
**Ход работы:**\
**1\.** Создаем три файла: 1) Вспомогательный файл(game.cpp), содержащий реализацию основных функций игры. 2) Заголовочный файл  для связи главного и вспомогательного файлов(game.h). 3) Файл реализующий игру «Иксики-нолики» используя функции описанные в вспомогательном файле.\
**2\.** В файле "game.cpp" реализуем функции: initGame для создания игры, updateDisplay для вывода новых ходов, botTurn и userTurn для ходов, updateGame для обновления статуса игры.\

```c++
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
			if (game->board[1][1] == game->userChar)
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
```
**3\.** В файле "game.h" создаем прототипы функций, реализованных в "game.cpp"\

```c++
#pragma once

/* Состояния игры */
enum Status 
{
	PLAY,            // Игра продолжается
	USER_WIN,        // Игрок победил
	BOT_WIN,         // Бот победил
	NOT_WIN          // Ничья. Победителя нет, но и на поле нет свободной ячейки
};

struct Game 
{
	char board[3][3];  // Игровое поле
	bool isUserTurn;  // Чей ход. Если пользователя, то isUserTurn = true
	char userChar;    // Символ которым играет пользователь
	char botChar;     // Символ которым играет бот
	Status status;
};


/**
* Выполняет следующие действия:
*  1. Очищает игровое поле заполняя его пробелами
*  2. Случайным образом определяет чей ход
*  3. Устанавливает символ для Игрока (Задаётся параметром userChar)
*  4. Устанавливает символ для бота
*  5. Возвращает заполненную структуру
*/

Game initGame(char userChar);
/**
* Выполняет следующие действия:
*  1. Очищает экран
*  2. Отображает содержимое игрового поля.
*/

void updateDisplay(const Game game);
/**
* Выполняет ход бота. В выбранную ячейку устанавливается символ которым играет бот.
* Бот должен определять строку, столбец или диагональ в которой у игрока больше всего иксиков/ноликов и ставить туда свой символ.
* Если на поле ещё нет меток, бот должен ставить свой знак в центр. В остальных случаях бот ходит рандомно.
*/

void botTurn(Game* game);
/**
* Функция отвечает за ход игрока. Если игрок вводит не допустимые
* значения, ругнуться и попросить ввести заново
*/

void userTurn(Game* game);
/**
* Функция определяет как изменилось состояние игры после последнего хода.
* Функция сохраняет новое состояние игры в структуре game и передаёт ход другому
* игроку.
* Функция возвращает true, если есть победитель или ничья, иначе false.
*/
bool updateGame(Game* game);
```
**4\.** В функции main в главном файле реализуем игру с помощью написанных ранее функций\

```c++
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
```

![Рис.1 Результат отработки программы](https://raw.githubusercontent.com/vailphoria/Laboratory_works/master/Lab4/images/draw.PNG)\
*рис.1: Результат отработки программы*\
\
**Вывод:** В ходе выполнения данной лабораторной работы приобрела навыки работы с многофайловыми программами и закрепила навыки работы со структурами.
