#include <iostream>
using namespace std;

template<typename T> // шаблонный класс Т 
class Item
{
protected: 
	T item; //аргументы класса

public:
	Item(T _item) //конструктор с одним параметром 
	{
		item = _item;
	}

	Item() : Item(0) { } // нулевой конструктор

	void Print(string msg) // метод Принт
	{
		cout << " " << msg << endl;
		cout << " Item = " << item << endl;
	}

	T GetItem()	{ return item; } // Геттер

	void SetItem(T _item) //Сеттер
	{
		item = _item;
	}

};

template<typename T1, typename T2> // шаблонные класы Т1 и Т2
class Item2 : public Item<T1> // унаследование класса Итем
{
protected: // аргументы класса
	T2 item2;

public:
	Item2(T1 _item, T2 _item2) : Item<T1>(_item) // конструктор с одним параметром и унаследование с класса Итем
	{
		item2 = _item2;
	}

	Item2() : Item<T1>() // Конструктор с нулевыми параметрами
	{
		item2 = 0;
	}

	T2 GetItem2() { return item2; } // Геттер

	void SetItem2(T2 _item2) // Сеттер
	{
		item2 = _item2;
	}

	void Print(string msg) // Метод принт
	{
		Item<T1>::Print(msg);
		cout << " Item2 = " << item2 << endl;
	}
};

int main()
{
	Item<char> firstItem('*');
	firstItem.Print("firstItem('*')");
	firstItem.SetItem('&');
	cout << "-------------------After Set '&'-------------------\n";
	cout << " firstItem.GetItem() = " << firstItem.GetItem() << endl;
	cout << "---------------------------------------------------\n";

	Item2 <int, int> secondItem2;
	secondItem2.Print("secondItem2");
	cout << "---------------------------------------------------\n";

	Item2 <double, char> thirdItem2(34.524, '$');
	thirdItem2.Print("thirdItem2");

	cout << "---------- After thirdItem2(24.632) | '#' ---------\n";
	thirdItem2.SetItem(24.632);
	thirdItem2.SetItem2('#');
	cout << " thirdItem2.GetItem() = " << thirdItem2.GetItem() << endl;
	cout << " thirdItem2.GetItem2() = " << thirdItem2.GetItem2() << endl;

}
