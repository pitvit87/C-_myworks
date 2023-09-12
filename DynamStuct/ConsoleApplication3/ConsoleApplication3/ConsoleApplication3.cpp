#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

int main()
{
	char surname[100];
	char name[100];
	int age;
	char buff[4];
	cout << "Enter sername:\n"; cin.getline(surname, 100);
	cout << "Enter name\n"; cin.getline(name, 100);
	cout << "Enter age\n"; cin >> age;

	FILE* out;
	out = fopen("2.csv", "w");
	fputs(surname, out);
	fputc(';', out);
	fputs(name, out);
	fputc(';', out);
	itoa(age, buff, 10);
	fputs(buff, out);
	fputc('\n', out);
	fclose(out);

	char* tsurname = nullptr;
	char* tname = nullptr;
	int tage;

	FILE* in = fopen("2.csv", "r");
	char temp[100];
	fgets(temp, 100, in);
	char* token = strtok(temp, ";");
	tsurname = new char[strlen(token) + 1];
	strcpy(tsurname, token);
	token = strtok(NULL, ";"); 
	tname = new char[strlen(token) + 1];
	strcpy(tname, token);
	token = strtok(NULL, "\n");
	tage = atoi(token);
	fclose(in);

	cout << "Surname = " << tsurname << "\n";
	cout << "Name = " << tname << "\n";
	cout << "Age = " << tage << "\n";
	
	delete[] tsurname;
	delete[] tname;
}
