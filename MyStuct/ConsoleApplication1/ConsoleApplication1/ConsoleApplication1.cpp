#include <iostream>
using namespace std;

struct student
{
    int ID;
    char name[100];
    int math, phis, chim;
    float ave;
};

void Fill(student* group, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter name:\n"; cin.getline(group[i].name, 100);
        cout << "Enter ID:\n"; cin >> group[i].ID;
        cout << "Enter math:\n"; cin >> group[i].math;
        cout << "Enter phis:\n"; cin >> group[i].phis;
        cout << "Enter chim:\n"; cin >> group[i].chim;
        cout << "\n";
        group[i].ave = (float)(group[i].math + group[i].phis + group[i].chim) / 3;
        cin.ignore();
    }
}

void Show(student* group, int size)
{
    cout << "#\tName\t\tid\tmath\tphis\tchim\taverage\n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "\t" << group[i].name << "\t\t" << group[i].ID << "\t" << group[i].math << "\t" << group[i].phis << "\t";
        cout << group[i].chim << "\t" << group[i].ave << "\n";
    }
}

int main()
{
    int const size = 3;
    student group[size];

    Fill(group, size);
    Show(group, size);

}
