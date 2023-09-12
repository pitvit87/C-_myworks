#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

class String
{
private:
	char* str = nullptr; //поля класса

public:
	String(const char* _str) // конструктор с параметром
	{
		if (_str)
		{
			str = new char[strlen(_str) + 1];
			strcpy(str, _str);
		}
		else
		{
			str = nullptr;
		}
	}

	String() : String(nullptr) // конструктор без параметров
	{
		
	}

	String(const String& obj) //Конструктор копирования
	{
		str = new char[strlen(obj.str) + 1];
		strcpy(str, obj.str);
	}

	~String() //деструктор
	{
		delete[] str;
	}

	void Print(string msg) //Вывод на экран
	{
		if (str)
		{
			cout << msg << " - ";
			for (int i = 0; i < strlen(str); i++)
			{
				cout << str[i];
			}
			cout << endl;
		}
		else
		{
			cout << msg << "-" << "String empty!" << endl;
		}
	}



	String& operator=(const String& obj) //оператор копирования
	{
		delete[] str;
		str = new char[strlen(obj.str) + 1];
		strcpy(str, obj.str);
		return *this;
	}
};

int main()
{
	setlocale(LC_ALL, "");
	String p1("Мама");
	p1.Print("t1");
	String p2("мыла");
	p2.Print("p2");
	String p5("раму");
	p5.Print("p5");
	String p4 = p1;
	p4.Print("p4");
	String p3;
	p3.Print("p3");
	p2 = p1;
	p2.Print("p6(p2)");
}
