#include <iostream>
#include <Windows.h>

using namespace std;

//Nisam se stigao posvetiti drugom zadatku ali ukoliko uspijem posaljem naknadno

const int WEIGHT = 20;
const int HEIGHT = 40;

char grid[WEIGHT][HEIGHT];

int rowA, colA;
int rowB, colB;
int tempRow, tempCol;

void moveR();
void moveC();

void createGrid()
{
	for (int i = 0; i < WEIGHT; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			//if (i == 0 && j == 5)
			//{
			//	grid[i][j] = '|';
			//}
			//else if (i == 1 && j == 5)
			//{
			//	grid[i][j] = '|';
			//}
			//else if (i == 2 && j == 5)
			//{
			//	grid[i][j] = '|';
			//}
			//else if (i == 3 && j == 5)
			//{
			//	grid[i][j] = '|';
			//}
			//else if (i == 4 && j == 5)
			//{
			//	grid[i][j] = '|';
			//}
			//else
			grid[i][j] = '-';
		}
	}

}

void display()
{
	cout << "Unesite red za A: ";
	cin >> rowA;
	cout << "Unesite kolonu za A: ";
	cin >> colA;

	tempRow = rowA;
	tempCol = colA;

	grid[tempRow - 1][tempCol - 1] = '*';
	grid[rowA - 1][colA - 1] = 'A';

	cout << "Unesite red za B: ";
	cin >> rowB;
	cout << "Unesite kolonu za B: ";
	cin >> colB;

	grid[rowB - 1][colB - 1] = 'B';
}

void printGrid()
{
	system("cls");
	for (int i = 0; i < WEIGHT; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			cout << grid[i][j];
		}
		cout << endl;
	}
}

void moveC()
{
	while (tempCol != colB)
	{
		if (tempCol < colB)
		{
			tempCol++;
		}
		else if (tempCol > colB)
		{
			tempCol--;
		}

		grid[tempRow - 1][tempCol - 1] = '*';
		printGrid();
		Sleep(200); //1000 mi je presporo 
	}
}

void moveR()
{
	while (tempRow != rowB)
	{
		if (tempRow < rowB)
		{
			tempRow++;
		}
		else if (tempRow > rowB)
		{
			tempRow--;
		}

		grid[tempRow - 1][tempCol - 1] = '*';
		printGrid();
		Sleep(200);

	}
}

void movement()
{
	moveR();
	moveC();
}

int main()
{
	createGrid();
	display();
	movement();

	return 0;
}