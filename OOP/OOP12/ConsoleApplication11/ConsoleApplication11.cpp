#include <iostream>
#include <map>
#include <vector> 
using namespace std;

class Users
{
private:
	map<string, string> user;

public:
	Users() {}

	void ShowUser(string msg)
	{
		cout << "\n" << msg << ":\n";
		for (pair<string, string> item : user)
		{
			cout << item.first << ":" << item.second << endl;
		}
		cout << endl;
	}

	bool CheckPass(string pass)
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
				cout << "All OK.!!!\n";
			return true;
		}
	}

	void AddUser(string login, string password)
	{
		if (user.empty())
		{
			if (CheckPass(password))
				user.insert(make_pair(login, password));
		}
		else
		{
			int list = 0;
			for (pair<string, string> item : user)
			{
				if (item.first == login)
					list++;
			}
			if (list == 0)
			{
				if (CheckPass(password))
					user.insert(make_pair(login, password));
			}
			else
				cout << "Login is already taken!\n";
		}
	}

	void DeleteUserByLogin(string login)
	{
		user.erase(login);
	}

	void ChangePassword(string login, string oldPassword, string newPassword)
	{
		int count = 0;
		for (pair<string, string> item : user)
		{
			if (item.first == login)
			{
				count++;
			}
		}
		if (count == 0)
			cout << "Login not found!\n";
		else
		{
			if (user.at(login) != oldPassword)
				cout << "Password does not match. Password change not possible!\n";
			else
			{
				for (pair<string, string> item : user)
				{

					if (item.first == login && item.second == oldPassword && (CheckPass(newPassword)))
					{
						user.insert_or_assign(login, newPassword);
						cout << "Change password success!\n";
					}

				}
			}
		}

	}

	void GetPassword(string login)
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
	userOne.ShowUser("userOne++");


}
