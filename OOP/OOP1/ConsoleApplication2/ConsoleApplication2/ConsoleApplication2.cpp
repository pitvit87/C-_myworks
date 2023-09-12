#include <iostream>
using namespace std;

class Point
{
private:
	double  x, y;

public:

	Point(double _xx, double _yy)
	{
		SetXY(_xx, _yy);
	}

	Point() : Point(0.0, 0.0) { }

	Point(double velue) : Point(velue, velue) { }

	Point(const Point& obj)
	{ 
		x = obj.x;
		y = obj.y;
	}

	void Show(string msg)
	{
		cout << msg << " => x = " << x << ", y = " << y << endl;
	}

	void SetXY(double _x, double _y)
	{
		x = _x; y = _y;

		if (x < 0) x = -_x;
		if (y < 0) y = -_y;
	}

	void SetPoint(const Point& pt)
	{
		x = pt.x;
		y = pt.y;
	}

	double X() const { return x; }
	double Y() const { return y; }
	 
	double Length();

};

double Point::Length()
{
	return sqrt(x * x + y * y);
}

void MyFuncTest()
{
	Point point(0,0);
	point.SetXY(-3, 4.4);
	point.Show("MyFuncTest");
}

class PInt
{
private:
	int* p;

public:
	PInt(int value)
	{
		p = new int;
		*p = value;
	}

	PInt() : PInt(0) {}

	PInt(int* _p)
	{
		
		p = new int;
		
		if(_p == nullptr)
			*p = 0;
		else
			*p = *_p;
	}

	PInt(const PInt& obj) : PInt(*obj.p)
	{
		//p = new int;
		//*p = *obj.p;
	}

	PInt& operator=(const PInt& obj)
	{
		*p = *obj.p;
		return *this;
	}

	void Show(const char* msg)
	{
		cout << msg << "=>" << *p << endl;
	}

	~PInt() 
	{
		if (p != nullptr)
			delete p;
	}

};


int main()
{
	PInt p1(4);
	p1.Show("p1"); 

	PInt p2 = p1;
	p2.Show("p2");

	PInt p3;
	p3 = p1;
	p3.Show("p3");
}
