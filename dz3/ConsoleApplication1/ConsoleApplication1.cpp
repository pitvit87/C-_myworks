#include <iostream>
#include <iomanip>
#pragma warning(disable: 4996);
using namespace std;

//1.	Найти максимальный элемент массива и удалить строку и столбец двумерного массива, в которой находится 
//		максимальный элемент

int main()
{
	srand(time(NULL));
	int** mass = nullptr;
	int** temp1 = nullptr;
	int** temp2 = nullptr;
	int hight = 10;
	int width = 10;
	int col = 0;
	int row	= 0;
	int max = 0;
	int choice;

	mass = new int* [hight];

	for (int i = 0; i < hight; i++)
		mass[i] = new int[width];

	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
			mass[i][j] = rand() % 100;

	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << setw(02) << mass[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
		{
			if (max < mass[i][j])
			{
				max = mass[i][j];
				row = i;
				col = j;
			}
		}
		
	cout << endl;
	cout << "Max is = " << max  << endl;
	cout << "Row is = " << row + 1 << endl;
	cout << "Column is = " << col + 1 << endl;
	cout << endl;
	cout << "New array:" << endl;

	temp1 = new int* [hight - 1];

	for (int i = 0; i < hight - 1; i++)
		temp1[i] = new int[width];

	temp2 = new int* [hight - 1];

	for (int i = 0; i < hight - 1; i++)
		temp2[i] = new int[width - 1];

	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
		{
			if (i < row) temp1[i][j] = mass[i][j];
			else if (i > row) temp1[i - 1][j] = mass[i][j];
		}

	for (int i = 0; i < hight - 1; i++)
		for (int j = 0; j < width; j++)
		{
			if (j < col) temp2[i][j] = temp1[i][j];
			else if (j > col) temp2[i][j - 1] = temp1[i][j];
		}

	for (int i = 0; i < hight; i++)
		delete[] mass[i];
	delete[] mass;

	mass = temp2;

	for (int i = 0; i < hight - 1; i++)
	{
		for (int j = 0; j < width - 1; j++)
		{
			cout << setw(02) << mass[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < hight - 1; i++)
		delete[] temp1[i];
	delete[] temp1;

	for (int i = 0; i < hight - 1; i++)
		delete[] mass[i];
	delete[] mass;
}
