#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

struct Worker
{
    char* name = nullptr;
    int ID;
    int pay;
    float bonus;
    float all;
};

void Add(Worker*& group, int& size)
{
    char buff[100];
    Worker* temp = new Worker[size + 1];
    for (int i = 0; i < size; i++)
        temp[i] = group[i];
    delete[] group;
    group = temp;
    cout << "Enter new worker name\n"; cin.getline(buff, 100);
    group[size].name = new char[strlen(buff) + 1];
    strcpy(group[size].name, buff);
    cout << "Enter ID\n"; cin >> group[size].ID;
    cout << "Enter peyment\n"; cin >> group[size].pay;
    group[size].bonus = (float)group[size].pay / 10;
    group[size].all = group[size].pay + group[size].bonus;
    size++;
}   

void Show(Worker* group, int size)
{
    cout << "#\tName\t\tID\tPay\tBonus\tAll\n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "\t" << group[i].name << "\t" << group[i].ID << "\t" << group[i].pay << "\t" << group[i].bonus << "\t" << group[i].all << "\n";
    }
     
}

void Delete(Worker*& group, int& size, int index)
{
    Worker* temp = new Worker[size - 1];
    for (int i = 0; i < size; i++)
    {
        if (i < index) temp[i] = group[i];
        else if (i > index) temp[i - 1] = group[i];
    }
    delete[] group[size].name;
    delete[] group;
    group = temp;
    size--;
}

void Fill(Worker*& group, int& size, int& index, int& temp, int& size2)
{
    index = 13000;
    size--;
    Worker*  temp;
    for (int i = 0; i < 
        [i] = obj[i]. ;

}


int main()
{
    Worker* group = nullptr;
    int size = 0;
    int choice;
    int index;
    bool job = 1;
    while (job)
    {
        if (size == 0)
        {
            cout << "Enter your choice\n1 - Add\n2-Delete0 - Exit\n";
            cin >> choice;
            if (choice == 1)
            {
                cin.ignore();
                Add(group, size);
            }
            else if (choice == 0) job = 0;
            else cout << "Wrong choice\n";
        }
        else
        {
            cout << "Enter your choice\n1-Add\n2-Show\n3-Delete\n0 - Exit\n";
            cin >> choice; 
            switch (choice)
            {
            case 1: cin.ignore();
                Add(group, size);
                break;
            case 2:
                Show(group, size);
                break;
            case 3:  
                cout << "Enter index for delete\n";
                cin >> index;
                Delete(group, size, index); 
                index--;
                if(index < 0 || index > size - 1)
                break;
            case 0: job = 0; break;
            default:
                cout << "Wrong choice!\n";
                break;
            }
        }
    }
    for (int i = 0; i < size; i++)
        delete[] group[i].name;
    delete[] group;
}

void Fill(Worker*& group, int& size, int& index, int& temp, int& size2)
{
    index = 13000;
    Worker* = temp[size];
    for (int i = 0; i < size; i++)
        size--;
    [i];

}