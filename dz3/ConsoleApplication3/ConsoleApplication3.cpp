#include <iostream>
#include <iomanip>
#pragma warning(disable: 4996);
using namespace std;

//3.	Написать функцию, которая принимает двумерный массив и делит его на два массива по вертикали по указанному пользователем
//		индексу

void Splitarray(int** mass, int**& mass1, int**& mass2, int index, int hight, int width)
{
	int width1 = width;
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j < index)
				mass1[i][j] = mass[i][j];
			else if (j >= index)
				mass2[i][j - index] = mass[i][j];
		}
	}
}

int main()
{
	srand(time(NULL));
	int hight = 10, width = 10;
	int index;
	
	do
	{
		cout << "Enter split index(2-10):\n";
		cin >> index;
		if (index < 2 || index > 10)
			index = 0;
	} while (index == 0);
	index--;
	int** mass = new int* [hight];
	int** mass1 = new int* [hight];
	int** mass2 = new int* [hight];
	
	for (int i = 0; i < hight; i++)
		mass[i] = new int[width];

	for (int i = 0; i < hight; i++)
		mass1[i] = new int[index];

	for (int i = 0; i < hight; i++)
		mass2[i] = new int[width - index];


	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
			mass[i][j] = rand() % 100;

	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << setw(2) << mass[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	
	Splitarray(mass, mass1, mass2, index, hight, width);

	cout << "New two arrays:\n";

	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < index; j++)
		{
			cout << setw(2) << mass1[i][j] << " ";
		}
		cout << "\t\t";

		for (int j = 0; j < width - index; j++)
		{
			cout << setw(2) << mass2[i][j] << " ";
		}
		cout << endl;
	}
	delete[] mass;
	delete[] mass1;
	delete[] mass2;
}
