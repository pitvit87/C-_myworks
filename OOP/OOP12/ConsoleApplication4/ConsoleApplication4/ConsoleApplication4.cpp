#include <iostream>
#include <map>
#include <vector>
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

int main()
{
	Point p1(1, 2);
	Point p2(2, 4);
	Point p3(3, 5);
	Point p4;

	//p4 = p4(p1, p2, p3);
	p4 = p4.operator()(p1, p2, p3);
	cout << p4;
	p4 = p1(2.8, 15);
	cout << p4;

	map<string, Point> M1;

	M1.insert(make_pair("point-1", Point(2, 3)));
	M1.insert(make_pair("point-2", Point(2, 8)));
	M1.insert(make_pair("point-1", Point(2, 5))); //игноруе
	M1.insert(make_pair("point-3", Point(7, 9)));
	M1.insert(make_pair("point-4", Point(8, 3)));

	ShowMap(M1, "M1");

	M1.clear();
	ShowMap(M1, "M1");

	map<char, string> M2;
	M2.insert(make_pair('A', "Assembler"));
	M2.insert(make_pair('B', "Bash"));
	M2.insert(make_pair('C', "C++"));
	M2.insert(make_pair('D', "Dart"));
	M2.insert(make_pair('E', "Erlang"));
	M2.insert(make_pair('F', "Fortran"));
	
	map<char, string>::iterator it;
	it = M2.find('D');

	if (it != M2.end())
		M2.erase(it);
	else
		cout << "not found" << endl;

	ShowMap(M2, "M2");
	map<char, string> M3;
	M3.insert(make_pair('K', "Kotlin"));
	ShowMap(M3, "M3");

	M2.swap(M3);
	ShowMap(M2, "M2");
	ShowMap(M3, "M3");

}
