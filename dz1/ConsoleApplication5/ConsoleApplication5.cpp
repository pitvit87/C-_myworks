#include <iostream>
#pragma warning (disable:4996)
using namespace std;

void Delspace(char*& str)
{
	char* str1 = nullptr;
	str1 = new char[strlen(str) + 1];
	int j = 0;

	for (int i = 0; str[i] != '\0';)
	{
		if (str[i] == ' ')
			i++;
		else
		{
			str1[j] = str[i];
			j++;
			i++;
		}
	}

	str1[j] = '\0';
	str = nullptr;
	str = new char[strlen(str1) + 1];
	strcpy(str, str1);
	cout << str << endl << endl;
}

int main()
{
	bool job = 0;
	int choice;
	char temp[100];
	char* str = nullptr;

	cout << "Enter string\n";
	cin.getline(temp, 100);
	str = new char[strlen(temp) + 1];
	strcpy(str, temp);
	cout << str << endl;

	cout << "Start func?(1)\n";
	cin >> choice;

	switch (choice)
	{
	case 1: Delspace(str); break;
	default: cout << "Wrong choice! Try agein!\n"; break;
	}

	delete[] str;
}
