#include <iostream>
using namespace std;

class C;

class A
{
private:
	int a;

	friend class C;
	
};
	

class C
{
private:
	int c;
	
public:

	void Demo(A& obj1)
	{
		obj1.a = 55;
	}
};

int main()
{

}
