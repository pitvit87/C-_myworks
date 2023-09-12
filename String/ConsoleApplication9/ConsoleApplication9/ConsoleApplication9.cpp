#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

int main()
{
	char str[] = "This is:string/again";
	cout << strtok(str, " :/") << "\n";
	cout << strtok(NULL, ": /") << "\n";
	cout << strtok(NULL, " :/") << "\n";
	cout << strtok(NULL, ":/ ") << "\n";
}


