#include <iostream>
#pragma warning(disable: 4996)
using namespace std;



int main()
{
	char str = '5';
	cout << "isalnum = " << isalnum(str) << "\n";
	cout << "isalpha = " << isalpha(str) << "\n";
	cout << "isdigit = " << isdigit(str) << "\n";
	cout << "isspace = " << isspace(str) << "\n";
	cout << "islower = " << islower(str) << "\n";
	cout << "isupper = " << isupper(str) << "\n";
	cout << "tolower = " << (char)tolower(str) << "\n";
	cout << "toupper = " << (char)toupper(str) << "\n";


}
