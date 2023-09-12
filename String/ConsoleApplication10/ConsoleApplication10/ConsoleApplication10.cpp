#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

int main()
{
    char temp[100];
    char* name = nullptr;
    char* subname = nullptr;
    char* pname = nullptr;
    cout << "Enter subname\n";
    cin.getline(temp, 100);
    subname = new char[strlen(temp) + 1];
    strcpy(subname, temp);

    cout << "Enter name\n"; cin.getline(temp, 100);
    name = new char[strlen(temp) + 1];
    strcpy(name, temp);

    cout << "Enter pname\n"; cin.getline(temp, 100);
    pname = new char[strlen(temp) + 1];
    strcpy(pname, temp);
    cout << subname << " " << name << " " << pname << ".";

    delete[] subname;
    delete[] name;
    delete[] pname;
}
