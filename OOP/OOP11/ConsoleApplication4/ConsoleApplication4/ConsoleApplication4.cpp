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
	
	for (int i = 0; i < 10; i++)
		V1.push_back(i * i);

	cout << "V1 = ";
	for (int i = 0; i < V1.size(); i++)
		cout << V1[i] << "  ";
	cout << endl;
	
	cout << "V1 = ";
	for (double x : V1)
		cout << x << "  ";
	cout << endl;

	vector<double>::iterator it;

	it = V1.begin();
	cout << "V1 = ";
	while (it != V1.end())
	{
		cout << *it << "  ";
		it++;
	}
	cout << endl;

}
