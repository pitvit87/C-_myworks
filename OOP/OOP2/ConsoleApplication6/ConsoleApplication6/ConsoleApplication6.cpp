#include <iostream>
using namespace std;

void Swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int av = 5, bv = 9;
	cout << av << " " << bv << endl;
	
	Swap(&av, &bv);
	
	cout << av << " " << bv;
}
