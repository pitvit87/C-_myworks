#include <iostream>
#pragma warning (disable:4996)
using namespace std;

void Normal(char*& str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (i == 0)
			str[i] = (char)toupper(str[i]);
		else
			str[i] = (char)tolower(str[i]);
	}
	cout << str << endl << endl;
}

void Ugly(char*& str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (i % 2 == 0)
		str[i] = (char)tolower(str[i]);
		else
		str[i] = (char)toupper(str[i]);
	}
	cout << str << endl << endl;
}

int main()
{
	bool job = 1;
	int choice;
	char temp[100];
	char* str = nullptr;

	cout << "Enter string\n";
	cin.getline(temp, 100);
	str = new char[strlen(temp) + 1];
	strcpy(str, temp);
	cout << str << endl;

	while (job)
	{
		cout << "Select func: (1)Normal text, (2)Ugly text, (3)Exit\n";
		cin >> choice;

		switch (choice)
		{
		case 1: Normal(str); break;
		case 2: Ugly(str); break;
		case 3: job = 0; cout << "Bye! Bye!\n";  break;
		default: cout << "Wrong choice! Try agein!\n"; break;
		}
	}
	delete[] str;
}