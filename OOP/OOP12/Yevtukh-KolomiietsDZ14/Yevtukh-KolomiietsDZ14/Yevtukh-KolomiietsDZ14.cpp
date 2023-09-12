#include <iostream>
#include <map>
#include <vector> 
using namespace std;

class Users // создаем класс
{
private:
	map<string, string> user;

public:
	Users() {} // конструктор без параметров

	void ShowUser(string msg) // вывод на экран
	{
		cout << "\n" << msg << ":\n";
		for (pair<string, string> item : user)
		{
			cout << item.first << ":" << item.second << endl;
		}
		cout << endl;
	}

	bool CheckPass(string pass) // проверка пороля путем сравнения символов в формате (int) с таблицей ASCI
	{
		if (pass.length() < 5)
		{
			cout << "Password Incorrect!\n";
			return false;
		}
		else
		{
			int count = 0;
			for (int i = 0; i < pass.length(); i++)
			{
				if ((int)pass[i] >= 48 && (int)pass[i] <= 57 || (int)pass[i] >= 65 && (int)pass[i] <= 90 ||
					(int)pass[i] >= 97 && (int)pass[i] <= 122)
					count++;
				else
				{
					cout << "Password Incorrect!\n";
					return false;
				}
			}
			if (count == pass.length())
			{
				cout << "password OK!\n";
				return true;
			}
		}
	}

	void AddUser(string login, string password) //добавление в нового пользователя в базу данных, с проверкой 
	{											//на уникальность
		if (user.empty()) //если список пуст
		{
			if (CheckPass(password))
				user.insert(make_pair(login, password));
		}
		else // если не пуст, то сравниваем
		{
			int list = 0;
			for (pair<string, string> item : user)
			{
				if (item.first == login)
					list++;
			}
			if (list == 0) // если совподений не нашли
			{
				if (CheckPass(password))
					user.insert(make_pair(login, password));
			}
			else // А если нашли, то...
				cout << "Login is already taken!\n";
		}
	}

	void DeleteUserByLogin(string login) // удаление из базы данных
	{
		user.erase(login);
	}

	void ChangePassword(string login, string oldPassword, string newPassword) //изминение пароля с проверками 
	{				                     // на верность внесенного пароля и наличия логина в списке введенных
		int count = 0;
		for (pair<string, string> item : user)
		{
			if (item.first == login) // проверяем есть ли логин в списке
			{
				count++;
			}
		}
		if (count == 0) // если нет в списке
			cout << "Login not found!\n";
		else
		{
			if (user.at(login) != oldPassword) // пароли не совпадают
				cout << "Password does not match. Password change not possible!\n";
			else
			{
				for (pair<string, string> item : user)
				{

					if (item.first == login && item.second == oldPassword && (CheckPass(newPassword)))
					{	//если логин и старый пароль совподают, и новый пароль проходит проверку - меняем пароль
						//user.insert_or_assign(login, newPassword);
						user[login] = newPassword;
						cout << "Change password success!\n";
					}

				}
			}
		}

	}

	void GetPassword(string login)// выводим пароль по логину
	{
		for (pair<string, string> item : user)
		{
			if (item.first == login)
			{
				cout << "Password " << item.first << " is " << item.second << "\n";
			}
		}
	}
};


int main()
{
	Users userOne;
	userOne.AddUser("Ivan", "Ivt6Kl5");
	userOne.AddUser("Petrov", "hs3fTyl");
	userOne.AddUser("Maks", "RKty89f");
	userOne.AddUser("Maks", "RKty23489f");
	userOne.AddUser("Dima", "RK+-ty89f");
	userOne.AddUser("Serg", "RK45");
	userOne.AddUser("Serg", "RK45dwer");
	userOne.AddUser("Alexandr", "RK4526526");

	userOne.ShowUser("userOne");
	userOne.DeleteUserByLogin("Maks");
	cout << "----------------------------\n";
	userOne.ShowUser("userOne+");
	cout << "----------------------------\n";
	userOne.GetPassword("Serg");
	cout << "----------------------------\n";
	userOne.ChangePassword("Nikolay", "RK45dwer", "NewPassWord");
	userOne.ChangePassword("Serg", "RK4353dwer", "01010101010");
	userOne.ChangePassword("Serg", "RK45dwer", "NewPassWord");
	cout << "----------------------------\n";
	userOne.GetPassword("Serg");
	userOne.ShowUser("userOne++");


}
