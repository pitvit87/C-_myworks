#include <iostream>
using namespace std;

template <class T>
class Point
{
private:
	T x, y;

public:
	Point(T x, T y) : x(x), y(y) { }
	Point() : Point(0, 0) { }

	void Print(string msg)
	{
		cout << msg << " => " << "( " << x << "; " << y << ")" << endl;
	}

	T X() { return x; }
	T Y() { return y; }

	Point<T>& operator+(Point<T>& obj)
	{
		Point<T> resObj(x + obj.x, y + obj.y);
		return resObj;
	}

	bool operator==(Point<T>& obj)
	{
		return (x == obj.x) && (y == obj.y);
	}



};

int main()
{
	Point<int> objInt(2, 8);
	objInt.Print("objInt");

	

	Point<int> objInt(1, 3);
	Point<int> objInt2(1, 1);
	Point<int> objInt3;
	objInt3 = objInt + objInt2;
	objInt3.Print("obj3");

	bool res = objInt == objInt2;
	cout << res << endl;
}
