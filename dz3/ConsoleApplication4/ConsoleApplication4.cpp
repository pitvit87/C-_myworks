#include <iostream>
using namespace std;

//4.	Создать структуру Human. Поля структуры – имя, рост, вес, размер ноги.Создать массив экземпляров структуры и функции
//      заполнения и вывода на экран.Также написать функцию редактирования указанного поля и экземпляра структуры

struct Human
{
    char name[30];
    int height;
    int weight;
    int footsize;
};

void Fill(Human* group, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter name:\n"; cin.getline(group[i].name, 30);
        cout << "Enter height:\n"; cin >> group[i].height;
        cout << "Enter weight:\n"; cin >> group[i].weight;
        cout << "Enter foot size:\n"; cin >> group[i].footsize;
        cin.ignore();
        system("cls");
    }
}

void Show(Human* group, int size)
{
    cout << "| # |\t" << " Name:\t\t" << "| Heigth: \t" << "| Weigth: \t" << "| Foot size:\n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "\t" << group[i].name << "\t\t" << group[i].height << "\t\t" << group[i].weight << "\t\t"
            << group[i].footsize << endl;
    }
}

void Cheing(Human* group,  int size)
{
    int size1;
    int size2;
    int choice2;
    bool job = 1;
    do
    {
        do
        {
            cout << "Enter the person to change(1-3):\n";
            cin >> size1;
            if (size1 < 1 || size1 > 3)
                size1 = 0;
        } while (size1 == 0);
        
        do
        {
            cout << "Enter the data type to change((1)Name,(2)Height,(3)Weight,(4)Foot size):\n";
            cin >> size2;

            if (size2 < 1 || size2 > 4)
                size2 = 0;

            switch (size2)
            {
            case 1: cin.ignore(); cin.getline(group[size1 - 1].name, 30); break;
            case 2: cin >> group[size1 - 1].height; break;
            case 3: cin >> group[size1 - 1].weight; break;
            case 4: cin >> group[size1 - 1].footsize; break;
            default: cout << "Wrong choice!\n";
                break;
            }
        } while (size2 == 0);

        do {
            cout << "Agein cheing?((1)Yes,(2)No)\n";
            cin >> choice2;
            if (choice2 < 1 || choice2 >> 2)
            {
                choice2 = 0;
                cout << "Wrong choice!\n";
            }
            else if (choice2 == 2)
            {
                job = 0;
                Show(group, size);
            }
        } while (choice2 == 0);
    } while (job);
}

int main()
{
    int const size = 3;
    Human group[size];
    int size1;
    int size2;
    int choice;
    bool job1 = 1;
    Fill(group, size);
    Show(group, size);
    cout << endl;
    while (job1)
    {
        cout << "To change the data((1)Yes, (2)Exit)?\n";
        cin >> choice;
        switch (choice)
        {
        case 1: Cheing(group,size); break;
        case 2: job1 = 0; cout << "Bye!Bye!\n"; break;
        default:
            cout << "Wrong choice! Try agen!\n";
            break;
        }
    }   
}
