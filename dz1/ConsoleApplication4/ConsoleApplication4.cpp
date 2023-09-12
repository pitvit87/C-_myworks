#include <iostream>
#pragma warning (disable:4996)
using namespace std;

void AOchange(char*& str)
{
	char* str1 = nullptr;
	int num = strlen(str);
	char ch;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 'a' || str[i] == 'A')
			num++;
		else if (str[i] == 'o' || str[i] == 'O')
			num += 2;
	}
	
	str1 = new char[num];
	int j = 0;
	for (int i = 0; str[i] != '\0';i++)
	{
		if (str[i] == 'a')
		{
			str1[j] = 'a';
			j++;
			str1[j] = 'a';
			j++;
		}
		else if (str[i] == 'A')
		{
			str1[j] = 'A';
			j++;
			str1[j] = 'A';
			j++;
		}
		else if (str[i] == 'o')
		{
			str1[j] = 'o';
			j++;
			str1[j] = 'o';
			j++;
			str1[j] = 'o';
			j++;
		}
		else if (str[i] == 'O')
		{
			str1[j] = 'O';
			j++;
			str1[j] = 'O';
			j++;
			str1[j] = 'O';
			j++;
		}
		else
		{
			str1[j] = str[i];
			j++;
		}
	}
	str1[num] = '\0';
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
	case 1: AOchange(str); break;
	default: cout << "Wrong choice! Try agein!\n"; break;
	}
	
	delete[] str;
}
