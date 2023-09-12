#include <iostream>
#pragma warning(disable: 4996);
using namespace std;

int main()
{
	srand(time(NULL));
	int size1 = 10;
	int size2 = 10;
	int size3 = size1 + size2;
	int* arr1 = nullptr;
	int* arr2 = nullptr;
	arr1 = new int[size1];
	arr2 = new int[size2];
	int* arr3 = nullptr;
	arr3 = new int[size3];
	
	for (int i = 0; i < size1; i++)
	{
		arr1[i] = rand() % 100;
	}

	for (int i = 0; i < size2; i++)
	{
		arr2[i] = rand() % 100;
	}

	for (int i = 0; i < size1; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < size2; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size3; i++)
	{
		if (i < 10)
			arr3[i] = arr1[i];
		else
			arr3[i] = arr2[i - 10];
	}
	cout << endl;

	for (int i = 0; i < size3; i++)
	{
		cout << arr3[i] << " ";
	}
	cout << endl << endl;
	
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
}