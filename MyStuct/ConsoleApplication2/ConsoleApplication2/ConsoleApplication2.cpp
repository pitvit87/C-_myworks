#include <iostream>
using namespace std;

struct PIB
{
	char sname[30];
	char name[30];
	char pname[30];
};

struct grade
{
	int math;
	int phis;
	int chim;
	float ave;
};

struct student
{
	PIB date;
	grade tabel;
	int age;
	int hight;
};

void Fill(student* group, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter sname:\n"; cin.getline(group[i].date.sname, 30);
		cout << "Enter name:\n"; cin.getline(group[i].date.name, 30);
		cout << "Enter pname:\n"; cin.getline(group[i].date.pname, 30);
		cout << "Enter math score:\n"; cin >> group[i].tabel.math;
		cout << "Enter phis score:\n"; cin >> group[i].tabel.phis;
		cout << "Enter chim score:\n"; cin >> group[i].tabel.chim;
		group[i].tabel.ave = (float)(group[i].tabel.math + group[i].tabel.phis + group[i].tabel.chim) / 3;
		cout << "Enter age:\n"; cin >> group[i].age;
		cout << "Enter hight:\n"; cin >> group[i].hight;
		cout << "\n";
		cin.ignore();
		system("cls");
		}
}

void Show(student* group, int size)
{
	int choice;
	int job = 1;

	while (job)
	{
		int choice;
		bool job = 1;

		cout << "Enter your choice:\n 1 - Base info\n 2 - Grade info\n 0 - Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "#\tSname\t\t\tName\tPname\tAge\tHight\n";
			for (int i = 0; i < size; i++)
			{
				cout << i + 1 << "\t" << group[i].date.sname << "\t\t\t" << group[i].date.name << "\t" << group[i].date.pname << "\t\t" << group[i].age << "\t";
				cout << group[i].hight << "\n";
			}
			break;
		case 2:
			cout << "#\tName\t\tMath\tPhis\tChim\tAve\n";
			for (int i = 0; i < size; i++)
			{
				cout << i + 1 << "\t" << group[i].date.sname << " " << group[i].date.name[0] << "." << group[i].date.pname[0] << ".\t" << group[i].tabel.math << "\t";
				cout << group[i].tabel.phis << "\t" << group[i].tabel.chim << "\t" << group[i].tabel.ave << "\n";
			}
			break;
		case 0: job = 0; break;
		default:
			cout << "Wrong choice!\n";
			break;
		}
	}
}


int main()
{
	int const size = 3;
	student group[size];
	
	Fill(group, size);
	Show(group, size);
}
