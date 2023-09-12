#include <iostream>
using namespace std;

class Human //класс Человек
{
protected: // аргументы класса
	string name;
	string surname;

public:
	Human(string _name, string _surname) //конструктор с двумя параметрами
	{
		name = _name;
		surname = _surname;
	}

	string GetName() { return name; } //Геттеры
	string GetSurname() { return surname; }

	void SetName(string _name) // Сеттеры
	{
		name = _name;
	}

	void SetSurname(string _surname)
	{
		surname = _surname;
	}

	void Print(string msg) // Метод класу Принт
	{
		cout << " " << msg << endl;
		cout << " Name - " << name << endl << " Surname - " << surname << endl;
	}
};

class Worker : public Human //класс Рабочий, что унаследует клас Человек
{
protected: // аргументы класса Рабочий
	double salary;
	string position;

public:		// конструктор с 4 параметрами, что 2 наследует с класса Человек и 2 с аргументов класса Воркер
	Worker(string _name, string _surname, double _salary, string _position) : Human(_name, _surname) 
	{
		salary = _salary;
		position = _position;
	}

	Worker() : Worker(" ", " ", 0, " ") { } // конструктор с нулевыми значениями

	double GetSalary() { return salary; } // Гетерры
	string GetPosition() { return position; }

	void SetSalary(double _salary) //Сеттеры
	{
		salary = _salary;
	}

	void SetPosition(string _position)
	{
		position = _position;
	}

	void Print(string msg) // метод Принт
	{
		Human::Print(msg);
		cout << " Salary - " << salary << endl << " Position - " << position << endl;
	}
};

int main()
{
	cout << "-----------------------------------" << endl;
	Human h1("Vladimer", "Zelenskiy");
	h1.Print("President of Ukraine");
	cout << "-----------------------------------" << endl;
	Worker w1("Valeriy", "Zaluzhniy", 33000.45, "General");
	w1.Print("Golovnokomanduvach ZSU");
	cout << "-----------------------------------" << endl;
}
