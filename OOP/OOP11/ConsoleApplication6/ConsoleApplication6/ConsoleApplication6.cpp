#include <iostream>
using namespace std;

class Country // Виртуальный класс Кантри
{
protected: // его поля
	string name;
	string capital;

public:
	Country(string _name, string _capital) : name(_name), capital(_capital) // конструктор с двумя параметрами
	{ }

	virtual string GetName() const = 0;
	virtual string GetCapital() const = 0;
	virtual long int GetPopulation() const = 0;
	virtual double GetArea() const = 0;
	virtual void Info(string msg) const = 0;
};

class CountryDetail : public Country // класс КантриДетеил наследующий класс Кантри
{
	long int population; // его поля
	double area;

public:
	//конструктор с 4 параметрами, что дву унаследует и два опредиляет
	CountryDetail(string _name, string _capital, long int _population, double _area) : Country(_name, _capital)
	{
		population = _population;
		area = _area;
	}

	string GetName() const override // геттеры
	{
		return name;
	}

	string GetCapital() const override
	{
		return capital;
	}

	long int GetPopulation() const override
	{
		return population;
	}

	double GetArea() const override
	{
		return area;
	}

	void Info(string msg) const override	// вывод на экран(Площадь в тис. км2, 
	{										//а то не выводит на экран полностью)
		cout << " " << msg << endl;
		cout << " Name => " << name << endl;
		cout << " Capital => " << capital << endl;
		cout << " Population => " << population << endl;
		cout << " Area => " << area << " тыс. км2" << endl;
	}
};

int main()
{
		setlocale(LC_ALL, "RUS");
		CountryDetail firstCountry("Китай", "Пекин", 1411750000, 9599);
		CountryDetail sekondCountry("Индия", "Нью-Дели", 1408000000, 3287);
		CountryDetail thirdCountry("Украина", "Киев", 40997699, 603);
		Country* arr[] = { &firstCountry, &sekondCountry, &thirdCountry };

		double AreaSum = 0;
		for (int i = 0; i < 3; i++)
		{
			AreaSum += arr[i]->GetArea();
		}
		for (int i = 0; i < 3; i++)
		{
			arr[i]->Info("***" + arr[i]->GetName() + "***");
		}
		cout << " Сумма площадей стран => " << AreaSum << " тыс. км2" << endl;
}
