#include <iostream>
#include <vector>
using namespace std;

class Point
{
private:
	double x, y;

public:
	Point(double x, double y) : x(x), y(y)
	{ }

	double GetX() { return x; }
	double Gety() { return y; }
	double SetX(double _x) { x = _x; }
	double SetY(double _y) { y = _y; }

	void Show(string msg)
	{
		cout << msg << " => ";
		cout << "x = " << x << ", y = " << y << endl;
	}
};

int main()
{
	vector<double> V1;
	vector<int> V2(10);

	initializer_list<char> LC = { 'a', '+', '&', ':' };
	vector<char> V3(LC);

	vector<double> V4(V1);

	cout << "V1.size = " << V1.size() << endl;
	cout << "V2.size = " << V2.size() << endl;
	cout << "V3.size = " << V3.size() << endl;


}
