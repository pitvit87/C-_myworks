#include <iostream>
#include <iomanip>
#pragma warning(disable: 4996);
using namespace std;
 
//2.	Реализовать сдвиг всех элементов двумерного массива влево / вправо на указанное кол - во шагов

int main()
{
	srand(time(NULL));
	int hight = 10, width = 10;
	int number, step = 0;
	int choice;
	bool job = 1;

	int** mass = new int* [hight];
	for (int i = 0; i < hight; i++)
		mass[i] = new int[width];

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
	while (job)
	{
		do
		{
			cout << "Enter direction((1) Left, (2) Right):\n";
			cin >> choice;
			if (choice < 1 || choice > 2)
			{
				choice = 0;
				cout << "Wrong choice!\n";
			}
			else if (choice == 1)
			{
				step = 101;
				cout << "Enter move count:\n";
				cin >> number;
			}
			else if (choice == 2)
			{
				step = 99;
				cout << "Enter move count:\n";
				cin >> number;
			}
		} while (choice == 0);
		
		for (int g = 0; g < step; g++)
		{
			for (int y = 0; y < number; y++)
			{
				for (int i = 0; i < hight; i++)
				{
					for (int j = 0; j < width; j++)
					{
						if (j != width - 1)
							swap(mass[i][j], mass[i][j + 1]);
						else if (j == width - 1 && i != hight - 1)
							swap(mass[i][width - 1], mass[i + 1][0]);
					}
				}
			}
		}

		choice = 0;
		number = 0;
		step = 0;

		cout << "New array:\n";
		for (int i = 0; i < hight; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << setw(2) << mass[i][j] << " ";
			}
			cout << endl;
		}
	}
}