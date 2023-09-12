#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template <class Key, class Value>
void ShowMap(map<Key, Value>& M, string msg)
{
	cout << msg << " = ";
	for (pair<Key, Value> item : M)
		cout << item.first << ":" << item.second << "  ";
	cout << endl;
}

class Point
{
private:
	double x, y;

public:
	Point(double x, double y) : x(x), y(y)
	{ }

	Point() : Point(0, 0)
	{ }

	double GetX() { return x; }
	double GetY() { return y; }

	void SetX(double _x) { x = _x; }
	void SetY(double _y) { y = _y; }

	Point operator()(Point& p1, Point& p2, Point& p3)
	{
		return Point(p1.x + p2.x + p3.x, p1.y + p2.y + p3.y);
	}

	Point operator()(double x, int y)
	{
		return Point(this->x + x, this->y + y);
	}

};

ostream& operator<<(ostream& stream, Point& p)
{
	stream << "(" << p.GetX() << "; ";
	stream << p.GetY() << ")" << endl;
	return stream;
}

template<class T>
void ShowVector(vector<T>& V, string msg)
{
	cout << msg << " => ";
	for (T item : V)
		cout << item << "  ";
	cout << endl;
}

void Mult2(int& velue)
{
	velue = velue * 2;
}

void IncrementXY(Point& p)
{
	p.SetX(p.GetX() + 1);
	p.SetY(p.GetY() + 1);
}

int main()
{
	vector<Point> V1 = { 
		Point(1,3),
		Point(2,5),
		Point(3,7),
		Point(4,9) 
	};


	ShowVector(V1, "V1");

	for_each(V1.begin(), V1.end(), IncrementXY);

	ShowVector(V1, "V1");
	
	for_each(V1.begin(),
		V1.end(),
		[](Point& p)
		{
			p.SetX(p.GetX() + 1);
			p.SetY(p.GetY() + 1);
		}
	);


	ShowVector(V1, "V1");


}
