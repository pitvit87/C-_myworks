#include <iostream>
using namespace std;

int cmp(char* str1, char* str2)
{
	if (strlen(str1) > strlen(str2))
		return 1;
	else if (strlen(str1) < strlen(str2))
		return -1;
	else
	{
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str1[i] > str2[i])
				return 1;
			else if (str2[i] > str1[i])
				return -1;
		}
		return 0;
	}
}

int main()
{
	char str1[] = "String";
	char str2[] = "String";
	cout << "cmp = " << cmp(str1, str2) << "\n";
}
