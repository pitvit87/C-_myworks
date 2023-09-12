#include <iostream>
using namespace std;

class A
{
protected:
	int a;

public:
	A(int _a) : a(_a) { }

	void Show(string msg)
	{
		cout << msg << " = " << a << endl;
	}

	int GetA() const { return a; }
	void SetA(int _a)
	{
		a = _a;
	}

};

class B : public A
{
protected:
	int b;

public:
	B(int _a, int _b) : A(_a), b(_b)  { }

	void Show(string msg)
	{
		A::Show(msg);
		
		cout << "b = " << b << endl;
	}


	void SetAB(int _a, int _b)
	{
		a = _a;
		b = _b;
	}

	int GetA() const { return A::a;  }
	int GetB() const { return B::b;  }

};

class C : public B
{
private:
	int c;

public:
	C(int _a, int _b, int _c) : B(_a, _b), c(_c) 
	{	}

	void Show(string msg)
	{
		B::Show(msg);

		cout << "c = " << c << endl;
	}
};

int main()
{
	A objA = 10;
	objA.Show("objA");
	objA.SetA(50);
	objA.Show("objA");
	

	B objB(15, 30);
	objB.Show("objB");

	C objC(22, 33, 44);
	objC.Show("objC");

}
