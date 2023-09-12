#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

int main()
{
	char str1[] = "This is string!";
	char str2[] = "12i35t";

	cout << "strpbrk = " << strpbrk(str1, str2) << "\n";

}
