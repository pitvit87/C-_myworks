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
	map<int, string> M1;

	M1.insert(pair<int, string>(1, "One"));  
	M1.insert(pair<int, string>(2, "Two"));

	M1.insert(make_pair(3, "Three"));

	map<int, string>::iterator it = M1.begin();

	while (it != M1.end())
	{
		cout << it->first << ":" << it->second << "  ";
		it++;
	}
	cout << endl;

	cout << "M1 = ";
	for (pair<int, string> item : M1)
		cout << item.first << ":" << item.second << "  ";
	cout << endl;

	ShowMap(M1, "M1");
}
