#include <iostream>
using namespace std;

class A
{
private:

	class B
	{
	private:
		int b;
		static double Pi;

	public:
		B(int _b) : b(_b) { }

		void Show(string msg)
		{
			cout << msg << " => " << b << endl;
			cout << "A::B::Pi = " << Pi << endl;
		}

		int Get() { return b; }
	};

	int a;
	B obj;

public:
	A(int _a, int _b) : a(_a), obj(_b) { }

	void Show(string msg)
	{
		cout << msg << " => ";
		cout << "a = " << a << ", ";
		cout << "obj.b = " << obj.Get() << endl;
		
		cout << "B::Show => ";
		obj.Show(msg);
	
	}

	int Get() const { return a; }
	//  так не вийде, клас В недоступній за межами класу А
	//B GetObjB() const { return obj; }

};

double A::B::Pi = 3.1415;
int x;

int main()
{
	A objA(2, 5);
	//A::B objB;

	objA.Show("objA");

	int x;

	cout << ::x << endl;
}
