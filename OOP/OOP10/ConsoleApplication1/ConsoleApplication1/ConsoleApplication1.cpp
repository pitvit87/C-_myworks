#include <iostream>
using namespace std;

double CalcExpression(double a, double b) throw(const char*, int, char)
{
	double c;

	if (a < 0)
		throw exception("a<0");
	if (b < 0)
		throw exception("b<0");
	if (b == 0)
		throw exception("b == 0");

	c = sqrt(a) / sqrt(b);

	return c;
}

int main()
{
	double c;

	try
	{
		c = CalcExpression(-5, 3);

		
	}
	catch (exception e)
	{
		cout << e.what() << endl;
		return 0;
	}

	cout << "c = " << c << endl;

}
