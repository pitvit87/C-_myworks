#include <iostream>
using namespace std;

class DynArray
{
	int* arr;
	int size;

public:
	DynArray(int sizeP) : arr{ new int[sizeP] {} }, size{ sizeP }
	{
		cout << "DynArr constructed for" << size << " elemrnts, for " << this << '\n';
	}
	
	DynArray() : DynArray(5) {}
	
	DynArray(const DynArray& object) : arr{ new int[object.size] }, size{ object.size } 
	{
		for (int i{ 0 }; i < size; i++)
		{
			arr[i] = object.arr[i];
		}
		cout << "DynArr copy constructed for " << size << " elements, for " << this << endl;
	}

	DynArray& operator=(const DynArray& object)
	{
		if (!(this == &object))
		{
			if (size != object.size)
			{
				delete[] arr;
				arr = new int[object.size];
			}
			size = object.size;
			for (int i{ 0 }; i < size; i++)
			{
				arr[i] = object.arr[i];
			}
		}
		cout << "DynArr copy assigned for " << size << " elements, for " << this << endl;
		return *this;
	}

	int GetElem(int idx)const { return arr[idx]; }
	void SetElem(int idx, int val) { arr[idx] = val; }
	void print() const;
	void randomizer();
	~DynArray()
	{
		cout << "Try to free memory from DynArray for " << arr << " pointer\n";
		delete[] arr;
		cout << "DynArr destructed for " << size << " elements, for " << this << endl;
	}
};

void DynArray::print()const
{
	for (int i{ 0 }; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void DynArray::randomizer()
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand() % 10; 
	}
}

int main()
{
	srand(time(NULL));
	DynArray ar1{ 10 };
	ar1.randomizer();
	cout << "ar1 elements: ";
	ar1.print();
	DynArray ar2{ ar1 };
	cout << "ar2 elements: ";
	ar2.print();
	cout << "Copy-assignment test\n";
	DynArray ar3{ 5 };
	cout << "ar3 elements: before copy: ";
	ar3.print();
	ar3 = ar2;
	cout << "ar3 elements: after copy: ";
	ar3.print();
}
