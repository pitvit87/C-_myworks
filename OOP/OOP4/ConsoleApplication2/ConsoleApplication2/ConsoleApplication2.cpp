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

	Point<T>& operator=(T velue)
	{
		x = y = velue;
		return *this;
	}

	bool operator&&(Point<T> obj)
	{
		return (x == obj.x) && (y == obj.y);
	}



};


// Перевантаження оператора > за допомогою глобальної функції
template <class T>
bool operator>(Point<T>& obj1, Point<T>& obj2)
{
	// Критерій порівняння
	double len1 = sqrt(obj1.X() * obj1.X() + obj1.Y() * obj1.Y());
	double len2 = sqrt(obj2.X() * obj2.X() + obj2.Y() * obj2.Y());
	return len1 > len2;
}


template <>
class Point<char>
{
private:
	Point() { }
};
template <>
class Point<bool>
{
private:
	Point() { }
};

template <class T>
class Point<T*>
{
private:
	T* px;
	T* py;

public:
	Point(T* _px, T*_py)
	{
		
		px = new T;
		py = new T;
		if (_px == nullptr)
			*px = 0;
		else
			*px = *_px;
		if (_py == nullptr)
			*py = 0;
			else
			*py = *_py;

	}
	~Point()
	{
		delete px;
		delete py;
	}

	Point(const Point<T>& obj) : Point(obj.px, obj.py) {	}

	Point<T>& operator=(const Point& obj)
	{
		Point(T* _px, T* _py)
		{
			px = new T;
			py = new T;

			if (_px == nullptr)
				*px = 0;
			else
				*px = *_px;
			if (_py == nullptr)
				*py = 0;
				else
				*py = *_py;
		}
		return *this;
	}

	void Print(string msg)
	{
		cout << msg << " => " << *p << endl;
	}

};

int main()
{
	Point<int> pt2(1, 3);
	Point<double> pt3(2.2, 3.3);
	
	Point<int*> pt(nullptr);

}
