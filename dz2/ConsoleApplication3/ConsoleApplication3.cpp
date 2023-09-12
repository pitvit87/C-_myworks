#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

int main()
{
    srand(time(NULL));
    int* arr = nullptr;
    int* temp = nullptr;
    int size = 20;
    arr = new int[size];
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 35)
            count++;
    }
       
    temp = new int[count];
    int j = 0;
    for (int i = 0; i < size; )
    {
        if (arr[i] >= 35)
        {
            temp[j] = arr[i];
            j++;
            i++;
        }
        else
            i++;
    }
    delete[] arr;
    arr = temp;
    
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] temp;
}
