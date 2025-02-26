//V2

#include <iostream>

#define SIZE 3

using namespace std; // осуждаем!!!!



void start_game(char** array, int &rows, int& cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			array[i][j] = 'Z';
		}
	}
}
void displayMenu(char** array, int& rows, int& cols)
{
	cout << "Игра крестики нолики!" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << array[i][j] << " "; // Пример инициализации
		}
		cout << '\n';
	}
}
void checkXO(char& Currplayer)
{
	while (Currplayer != 'X' && Currplayer != 'O')
	{
		cout << " Выберети X или O ";
		cin >> Currplayer;
		Currplayer = toupper(Currplayer);
	}

}
bool checkCin(char** array, int& row, int& col, char& Currplayer,int& rows, int& cols)
{
	while (true)
	{
		cout << "Введети ряд!";
		cin >> row;
		cout << "Введети колонку!";
		cin >> col;

		if (row > rows || row < 0 || col < 0|| col > cols || array[row][col] != 'Z')
		{
			cout << " видимо где то ошибка  " << endl;
			continue;
		
		}

		array[row][col] = Currplayer;
			cout << "Метка поставилена!";
			displayMenu(array, rows, cols);
			return true;

	}

}
bool checkWin(char player, char** board, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) 
			||  board[0][i] == player && board[1][i] == player && board[2][i] == player) { // Вертикали
			cout << "Игрок " << player << " выиграл!" << endl;
			return true;
		}
	}
	if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
		(board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
		cout << "Игрок " << player << " выиграл!" << endl;
		return true;
	}

	return false;
}
bool isDraw(char** array,int rows) {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0;  j < rows;  j++)
		{
			if (array[i][j] == 'Z')
			{
				return false;
			}
		}
	}
	return true;
}
void fillarr(char** arr, int& row, int& col)
{
	
	
}
void deletearr(char** arr, int& rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;
	arr = nullptr;

}


int main()
{	
	setlocale(LC_ALL, "RU");

	int rows = 0, cols = 0;
	char player = 0;
	int row = 0, col = 0;

	cout << "Введите количество строк: ";
	cin >> rows;
	cout << "Введите количество столбцов: ";
	cin >> cols;
	char** game_pole = new char*[rows];

	for (size_t i = 0; i < rows; i++)
	{
		game_pole[i] = new char[cols];
	}

	start_game(game_pole,rows,cols);
	displayMenu(game_pole,rows,cols);
	checkXO(player);

	while (true)
	{
		if (checkCin(game_pole, row, col, player,rows,cols))
		{
			

			if (checkWin(player,game_pole,rows,cols))
			{
				displayMenu(game_pole,rows,cols);
				break;
			}

			if (isDraw(game_pole,rows))
			{
				displayMenu(game_pole,rows,cols);
				break;
			}
			
			player = (player == 'X') ? 'O' : 'X';// если игрок x то после хода его он будте o
		}

	}

	deletearr(game_pole, rows);

	return 0;
}
