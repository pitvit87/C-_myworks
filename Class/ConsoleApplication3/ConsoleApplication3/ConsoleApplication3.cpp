#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

class Student
{
private:
	char* name;
	int ID;
	int math, phis, chim;
	float ave;

public:
	Student()
	{
		name = new char[strlen("NoName") + 1];
		strcpy(name, "NoName");
		ID = 0;
		math = 0;
		phis = 0;
		chim = 0;
		ave = 0;
	}

	Student(const Student& obj)
	{
		this->name = new char[strlen(obj.name) + 1];
		strcpy(this->name, obj.name);
		this->ID = obj.ID;
		this->math = obj.math;
		this->phis = obj.phis;
		this->chim = obj.chim;
		this->ave = obj.ave;
	}

	void Set(char* name, int ID, int math, int phis, int chim)
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->ID = ID;
		this->math = math;
		this->phis = phis;
		this->chim = chim;
		ave = (float)(math + phis + chim) / 3;
	}

	void Show()
	{
		cout << name << "\t" << ID << "\t" << math << "\t" << phis << "\t" << chim << "\t" << ave << "\n";
	}

	char* GetName() { return name; }
	int GetID() { return ID; }
	int GetMath() { return math; }
	int GetPhis() { return phis; }
	int GetChim() { return chim; }
	float GetAve() { return ave; }

	void Write(char* filename)
	{
		char buff[10];
		FILE* fout = fopen(filename, "a");
		fputs(name, fout);
		fputc(';', fout);
		snprintf(buff, 10, "%i", ID);
		fputs(buff, fout);
		fputc(';', fout);
		snprintf(buff, 10, "%i", math);
		fputs(buff, fout);
		fputc(';', fout);
		snprintf(buff, 10, "%i", phis);
		fputs(buff, fout);
		fputc(';', fout);
		snprintf(buff, 10, "%i", chim);
		fputs(buff, fout);
		fputc(';', fout);
		snprintf(buff, 10, "%f", ave);
		fputs(buff, fout);
		fputc(';', fout);
		fclose(fout);
	}

	~Student()
	{
		delete[] name;
	}
};

int main()
{
	char name[100];
	int ID;
	int math, phis, chim;
	Student first;
	cout << "Enter name\n"; cin.getline(name, 100);
	cout << "Enter ID\n"; cin >> ID;
	cout << "Enter math\n"; cin >> math;
	cout << "Enter phis\n"; cin >> phis;
	cout << "Enter chim\n"; cin >> chim;
	first.Set(name, ID, math, phis, chim);
	first.Show();

	cin.ignore();
	char filename[100];
	cout << "Enter filename\n";
	cin.getline(filename, 100);
	first.Write(filename);
	
}
