
#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int main()
{
    char* str = nullptr;
    char temp[100];

    cout << "Enter string\n";
    cin.getline(temp, 100);
    str = new char[strlen(temp) + 1];
    strcpy(str, temp);

    cout << "str = " << str << "\n";
    delete[] str;
}
