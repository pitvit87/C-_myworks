#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

void Merge(char* str1, char* str2, char*& result)
{
    result = new char[strlen(str1) + strlen(str2) + 2];
    strcpy(result, str1);
    strcat(result, " ");
    strcat(result, str2);
}

int len(char* str)
{
    int count = 0;
    for (; str[count]; count++) {}
    return count;
}

void Merge_h(char* str1, char* str2, char*& result)
{
    result = new char[len(str1) + len(str2) + 2];
    for (int i = 0; i < len(str1); i++)
        result[i] = str1[i];
    result[len(str1)] = ' ';
    for (int i = 0; i < len(str2); i++)
        result[i + len(str1) + 1] = str2[i];
    result[len(str1) + len(str2) + 1] = '\0';
}

int main()
{
    char temp[100];
    char* str1;
    char* str2;
    char* result;

    cout << "Enter first string:\n";
    cin.getline(temp, 100);
    str1 = new char[strlen(temp) + 1];
    strcpy(str1, temp);
    cout << "Enter second string\n";
    cin.getline(temp, 100);
    str2 = new char[strlen(temp) + 1];
    strcpy(str2, temp);

    Merge(str1, str2, result);
    //Merge_h(str1, str2, result);
    cout << result << "\n";

    delete[] str1;
    delete[] str2;
    delete[] result;
}
