#include <iostream>
#include <map>
#include <vector>
using namespace std;

template <class Key, class Value>
void ShowMap(map<Key, Value>& M, string msg)
{
	cout << "M1 = ";
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
	void SetY(double _y) { x = _y; }


};

ostream& operator<<(ostream& stream, Point& p)
{
	stream << "(" << p.GetX() << "; ";
	stream << p.GetY() << ")" << endl;
	return stream;
}

int main()
{
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

	M2.erase('A');
	M2.erase('D');

	ShowMap(M2, "M2");

	map<char, string>::iterator it = M2.end();
	it--;
	

	M2.erase(it);

	ShowMap(M2, "M2");

}