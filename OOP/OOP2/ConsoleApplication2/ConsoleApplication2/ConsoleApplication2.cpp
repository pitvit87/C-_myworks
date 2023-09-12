#include <iostream>
using namespace std;

int main()
{
	const char* s1 = "abcd";
	char* s2 = nullptr;

	int len = strlen(s1);
	cout << len << endl;

	s2 = new char[len + 1];
	strcpy_s(s2, len + 1, s1);
	cout << s2 << endl;

	delete[] s2;
}
