#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

void FourDig(char*& pass)
{
	pass = nullptr;
	pass = new char[4];
	int ch = 0;
	for (int i = 0; i <= 4; i++)
	{
		if (i < 4)
		{
			ch = rand() % 10 + 48;
			pass[i] = (char)ch;
		}
		else
			pass[i] = '\0';
	}
	cout << pass << endl;
}

void SixDig(char*& pass)
{
	pass = nullptr;
	int ch = 0;
	int lng = 0;
	cout << "Select long password?(6-12)\n"; 
	do
	{
		cin >> lng;
		if (lng < 6 || lng > 12)
		{
			lng = 0;
			cout << "Wrong choice! Try again!\n";
		}
	} while (lng == 0);
	pass = new char[lng + 1];
	for (int i = 0; i <= lng; i++)
	{
		if (i < lng)
		{
			ch = rand() % 63;
			if (ch >= 0 && ch <= 9)
			{
				pass[i] = (char)(ch + 48);
			}
			else if (ch >= 10 && ch <= 35)
			{
				pass[i] = (char)(ch + 48 + 7);
			}
			else if (ch >= 36 && ch <= 62)
			{
				pass[i] = (char)(ch + 48 + 13);
			}
		}
		else
			pass[i] = '\0';
	}
	cout << pass << endl;
}

void EightDig(char*& pass)
{
	pass = nullptr;
	int ch = 0;
	int lng = 0;
	cout << "Select long password?(8-16)\n";
	do
	{
		cin >> lng;
		if (lng < 8 || lng > 16)
		{
			lng = 0;
			cout << "Wrong choice! Try again!\n";
		}
	} while (lng == 0);
	pass = new char[lng + 1];
	for (int i = 0; i <= lng; i++)
	{
		if (i < lng)
		{
			ch = rand() % 94 + 33;
			pass[i] = (char)ch;
		}
		else
			pass[i] = '\0';
	}
	cout << pass << endl;
}

int main()
{
	srand(time(NULL));
	char* pass = nullptr;
	bool job = 1;
	int choice;
	while (job)
	{
		cout << "Create password?((1) 4 digit,(2) 6-12 symbols, (3) 8-16 symbols,(4) exit)\n";
		cin >> choice;
		switch (choice)
		{
		case 1: FourDig(pass);  break;
		case 2: SixDig(pass);  break;
		case 3: EightDig(pass);  break;
		case 4: job = 0; 
			cout << "Bye! Bye!";
			delete[] pass;
			break;
		default:
			cout << "Wrong choice!";
			break;
		}
	}
}



