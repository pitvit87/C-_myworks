#include <iostream>
#include <iomanip>
using namespace std;

/////////////////////
//int** Create(int hight, int width)
//{
//	int** mass = new int* [hight];
//	for (int i = 0; i < hight; i++)
//		mass[i] = new int [width];
//	return mass;
//}
///////////////////

void Create(int**& mass, int hight, int width)
{
	mass = new int* [hight];
	for (int i = 0; i < hight; i++)
		mass[i] = new int[width];
}

void Delete(int** mass, int hight)
{
	for (int i = 0; i < hight; i++)
	{
		delete[] mass[i];
	}
	delete[] mass;
}

void Fill(int** mass, int hight, int width)
{
	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
			mass[i][j] = rand() % 100;
}

void Show(int** mass, int hight, int width)
{
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << setw(2) << mass[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void AddLastCol(int**& mass, int hight, int& width)
{
	int** temp;
	Create(temp, hight, width + 1);
	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
			temp[i][j] = mass[i][j];

	Delete(mass, hight);
	mass = temp;
	for (int i = 0; i < hight; i++)
		mass[i][width] = 0;
	width++;
}

void AddLastRow(int**& mass, int& hight, int width)
{
	int** temp;
	Create(temp, hight + 1, width);
	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
			temp[i][j] = mass[i][j];

	Delete(mass, hight);
	mass = temp;
	for (int i = 0; i < width; i++)
		mass[hight][i] = 0;
	hight++;
}

void AddIndexCol(int**& mass, int hight, int& width, int index)
{
	int** temp;
	Create(temp, hight, width + 1);
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width + 1; j++)
		{
			if (j < index) temp[i][j] = mass[i][j];
			else if (j > index) temp[i][j] = mass[i][j - 1];
		}
	}

	Delete(mass, hight);
	mass = temp;
	for (int i = 0; i < hight; i++)
		mass[i][index] = 0;
	width++;
}

void AddIndexRow(int**& mass, int& hight, int width, int index)
{
	int** temp;
	Create(temp, hight + 1, width);
	for (int i = 0; i < hight + 1; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i < index) temp[i][j] = mass[i][j];
			else if (i > index) temp[i][j] = mass[i - 1][j];
		}
	}

	Delete(mass, hight);
	mass = temp;
	for (int i = 0; i < width; i++)
		mass[index][i] = 0;
	hight++;
}

void AddIndexFewCol(int**& mass, int hight, int& width, int index, int number)
{
	int** temp;
	Create(temp, hight, width + number);
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width + number; j++)
			if (j < index) temp[i][j] = mass[i][j];
			else if (j > index + number - 1) temp[i][j] = mass[i][j - number];
	}

	Delete(mass, hight);
	mass = temp;
	for (int i = 0; i < hight; i++)
		for (int j = index; j < index + number; j++)
			mass[i][j] = 0;
	width += number;
}

void DelLastCol(int**& mass, int hight, int& width)
{
	int** temp;
	Create(temp, hight, width - 1);
	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width - 1; j++)
			temp[i][j] = mass[i][j];

	Delete(mass, hight);
	mass = temp;
	width--;
}

void DelLastRow(int**& mass, int& hight, int width)
{
	int** temp;
	Create(temp, hight - 1, width);
	for (int i = 0; i < hight - 1; i++)
		for (int j = 0; j < width; j++)
			temp[i][j] = mass[i][j];

	Delete(mass, hight);
	mass = temp;
	hight--;
}

void DelIndexCol(int**& mass, int hight, int& width, int index)
{
	int** temp;
	Create(temp, hight, width - 1);
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j < index) temp[i][j] = mass[i][j];
			else if (j > index) temp[i][j - 1] = mass[i][j];
		}
	}
	Delete(mass, hight);
	mass = temp;
	width--;
}

void DelIndexRow(int**& mass, int& hight, int width, int index)
{
	int** temp;
	Create(temp, hight - 1, width);
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i < index) temp[i][j] = mass[i][j];
			else if (i > index) temp[i - 1][j] = mass[i][j];
		}
	}

	Delete(mass, hight);
	mass = temp;
	hight--;
}

