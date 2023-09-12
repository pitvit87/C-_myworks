#include <iostream>
#pragma warning(disable:4996)

using namespace std;
class String
{
private:
	char* str = nullptr;//1.Внутрышне поле
public:
	String(const char* _str)//2.Конструктор з одним параметром
	{
		if (_str)
		{
			str = new char[strlen(_str) + 1];//визначення розміру та виділення памяті
			strcpy(str, _str);//копіювання з одного масиву у інший
		}
		else
		{
			str = nullptr;//випадок коли строка відсутні
		}
	}
	String() :String(nullptr) //3.Конструктор без параметрів
	{

	}
	void Print(string msg)//5.Метод виведення на екран
	{
		if (str)
		{
			cout << msg << "-";
			for (int i = 0; i < strlen(str); i++)//виведення масиву у консоль
			{
				cout << str[i];
			}
			cout << endl;
		}
		else
		{
			cout << msg << "-" << "Строка вiдсутня!";//у випадку коли строка відсутня(пуста), без параметрів 
		}
	}

	String(const String& obj) //6.Конструктор копіювання
	{
		str = new char[strlen(obj.str) + 1];//визначення та виділення памяті		
		strcpy(str, obj.str);// копіювання строки з масиву у масив
	}

	String& operator= (const String& obj)//7.Оператор копіювання
	{
		delete[] str;
		str = new char[strlen(obj.str) + 1];
		//*str = *obj.str;// 
		strcpy(str, obj.str);//перевантаження оператора =
		return *this;// присвоення значення за адресою поінтера
	}

	~String()//4.Деструктор
	{
		delete[] str;//очищення памяті у кучі
		cout << "1-";
	}

};


int main()
{
	setlocale(LC_ALL, "ru");
	String t1("Слава");
	t1.Print("t1");
	String t2("ЗСУ");
	t2.Print("t2");
	String t5("Героям");
	t5.Print("t5");
	String t4 = t1;
	t4.Print("t4");
	String t3;
	t3.Print("t3");
	t2 = t1;
	t2.Print("t2-6");
	return 0;
}