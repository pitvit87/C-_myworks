#include <iostream>
using namespace std;

template <class TA>
class A 
{
private:
	TA a;

public:
	A(TA _a) : a(_a) { }

	void Show()
	{
		cout << "A::Show" << endl;
		cout << "a = " << a << endl;
	}

};


template <class TA, class TB>
class B : public A<TA>
{
private:
	TB b;

public:

	B(TA _a, TB _b) : A<TA>(_a), b(_b)
	{ }

	void Show()
	{
		A<TA>::Show();
		cout << "B::Show" << endl;
		cout << "b = " << b << endl;

	}
};

template <typename TA, typename TB, class TC>
class C : public B<TA, TB>
{
private:
	TC c;

public:

	C(TB _a, TB _b, TC _c) : B<TA, TB>(_a, _b) 
	{
		c = _c;
	}

	C() : B<TA, TB>(0, 0), c(0) {}

	void Show()
	{
		A<TA>::Show();
		B<TA, TB>::Show();

		cout << "C::Show" << endl;
		cout << "c = " << c << endl;

	}
};


int main()
{
	
	C<int, double, char> objC(20, 3.88, '+');
	objC.Show();

	C<double, float, bool> objC2;
	objC2.Show();
}
