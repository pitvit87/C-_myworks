#include <iostream>
using namespace std;

template<typename T = int, int size = 10>
class Array10
{
private:
	T* A;
	int size;
public:
	Array10(T* _A)
	{
		for (int i = 0; i < size; i++)
			A[i] = _A[i];
	}

	Array10()
	{
		for (int i = 0; i < size; i++)
			A[i] = i + 1;
	}

	void Show(string msg)
	{
		cout << msg << " => ";
		for (int i = 0; i < size; i++)
			cout << A[i] << " ";
		cout << endl;
	}

};

int main()
{
	Array10<double, 5> objDouble;
	objDouble.Show("objDouble");

	Array10<int> objInt;
	objInt.Show("objInt");

	Array10<> objInt2;
	objInt2.Show("objInt2");


}
