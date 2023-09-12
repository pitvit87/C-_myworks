#include <iostream>
#pragma warning (disable: 4996)
using namespace std;

int main()
{
	char str1[] = "This is string";
	char chr = 'i';
	cout << "strchr = " << strchr(str1, chr) << "\n";
	cout << strlen(str1) - strlen(strchr(str1, chr)) << "\n";
	cout << "strrchr = " << strrchr(str1, chr) << "\n";
	cout << strlen(str1) - strlen(strrchr(str1, chr)) << "\n";
}
