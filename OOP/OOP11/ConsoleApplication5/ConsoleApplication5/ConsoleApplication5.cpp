#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Point
{
private:
	double x, y;

public:
	Point(double x, double y) : x(x), y(y)
	{ }

	double GetX() { return x; }
	double GetY() { return y; }
	double SetX(double _x) { x = _x; }
	double SetY(double _y) { y = _y; }

	void Show(string msg)
	{
		cout << msg << " => ";
		cout << "x = " << x << ", y = " << y << endl;
	}
};

ostream& operator<<(ostream& stream, Point& pt)
{
	stream << "(" << pt.GetX() << "; " << pt.GetY() << ") ";
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

int main()
{
	vector<double> V1;

	vector<Point> VP1 = {
		Point(1,3),
		Point(2,4),
		Point(3,5),
		Point(5,7)
	};

	ShowVector(VP1, "VP1");

	VP1.pop_back();
	ShowVector(VP1, "VP1");

	Point pt = VP1.at(1);
	pt.Show("pt");

	pt = VP1.front();
	pt.Show("pt");

	pt = VP1.back();
	pt.Show("pt");

	vector<Point>::iterator it;
	Point pt2(10, 20);
	//it = VP1.begin() + 2;
	it = VP1.end();
	VP1.insert(it, pt2);
	ShowVector(VP1, "VP1");

	initializer_list<Point> IL1 = {
		Point(5,6),
		Point(7,8),
		Point(-3,-4)
	};

	VP1.insert(VP1.begin(), IL1);
	ShowVector(VP1, "VP1");

	VP1.erase(VP1.end() - 1);
	ShowVector(VP1, "VP1");

	Point* ptr = VP1.data();

	cout << "VP1 => ";
	for (int i = 0; i < VP1.size(); i++)
	{
		cout << "(" << ptr->GetX() << "; ";
		cout << ptr->GetY() << ")  ";
		ptr++;
	}
	cout << endl;

	if (VP1.empty())
		cout << "empty" << endl;
	else
		cout << "not empty" << endl;

	vector<Point> VP2(IL1);
	VP2.swap(VP1);
	ShowVector(VP1, "VP1");
	ShowVector(VP2, "VP2");

	VP1 = VP2;
	ShowVector(VP1, "VP1");
	ShowVector(VP2, "VP2");
	VP2.clear();
	ShowVector(VP2, "VP2");

	VP2.assign(VP1.begin(), VP1.begin() + 3);
	ShowVector(VP2, "VP2");

}
