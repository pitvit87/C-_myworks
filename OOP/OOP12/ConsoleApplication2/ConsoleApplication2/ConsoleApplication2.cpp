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

	Point() : Point(0,0)
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

	Point pt(0, 0);

	pt = M1.at("point-2");
	cout << "pt => ";
	cout << pt;

	if (M1.empty())
		cout << "empty" << endl;
	else
		cout << "not empty" << endl;

	map<string, Point>::iterator it;

	it = M1.find("point-4");

	if (it == M1.end())
		cout << "not found" << endl;
	else
		cout << it->first << ":" << it->second << endl;

	cout << M1.size() << endl;

	pt = M1["point-3"];
	cout << "pt => " << pt << endl;
}
