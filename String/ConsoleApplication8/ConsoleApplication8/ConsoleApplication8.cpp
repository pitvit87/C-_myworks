#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

int main()
{
	int a;
	float b;
	long c;
	char str[] = "56.5";
	a = atoi(str);
	cout << "a = " << a + 10 << "\n";
	b = atof(str);
	cout << "b = " << b << "\n";
	c = atol(str);
	cout << "c = " << c << "\n";
}
