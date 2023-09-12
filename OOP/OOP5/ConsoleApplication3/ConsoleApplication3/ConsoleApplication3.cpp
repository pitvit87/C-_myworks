#include <iostream>
#include <vector>
#pragma warning(disable: 4996)
using namespace std;

void ShowList(initializer_list<int> L1)
{
	cout << "L1 = ";
	const int* pI = L1.begin();
	while (pI != L1.end())
	{
		cout << *pI << " ";
		cout << endl;
		pI++;
	}
	cout << endl;
}

void ShowList(initializer_list<double> LD)
{
	cout << "LD = ";
	const double* pD = LD.begin();
	while (pD != LD.end())
	{
		cout << *pD << " ";
		cout << endl;
		pD++;
	}
	cout << endl;
}

struct Day
{
	int number;
	string name;
};


int main()
{
	initializer_list<int> L1 = { 1, 2, 3, 4, 5, 6 };
	initializer_list<string> L2 = { "One", "Two", "Three" };

	const int* pI = L1.begin();

	while (pI != L1.end())
	{
		cout << *pI << " ";
		pI++;
	}

	ShowList(L1);
	ShowList({ 3.1415, 2.71, 1.0 });

	initializer_list<Day> DW = {
		{ 1, "Monday" },
		{ 2, "Truesday" },
		{ 3, "Wednesday" }
	};
	const Day* pD = DW.begin();
	cout << " Day of week" << endl;
	while (pD != DW.end())
	
	{
		cout << pD->number << " : " << pD->name << endl;
		pD++;
	}
	cout << endl;

	vector<Day> V1(DW);
}
