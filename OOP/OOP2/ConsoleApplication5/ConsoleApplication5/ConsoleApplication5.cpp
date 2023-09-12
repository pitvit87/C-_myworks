#include <iostream>
using namespace std;

int main()
{
	const int size = 5;
	int arr[size] = { 33,44,7,8,9 };
	int* ptr = arr;

	cout << *ptr << endl;

	cout << *(ptr + 1) << endl;
	//ptr = ptr++;
	cout << *ptr << endl;
	for (int i = 0; i < size; i++)
	{
		cout << *(ptr + i) << " ";
	}
	cout << endl;
	*(ptr + 1) = 55;
	*(ptr + 2) = 12;
	for (int i = 0; i < size; i++)
	{
		cout << *(ptr + i) << " ";
	}
}
