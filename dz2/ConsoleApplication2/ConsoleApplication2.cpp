#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

int main()
{
	srand(time(NULL));
	int* arr1 = nullptr;
	int* arr2 = nullptr;
	int* arr3 = nullptr;
	int size = 0;
	int size1;
	int size2;
	int index = 0;

	while (size == 0)
	{
		cout << "Enter size(5-20):\n";
		cin >> size;
		if (size < 5 || size > 20)
			size = 0;
	}

	arr1 = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr1[i] = rand() % 100;
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl << endl;
	while (index == 0)
	{
		cout << "Enter separation index(more 2, less (\"size\" - 1)):\n";
		cin >> index;
		if (index < 2 || index > size - 1 )
			index = 0;
	}
	size1 = index;
	size2 = size - size1;
	arr2 = new int[size1];
	arr3 = new int[size2];
	for (int i = 0; i < index; i++)
	{
		arr2[i] = arr1[i];
	}

	for (int i = 0; i < index; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < size2; i++)
	{
		arr3[i] = arr1[i + index];
	}

	for (int i = 0; i < size2; i++)
	{
		cout << arr3[i] << " ";
	}
	cout << endl;

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
}
