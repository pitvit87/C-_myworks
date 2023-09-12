#include <iostream>
using namespace std;

class Circle
{
protected:
	double radius;
	const double pi = 3.1415;

public:

	Circle(double _radius)
	{
		if (_radius < 0)
			_radius = -_radius;
			radius = _radius;
	}

	double Area()
	{
		return pi * radius * radius;
	}
};

class Table
{
protected:
	double height, a, b;

public:
	Table(double _a, double _b, double _height) : height(_height), a(_a), b(_b)
	{ }
};

class RoundTable : public Table, public Circle
{
protected:
	int color;

public:
	RoundTable(double _a, double _b, double _height, double _r, int _color) : Table(_a, _b, _height), Circle(_r), color(_color) { }

	RoundTable(double _height, double _r, int _color) : RoundTable(1.0, 1.0, _height, _r, _color) { }

	void Print()
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "height = " << height << endl;
		cout << "radius = " << radius << endl;
		cout << "color = " << color << endl;
		cout << "pi = " << pi << endl;
	}

};

int main()
{
	RoundTable table(2.5, 3.8, 4.4, 1.5, 23);
	table.Print();

	RoundTable table2(3.0, 2.0, 33);
	table2.Print();
}