void DelIndexFewRow(int**& mass, int& hight, int width, int index, int number)
{
	int** temp;
	Create(temp, hight - number, width);
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i < index) temp[i][j] = mass[i][j];
			else if (i > index + number - 1) temp[i - number][j] = mass[i][j];
		}
	}

	Delete(mass, hight);
	mass = temp;
	hight -= number;
}

int main()
{
	srand(time(NULL));
	int** mass = nullptr;
	int hight, width;
	int choice;
	int number;
	int index;
	bool job = 1;
	do
	{
		cout << "Enter hight:\n"; cin >> hight;
		cout << "Enter width:\n"; cin >> width;
	} while (hight <= 0 || width <= 0);
	//mass = Create(hight, width);
	Create(mass, hight, width);
	Fill(mass, hight, width);
	while (job)
	{
		if (width == 0)
		{
			cout << "Enter your choice\n1 - AddLastCol\n0 - Exit\n";
			cin >> choice;
			if (choice == 1) AddLastCol(mass, hight, width);
			else if (choice == 0) job = 0;
			else cout << "Wrong choice!\n";
		}
		else if (hight == 0)
		{
			cout << "Enter your choice\n1 - AddLastRow\n0 - Exit\n";
			cin >> choice;
			if (choice == 1) AddLastRow(mass, hight, width);
			else if (choice == 0) job = 0;
			else cout << "Wrong choice!\n";
		}
		else
		{
			cout << "Enter choice:\n1 - Show\n2 - AddLastCol\n3 - AddLastRow\n";
			cout << "4 - AddIndexCol\n5 - AddIndexRow\n6 - DelLastCol\n";
			cout << "7 - DelLastRow\n8 - DelIndexCol\n9 - DelIndexRow\n";
			cout << "10 - AddIndexFewCol\n11 - DelIndexFewRow\n";
			cout << "0 - Exit\n";
			cin >> choice;
			switch (choice)
			{
			case 1: Show(mass, hight, width); break;
			case 2: AddLastCol(mass, hight, width); Show(mass, hight, width); break;
			case 3: AddLastRow(mass, hight, width); Show(mass, hight, width); break;
			case 4:
				cout << "Enter index new column:\n"; cin >> index;
				if (index < 0 || index > width)
					cout << "Wrong index!\n";
				else
					AddIndexCol(mass, hight, width, index);
				Show(mass, hight, width);
				break;
			case 5:
				cout << "Enter index new row\n"; cin >> index;
				if (index < 0 || index > hight - 1)
					cout << "Wrong choice!\n";
				else
					AddIndexRow(mass, hight, width, index);
				Show(mass, hight, width);
				break;
			case 6: DelLastCol(mass, hight, width);
				Show(mass, hight, width);
				break;
			case 7: DelLastRow(mass, hight, width);
				Show(mass, hight, width);
				break;
			case 8:
				cout << "Enter index column for delete\n";
				cin >> index;
				if (index < 0 || index > width - 1)
					cout << "Wrong index!\n";
				else DelIndexCol(mass, hight, width, index); Show(mass, hight, width); break;
			case 9:
				cout << "Enter index row for delete\n";
				cin >> index;
				if (index < 0 || index > hight - 1)
					cout << "Wrong index!\n";
				else DelIndexRow(mass, hight, width, index); Show(mass, hight, width); break;
			case 10:
				cout << "Enter index:\n"; cin >> index;
				if (index < 0 || index > width)
					cout << "Wrong index!\n";
				else
				{
					cout << "Enter number:\n"; cin >> number;
					if (number <= 0)
						cout << "Wrong index!\n";
					else
						AddIndexFewCol(mass, hight, width, index, number); Show(mass, hight, width); break;
				}
			case 11:
				cout << "Enter index:\n"; cin >> index;
				if (index < 0 || index > hight - 1)
					cout << "Wrong index!\n";
				else
				{
					cout << "Enter number row for delete:\n";
					cin >> number;
					if (number <= 0 || number + index > hight - 1)
						cout << "Wrong index!\n";
					else
						DelIndexFewRow(mass, hight, width, index, number); Show(mass, hight, width); break;
				}
			case 0: job = 0; cout << "Bay! Bay!"; break;
			default:
				cout << "Wrong choice!\n"; break;
			}
		}
	}
	Delete(mass, hight);
}

