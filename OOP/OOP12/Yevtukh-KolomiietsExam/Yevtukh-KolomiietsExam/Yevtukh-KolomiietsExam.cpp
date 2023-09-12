#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>
#pragma warning(disable: 4996);
using namespace std;

class RecordBook
{
private:
	class PhoneNumber
	{
	private:
		string number;

		enum PhoneChars
		{
			Plus = '+',
			Minus = '-',
			OpenBracket = '(',
			CloseBracket = ')'
		};

		bool CheckNumber(string s)
		{
			for (int i = 1; i < s.length(); i++)
				if (s[i] == Minus || s[i] == OpenBracket || CloseBracket || s[i] == '0' || s[i] == '1' ||
					s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' ||
					s[i] == '8' || s[i] == '9' || s.length() <= 16)
					return true;
				else
					return false;
		}

		bool CheckFirst(string s)
		{
			if (s[0] == Plus || s[0] == OpenBracket || s[0] == CloseBracket || s[0] == '0' || s[0] == '1' ||
				s[0] == '2' || s[0] == '3' || s[0] == '4' || s[0] == '5' || s[0] == '6' || s[0] == '7' ||
				s[0] == '8' || s[0] == '9' || s[0] == '\n')
				return true;
			else
				return false;
		}

	public:
		PhoneNumber() : number("") { };

		string GetNumber() const { return number; }
		void SetNumber(const string& _number) throw(exception)
		{
			if (CheckFirst(_number) == 1 && CheckNumber(_number) == 1)
				number = _number;
			else
				throw exception("Wrong number!");
		}
	};

	string name;
	string address;
	PhoneNumber number;

public:
	
	
	string GetName() const { return name; }
	string GetAddress() const { return address; }
	string GetNumber() const { return number.GetNumber(); }
	void SetName(string _name) { name = _name; }
	void SetAddress(string _address) { address = _address; }
	void SetNumber(string _number) { number.SetNumber(_number); }
		

	RecordBook(string _name, string _address, string _number) throw(exception)
	{
		name = _name;
		address = _address;
		number.SetNumber(_number);
	}

	RecordBook() : RecordBook("", "", "") { };

	void ShowBook(string msg)
	{
		cout << msg << " => Name: " << name << ", Address: " << address << ", Number: " << number.GetNumber() << endl;
	}
};

class HandBook
{
private:
	vector<RecordBook> hBook;

public:
	HandBook() {};

	void Show(string msg)
	{
		cout << msg << " => ";
		for (int i = 0; i < hBook.size(); i++)
			cout << hBook[i].GetName() << ", " << hBook[i].GetAddress() << ", " << hBook[i].GetNumber() << "." 
			<< endl;
	}

	bool Add(string name, string address, string number)
	{
		try
		{
			hBook.push_back(RecordBook(name, address, number));
		}
		catch (exception e)
		{
			cout << e.what() << endl;
			return false;
		}
		return true;
	}

	void DelByName(string name)
	{
		for (int i = 0; i < hBook.size(); )
		{
			if (hBook[i].GetName() == name)
			{
				hBook.erase(hBook.begin() + i);
			}
			else
			{
				++i;
			}
		}
	}

	bool SaveToFile(const char* filename)
	{
		ofstream outFile(filename);
		if (outFile)
		{
			for (int i = 0; i < hBook.size(); ++i)
			{
				outFile << hBook[i].GetName() << " " << hBook[i].GetAddress() << " " << hBook[i].GetNumber() << endl;
			}
			return true;
		}
		return false;
	}


	bool LoadFromFile(const char* filename)
	{
		ifstream inFile(filename);
		if (inFile)
		{
			string name, address, number;
			while (inFile >> name >> address >> number)
			{
				Add(name, address, number);
			}
			return true;
		}
		return false;
	}
};

int main()
{
	HandBook B;

	B.Add("Org-03", "Address-03", "097-9358012");
	B.Add("Org-01", "Address-01", "097-9358012");
	B.Add("Org-03", "Address-03", "099-6258031");
	B.Add("Org-02", "Address-02", "+38(095)-77780029");
	B.Add("Org-03", "Address-03", "099-5258001");

	if (B.SaveToFile("handcccbook.bin"))
		cout << "Save: Ok!" << endl;
	else
		cout << "Save: Error!" << endl;

	B.Show("B");
	B.DelByName("Org-03");
	B.Show("B");

	if (B.LoadFromFile("handbook.bin"))
		cout << "Load: Ok!" << endl;
	else
		cout << "Load: Error!" << endl;

	B.Show("B++");
}
