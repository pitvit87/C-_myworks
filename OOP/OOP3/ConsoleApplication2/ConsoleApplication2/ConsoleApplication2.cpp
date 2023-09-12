#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

class Point
{
private:
	double x, y;

public:
	Point(double x, double y) : x(x), y(y) { }
	Point() : Point(0,0) { }

	void Print(string msg)
	{
		cout << msg << " = (" << x << "; " << y << ")" << endl;
	}
	double X() const { return x; } 
	double Y() const { return y; }

	Point& operator+(Point& obj)
	{
		// а, б => c
		Point res(x + obj.x, y + obj.y);
		return res;
	}

	Point& operator-()
	{
		x = -x;
		y = -y;
		return *this;
	}

	Point& operator+=(Point& obj)
	{
		x = x + obj.x;
		y = y + obj.y;
		return *this;
	}

	friend Point& operator-=(Point& obj1, Point& obj2);
	
	//Инкримент, декримент ++х, х++
	//a = 5;
	//b = a++;
	//Операторы інкрименти, декрименту є:
	//-префіксні (++х)
	//-постфіксні (х++)
	//

	Point& operator++()
	{
		x = x + 5;
		y = y + 5;

		return *this;
	}

	// Постфіксна форма
	Point& operator++(int d)
	{
		x++;
		y++;
		return *this;
	}

	friend Point& operator--(Point& obj);
	friend Point& operator--(Point&, int);
};

Point& operator--(Point& obj)
{
	obj.x -= 3;
	obj.y -= 3;
	return obj;
}

Point& operator--(Point& obj, int d)
{
	obj.x -= 10;
	obj.y--;
	return obj;
}


Point& operator-=(Point& obj1, Point& obj2)
{
	obj1.x = obj1.x - obj2.x;
	obj1.y = obj1.y - obj2.y;
	return obj1;
}

Point& operator-(Point& obj1, Point& obj2)
{
	Point obj3(obj1.X() + obj2.X(), obj1.Y() + obj2.Y());
	return obj3;
}



class ArrayPoint
{
private:
	Point* AP;
	int size;

public:
	ArrayPoint(Point* _AP, int _size)
	{
		size = _size;
		AP = new Point[size];

		for (int i = 0; i < size; i++)
			AP[i] = _AP[i];
	}

	ArrayPoint() : ArrayPoint(nullptr, 0) { }

	~ArrayPoint()
	{
		if (size > 0)
			delete[] AP;
	}

	void Print(string msg)
	{
		cout << msg << " => ";
		for (int i = 0; i < size; i++)
			cout << "(" << AP[i].X() << "; " << AP[i].Y() << ")";
		cout << endl;
	}

	ArrayPoint(const ArrayPoint& obj) : ArrayPoint(obj.AP, obj.size)
	{

	}

	ArrayPoint& operator=(const ArrayPoint& obj)
	{
		if (size > 0)
			delete[] AP;

		size = obj.size;
		AP = new Point[size];

		for (int i = 0; i < size; i++)
			AP[i] = obj.AP[i];

		return *this;
	}



	Point& operator[](int index)
	{
		return AP[index];
	}

	


};

int main()
{
	Point PT[] = {
		Point(1,3),
		Point(2,-5),
		Point(3,4),
		Point(2,8),
		Point(3,10),
	};

	ArrayPoint AP1(PT, 5);
	AP1.Print("AP1");

	ArrayPoint AP2 = AP1;
	AP2.Print("AP2");

	ArrayPoint AP3;
	AP3 = AP1;
	AP3.Print("AP3");

	AP3[2] = Point(100, 200);
	AP3.Print("AP3+");

	Point pt1(1, 1);
	Point pt2(2, 2);
	Point pt3;
	pt3 = pt1 + pt2;
	pt3.Print("pt3");
	pt3 = -pt3;
	pt3.Print("-PT3");
	pt1 += pt2;
	pt1.Print("pt1");

	//Тут віклікаетьсяф operator-=(pt1, pt2);
	pt1 -= pt2;
	pt1.Print("pt1");

	//Тут 
	pt3 = pt1 - pt2;
	pt3.Print("pt3");

	++pt3;
	pt3.Print("pt3");


	pt3++;
	pt3.Print("pt3");

	pt3--; //
	pt3.Print("pt3");

		--pt3;
		pt3.Print("pt3");


};
