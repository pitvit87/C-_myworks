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

void AllLitle(char*& str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = (char)tolower(str[i]);
	}
	cout << str << endl << endl;
}

void AllBig(char*& str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = (char)toupper(str[i]);
	}
	cout << str << endl << endl;
}

void FirstBig(char*& str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (i == 0)
			str[i] = (char)toupper(str[i]);
		else if (i != 0 && isspace(str[i]) && str[i + 1] != '\0')
			str[i+1] = (char)toupper(str[i + 1]);
	}
	cout << str << endl << endl;
}

void FirstLitle(char*& str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (i == 0)
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
		cout << "Select func: (1)Normal, (2)All litle, (3)All big, (4)First big, (5)First litle, (6)Exit\n";
		cin >> choice;

		switch (choice)
		{
		case 1: Normal(str); break;
		case 2: AllLitle(str); break;
		case 3: AllBig(str); break;
		case 4: FirstBig(str); break;
		case 5: FirstLitle(str); break;
		case 6:  job = 0; cout << "Bye! Bye!\n"; break;
		default: cout << "Wrong choice! Try agein!\n"; break;
		}
	} 
	delete[] str;
}
