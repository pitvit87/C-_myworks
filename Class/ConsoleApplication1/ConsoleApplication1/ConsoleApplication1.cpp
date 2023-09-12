#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

class Point
{
private:
	int x;
	int y;
	int z;
public:
	void Show()
	{
		cout << x << "\t" << y << "\t" << z << "\n";
	}

	void SetX(int tx) { x = tx; }
	void SetY(int ty) { y = ty; }
	void SetZ(int tz) { z = tz; }
	

	int GetX() { return x; }
	int GetY() { return y; }
	int GetZ() { return z; }
};

void Show(Point* mass, int size)
{
	cout << "x\ty\tz\n";
	for (int i = 0; i < size; i++)
	{
		mass[i].Show();
	}
}

void Add(Point*& mass, int& size)
{
	int x, y, z;
	Point* temp = new Point[size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = mass[i];
	delete[] mass;
	mass = temp;
	cout << "Enter x\n"; cin >> x;
	mass[size].SetX(x);
	cout << "Enter y\n"; cin >> y;
	mass[size].SetY(y);	
	cout << "Enter z\n"; cin >> z;
	mass[size].SetZ(z);
	size++;
}

int main()
{
	int size = 0;
	Point* mass = nullptr;
	int choice;
	bool job = 1;
	while (job)
	{
		if (size == 0) 
		{
			cout << "Enter your choice\n1-Add point\n0-Exit\n";
			cin >> choice;
			if (choice == 1) Add(mass, size);
			else if (choice == 0) job = 0;
			else cout << "Wrong choice\n";
		}
		else
		{
			cout << "Enter your choice\n1-Add\n2-Show\n0-Exit\n";
			cin >> choice;
			if (choice == 1) Add(mass, size);
			else if (choice == 2) Show(mass, size);
			else if (choice == 0) job = 0;
			else cout << "Wrong choice\n";
		}
	}
	delete[] mass;
}
