#include <iostream>
#pragma warning (disable: 4996)
using namespace std;

class Human
{
private:
	char name[100];
	int age;
	float weight;

public:
	Human()
	{
		strcpy(name, "NoName");
		age = 0;
		weight = 0;
	}

	Human(const char name[], int age = 0, int weight = 0)
	{
		strcpy(this->name, name);
		this->age = age;
		this->weight = weight;
	}

	void Show()
	{
		cout << name << "\t" << age << "\t" << weight << "\n";
	}

	void Set(char* name, int age, float weight)
	{
		strcpy(this->name, name);
		this->age = age;
		this->weight = weight;
	}

	char* GetName() { return name; }
	int GetAge() { return age; }
	float GetWeight() { return weight; }

	~Human()
	{

	}
};

int main()
{
	Human first;
	char name[100];
	int age;
	float weight;
	first.Show();
	cout << "Enter name\n"; cin.getline(name, 100);
	cout << "Enter age\n"; cin >> age;
	cout << "Enter weight\n"; cin >> weight;

	first.Set(name, age, weight);
	first.Show();

	cout << "Name = " << first.GetName() << "\n";

	Human second("Eva", 34, 140);
	second.Show();

	Human three("Joseph");
	three.Show();
}
