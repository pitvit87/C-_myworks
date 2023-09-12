#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

class Human
{
private: 
    char* name;
    int age;
    float weight;

public:
    Human()
    {
        name = new char[strlen("NoName") + 1];
        age = 0;
        weight = 0; 
    }

    Human(char* name, int age, float weight)
    {
        this->name = new char[strlen("NoName") + 1];
        strcpy(this->name, "NoName");
        this->age = age;
        this->weight = weight;
    }

    Human(const Human& obj)
    {
        this->name = new char[strlen(obj.name) + 1];
        strcpy(this->name, obj.name);
        this->age = age;
        this->weight = weight;
    }

    void Show()
    {
        cout << name << " " << age << " " << weight << "\n";
    }

    ~Human()
    {
        delete[] name; 
    }
};

Human Test()
{
    Human four;
    return four;
}

Human five = Test(); 

void Show(Human obj)
{
    obj.Show();
}

int main()
{
    Human first;
    first.Show();

    char name[100];
    int age;
    float weight;
    cout << "Enter name\n"; cin.getline(name, 100);
    cout << "Enter age\n"; cin >> age;
    cout << "Enter weight\n"; cin >> weight;
    Human second(name, age, weight);
    second.Show();
    
    Human third(second);
    third.Show();
    Show(second); 
    Human five = Test();
}
