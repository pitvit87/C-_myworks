#include <iostream>
#include <fstream>
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

	bool SaveToFile() // функція запису даних в файл
	{
		ofstream outFile; // потік в файл бинарного формату
		outFile.open("fraction.bin", ios::out | ios::binary);

		if (!outFile) // перевирка потоку, чи спрацював потік
			return false;

		outFile.write((char*)&integer, sizeof(int)); //запис
		outFile.write((char*)&part, sizeof(int));

		outFile.close(); // закриття файлу

		return true; // повернення тру
	}

	bool LoadFromFile() //функція запису данних в файл
	{
		ifstream inFile("fraction.bin", ios::binary); // направлення потоку з файлу в нашу программу

		if (!inFile) // перевірка на коректність
			return false;

		inFile.read((char*)&integer, sizeof(int)); //зчитування
		inFile.read((char*)&part, sizeof(int));

		inFile.close(); // закриття файлу 
		return true; // повернення тру
	}

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

int main()
{
	setlocale(LC_ALL, "RU");

	Fraction firstFraktion(23, 45);
	firstFraktion.Show("firstFraction");
	firstFraktion.SaveToFile();
	if (firstFraktion.SaveToFile())
		cout << "Save - OK!" << endl;
	else
		cout << "Error!" << endl;

	Fraction sekondFraction;
	cout << "\nsekondFraction до загрузки:\n";
	sekondFraction.Show("sekondFraction");
	
	if (sekondFraction.LoadFromFile())
		cout << "Load - Ok!" << endl;
	else
		cout << "Error!" << endl;

	cout << "\nsekondFraction после загрузки:\n";
	sekondFraction.Show("sekondFraction");

}