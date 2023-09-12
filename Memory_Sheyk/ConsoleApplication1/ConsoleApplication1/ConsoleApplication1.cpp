#include <iostream>
#pragma warning(disable: 4996)
using namespace std;



int main()
{
	int number;
	char str[] = "This is string";
	FILE* fout = fopen("3.txt", "w");
	cout << "Enter number of string\n";
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		fputs(str, fout);
		fputc(';', fout);
		fputc('\n', fout);
	}
	fclose(fout);

	char buff[100];
	FILE* fin = fopen("3.txt", "r");
	int size = 0;
	while (fgets(buff, 100, fin))
	{
		size++;
	}
	fclose(fin);
	cout << "Size = " << size;
}
