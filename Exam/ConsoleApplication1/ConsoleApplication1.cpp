#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

//Работаем над экзаменом
//1.	Экзаменационное задание.Написать программу «Телефонная книга», содержащая структуру с полями :
//a.ФИО
//b.Номер телефона
//c.Email
//Функции :
//a) - добавления в телефонную книгу
//b) - удаления из телефонной книги
//c) - сортировка по имени
//d) - проверка адреса электронной почты на нормальность(кол - во @ и точек, длина имени и домена и пр), также проверить номер 
//	   телефона на реальность(только цифры и спецсимволы)
//e) - редактирование полей по выбору пользователя
//f) - чтения данных из файла
//g) - запись в файл
//h) - реализовать механизм, который позволял бы пользователю делать некоторые телефоны избранными, чтоб к ним был простой
//	   доступ.
// 
// Стоит сказать, что за 100 % выполнение данных задач максимальная оценка – 10 баллов.Чтоб получить более высокую оценку 
// необходимо добавить нечто, не рассматриваемое в курсе и изученное самостоятельно – цветовое оформление, подключить 
// управление при помощи клавиатуры или что то на свое усмотрение.

struct PhoneBook
{
	char* fullname = nullptr;
	char* phone = nullptr;
	char* email = nullptr;
};

bool TelCheck(char* phone)
{
	char phonsymb[14] = { '+','-','0','1','2','3','4','5','6','7','8','9','(',')' };
	int count;
	int tsize = strlen(phone);
	
	if (tsize > 16)
		return false;
	
	if (phone[0] != '+')
		return false;
	
	for (int i = 1; i < tsize; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (phone[i] == phonsymb[j])
				count++;
		}
	}
	
	if (count + 1 < tsize)
		return false;
	
	 return true;
}

bool EmailCheck(char* email)
{
	int tsize = strlen(email);
	int lclprt = 0;
	int domain = 0;
	if (tsize > 254)
		return false;
	int atcount = 0;
	
	for (int i = 0; i < strlen(email); i++)
	{
		if (email[i] == '@')
			atcount++;
	}

	if (atcount > 1)
		return false;

	for (int i = 0; email[i] != '@'; i++)
	{
		lclprt++;
	}

	if (lclprt > 64)
		return false;

	for (int i = 0; email[i] < tsize; )
	{
		if (email[i] == '.' && email[i + 1] == '.')
			return false;
		else if ((int)email[i] == 33 || (int)email[i] >= 35 && (int)email[i] <= 39 || (int)email[i] == 42 || (int)email[i] == 43
			|| (int)email[i] == 45 || (int)email[i] >= 47 && (int)email[i] <= 57 || (int)email[i] == 61 || (int)email[i] == 63 ||
			(int)email[i] >= 65 && (int)email[i] <= 90 || (int)email[i] >= 94 || (int)email[i] <= 126)
			i++;
		else if (email[i] == '@')
			i++;
		else
			return false;
	}

	return true;
}

void Add(PhoneBook* mybook, int& size)
{
	char temp[256];
	PhoneBook* tempPB = new PhoneBook[size + 1];
	for (int i = 0; i < size; i++)
		tempPB[i] = mybook[i];
	delete[] mybook;
	mybook = tempPB;
	cout << "Enter full name:\n"; cin.getline(mybook[size].fullname, 100);
	cout << "Enter phone number:\n"; cin.getline(temp, 265);
	do {
		cin.getline(temp, 256);
		if (!TelCheck(temp))
		{
			cout << "Wrong number! Try agen!\n";
			delete[] temp;
		}
	} while (TelCheck(temp));
	strcpy(mybook[size].phone, temp);
	delete[] temp;
	cin.ignore();
	cout << "Enter e-mail:\n"; cin.getline(temp, 265);
	do {
		cin.getline(temp, 256);
		if (!EmailCheck(temp))
		{
			cout << "Wrong email! Try agen!\n";
			delete[] temp;
		}
	} while (EmailCheck(temp));
	strcpy(mybook[size].email, temp);
	cin.ignore();
	delete[] temp;
}

int main()
{
	PhoneBook* mybook = nullptr;
	int size = 0;
	char phonsymb[14] = { '+','-','0','1','2','3','4','5','6','7','8','9','(',')' };

}
