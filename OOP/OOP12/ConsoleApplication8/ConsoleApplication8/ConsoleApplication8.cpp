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

	double LengthOrigin()
	{
		return sqrt(x * x + y * y);
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

template<class T>
void ShowList(list<T>& L, string msg)
{
	cout << msg << " => ";
	for (T item : L)
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

Point& IncrementXY_5(Point& p)
{
	p.SetX(p.GetX() + 5);
	p.SetY(p.GetY() + 5);
	return p;
}

Point AddPoints(Point& p1, Point& p2)
{
	Point p3(p1.GetX() + p2.GetX(), p1.GetY() + p2.GetY());
	return p3;
}

bool ComparePoints(Point& p1, Point& p2)
{
	return p1.LengthOrigin() > p2.LengthOrigin();
}

int main()
{
	vector<Point> V1 = {
		Point(3,7),
		Point(2,6),
		Point(4,9),
		Point(1,5)
	};

	vector<int> V2 = { 1,3,2,8,4,9,5 };

	sort(V2.begin(), V2.end(), 
		[](int a, int b)
		{
			return a > b;
		}
	);

	ShowVector(V2, "V2");

	sort(V1.begin(), V1.end(), ComparePoints);

	ShowVector(V1, "V1");


}
