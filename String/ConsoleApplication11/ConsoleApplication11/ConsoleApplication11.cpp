#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

void Getstring(char*& str)
{
	char temp[100];
	cout << "Enter string\n";
	cin.getline(temp, 100);
	str = new char[strlen(temp) + 1];
	strcpy(str, temp);
}

int main()
{
	char* name;
	char* subname;
	char* pname;
	Getstring(name);
	Getstring(subname);
	Getstring(pname);
	cout << name << " " << subname << " " << pname << ".";
	delete[] name;
	delete[] subname;
	delete[] pname;
}
