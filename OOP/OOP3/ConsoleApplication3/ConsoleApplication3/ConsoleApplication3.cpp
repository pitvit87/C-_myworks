#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

class Fraction // клас Фрекшен
{
private: // приховані поля класу
	int integer, part; // ціла та дробна

public:
	Fraction(int _integer, int _part) // конструктор з двома параметрами
	{
		
		this->integer = _integer;
		if (_part >= 0) // перевірка, щоб дробна частина не була відмінною
		{
			this->part = _part;
		}
		else
			this->part = -(_part);
	}

	Fraction() : Fraction(0, 0) { } // конструктор за замовченням

	int GetI() const { return integer; } // геттери
	int GetP() const { return part; }
	
	void Show(string msg) // вивід на екран
	{
		cout << msg << " => (" << integer << "," << part << ")" << endl << endl;
	}

	Fraction(const Fraction& obj) : Fraction(obj.integer, obj.part) { } // конструктор копіювання

	~Fraction() //деструктор 
	{ }

	Fraction& operator=(const Fraction& obj) // оператор копіювання 
	{
		this->integer = obj.integer;
		this->part = obj.part;
		return *this;
	}
};

class ArrayFraction // динамічний массив класу фрекшен 
{
private:
	Fraction* AF; // приховані поля класу
	int size;

public:
	ArrayFraction(Fraction* _AF, int _size) // конструктор який ініціалізує внутрішні поля класу 
	{
		size = _size; // отримуемо розмір
		AF = new Fraction[size]; // виділяємо пам'ять

		for (int i = 0; i < size; i++) // в циклі робимо копіювання
			AF[i] = _AF[i];
	}

	ArrayFraction() : ArrayFraction(nullptr, 0) {} // конструктор за замовченням з нульовими значеннями

	void Show(string msg) // метод виводу на екран
	{
		cout << msg << ":" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "(" << AF[i].GetI() << "," << AF[i].GetP() << ");" << endl;
		}
		cout << endl;
	}

	~ArrayFraction() // деструктор
	{
		if (AF != 0)
			delete[] AF; // видаляемо покажчик якщо він не дорівнює 0
	}

	ArrayFraction(const ArrayFraction& obj) : ArrayFraction(obj.AF, obj.size) // конструктор копіювання
	{ }

	int GetSize() const { return size; } // геттер розміру сайз

	ArrayFraction& operator=(const ArrayFraction& obj) // оператор копіювання
	{
		if (size != 0) // звільняемо покажчик, якщо тот розмір не дорівнює нулю
			delete[] AF;

		size = obj.size; // копіюємо розмір
		AF = new Fraction[size]; // віділяємо пам'ять

		for (int i = 0; i < size; i++) // в циклі копіюємо
			AF[i] = obj.AF[i];

		return *this; // повертаємо *зис(покажчик на комірку пам'яті)
	}

	Fraction& operator[](int index) // функція яка перевантажуе оператор індексування елемент масиву
	{
		return AF[index];
	}

};

int main()
{
	Fraction f1(3, 4); // тестуємо роботу класу Фрекшен
	f1.Show("f1");

	Fraction f2 = f1;
	f2.Show("f2");

	Fraction f3;

	f3 = f2;
	f3.Show("f3");

	Fraction f4(f3);
	f4.Show("f4");

	Fraction AF[] = { // масив класу фрекшен
		Fraction(3,4),
		Fraction(-4,6),
		Fraction(2,7),
		Fraction(8,0),
		Fraction(5,7),
		Fraction(8,6),
	};

	ArrayFraction AF1(AF, 6); // тестуємо роботу класу АррейФрекшен
	AF1.Show("AF1");

	ArrayFraction AF2 = AF1;
	AF2.Show("AF2");

	ArrayFraction AF3;
	AF3 = AF2;
	AF3.Show("AF3");

	AF3[2] = Fraction(10, 9);
	AF3.Show("AF3+");

	cout << "AF1 size => " << AF1.GetSize() << endl << endl;

}
