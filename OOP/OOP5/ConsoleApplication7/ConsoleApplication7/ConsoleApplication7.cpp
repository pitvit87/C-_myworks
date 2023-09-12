#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

template<class T>// объявление шаблонного класса
class ArrayNumbers// создание класса
{
private:
	T* A;
	int count;
	
public:
	ArrayNumbers(T* _A, int _count) // конструктор с двумя параметрами
	{
		count = _count;
		A = new T[count];

		for (int i = 0; i < count; i++)
			A[i] = _A[i];
	}

	ArrayNumbers() : ArrayNumbers(nullptr, 0) { } // конструктор без параметров

	ArrayNumbers<T>(const ArrayNumbers<T>& obj) // конструктор копирования
	{
		count = obj.count;
		A = new T[count];

			for (int i = 0; i < count; i++)
			{
				A[i] = obj.A[i];
			}
	}

	ArrayNumbers<T>& operator=(const ArrayNumbers<T>& obj) // Перегрузка оператора присваивания
	{
		if (A != nullptr)
		{
			delete[] A;
		}

		count = obj.count;
		A = new T[count];

		for (int i = 0; i < obj.count; i++)
			 A[i] = obj.A[i];

			return *this;
	}

	T& operator[] (int index) // Перегрузка оператора индексирования
	{
		return A[index];
	}

	void Print(string msg) // Вывод на экран
	{
		cout << msg << endl;
		cout << "count = " << count << endl;
		for(int i = 0; i < count; i++)
		cout << "A[" << i << "] = " << A[i] << endl;
	}

	~ArrayNumbers() // деструктор
	{
		if (A != nullptr)
			delete[] A;
	}
};

template<>
class ArrayNumbers<char>
{
public:
	ArrayNumbers() = delete;
};

template<>
class ArrayNumbers<string>
{
public:
	ArrayNumbers() = delete;
};

template<>
class ArrayNumbers<bool>
{
public:
	ArrayNumbers() = delete;
};

int main()
{
	int Arr[] = { 12,5,33,41,65,69,71 };

	ArrayNumbers<int> AN1(Arr,7);
	AN1.Print("AN1");

	ArrayNumbers<int> AN2;
	AN2 = AN1;
	AN2.Print("AN2");

	ArrayNumbers<int> AN3(AN2);
	AN3.Print("AN3");
	
	int a = AN3[2];
	cout << "a = " << a << endl << endl;
	AN3[2] = 0;
	AN3.Print("AN3+");

	//ArrayNumbers<char> objChar;
	//ArrayNumbers<string> objString;
	//ArrayNumbers<bool> objBool;
	
}
