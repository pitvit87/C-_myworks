#include <iostream>
#pragma warning (disable:4996)
using namespace std;

int main()
{
    char str1[100];
    char str2[100];
    char str3[100];
    char str4[100];
    cout << "Enter first string\n";
    cin.getline(str1, 100);
    cout << "size=" << strlen(str1) << "\n";

    for (int i = 0; str1[i] != '\0'; i++)
        str2[i] = str1[i];
    str2[strlen(str1)] = '\0';
    cout << "str2=" << str2 << "\n";

    strcpy(str3, str2);
    cout << "str3(strcpy)=" << str3 << "\n";

    strncpy(str4, str3, 4);
    str4[4] = '\0';
    cout << "str4(+4 char)=" << str4 << "\n";

    strcat(str2, str1);
    cout << "str2(strcat)=" << str2 << "\n";
    
    strncat(str4, str1, 3);
    str4[7] = '\0';
    cout << "str4(strcat(4))=" << str4 << "\n";

    strcpy(str1, "StryNG");
    strcpy(str2, "Stryng");

    cout << "str1(new)=" << str1 << "\n";
    cout << "str2(new)=" << str2 << "\n";

    cout << strcmp(str1, str2) << "\n";
    if (!strcmp(str1, str2))
        cout << "String is equale\n";
    else
        cout << "String isnt equale\n";

    cout << strncmp(str1, str2, 4) << "\n";
    if (!strncmp(str1, str2, 4))
        cout << "String is equale\n";
    else
        cout << "String isnt equale\n";
}
