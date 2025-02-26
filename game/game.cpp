#include <iostream>


#define SIZE 3

using namespace std; // осуждаем!!!!

void displayMenu(char pole[SIZE][SIZE])
{
	cout << "Игра крестики нолики!" << endl;
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			cout << pole[i][j] << " ";
		}
		cout << endl;
	}

}
void start_game(char pole[3][3])
{
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			pole[i][j] = 'Z';
		}


	}
}
void checkXO(char& a)
{
	cout << " Выберети X или O ";
	cin >> a;
	a = toupper(a);
	while (a != 'X' && a != 'O')
	{
		cout << " Выберети X или O ";
		cin >> a;
		a = toupper(a);
	}

}

bool checkCin(char pole[3][3], int& row, int& col, char& num)
{
	while (true)
	{
		cout << "Введети ряд!(0-2)";
		cin >> row;
		cout << "Введети колонку!(0-2)";
		cin >> col;

		if (row > 2 || row < 0 || col < 0|| col > 2 || pole[row][col] != 'Z')
		{
			cout << " видимо где то ошибка  " << endl;
			continue;
		
		}

			pole[row][col] = num;
			cout << "Метка поставилена!";
			displayMenu(pole);
			return true;

	}

}

bool checkWin(char player, char board[3][3]) {
	for (int i = 0; i < SIZE; i++) {
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
			return true;
		}
	}

	for (int i = 0; i < SIZE; i++) {
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
			cout << "Игрок " << player << " выйграл!";
			return true;
		}
	}

	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
		cout << "Игрок " << player << " выйграл!";
		return true;
	}
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
		cout << "Игрок " << player << " выйграл!";
		return true;
	}

	return false;
}
bool isDraw(char pole[3][3]) {
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0;  j < SIZE;  j++)
		{
			if (pole[i][j] == 'Z')
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	setlocale(LC_ALL, "RU");
	
	char game_pole[3][3] = {};
	char player = 0;
	int row = 0,col = 0; 
	start_game(game_pole);
	displayMenu(game_pole);
	checkXO(player);

	while (true)
	{
		if (checkCin(game_pole, row, col, player))
		{
			

			if (checkWin(player,game_pole))
			{
				displayMenu(game_pole);
				break;
			}

			if (isDraw(game_pole))
			{
				displayMenu(game_pole);
				break;
			}
			
			player = (player == 'X') ? 'O' : 'X';// если игрок x то после хода его он будте o
		}

	}


	return 0;
}
