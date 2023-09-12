#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

int main()
{
	char str1[] = "aaaaThis is string!";
	char str2[] = "Thos os string!";

	cout << "strspn = " << strspn(str1, str2) << "\n";
	cout << "strcspn = " << strcspn(str1, str2) << "\n";
}
