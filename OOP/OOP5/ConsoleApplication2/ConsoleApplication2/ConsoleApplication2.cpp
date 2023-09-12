#include <iostream>
using namespace std;


template<class T1, class T2>
class Velues
{
private:
	T1 velue1;
	T2 velue2;

public:
	Velues(T1 _velue1, T2 _velue2) : velue1(_velue1), velue2(_velue2) 
	{ }

	void Show(string msg)
	{
		cout << msg << " => ";
		cout << "velue1 = " << velue1;
		cout << ", velue = " << velue2 << endl;
	}

	double Avg()
	{
		return (velue1 + velue2) / 2.0;
	}

};

int main()
{
	Velues<int, double> V1(10, 2.8);
	V1.Show("V1");
	cout << "Avg = " << V1.Avg() << endl;
}
