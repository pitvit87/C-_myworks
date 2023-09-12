#include <iostream>
#include <fstream>
using namespace std;

class Point
{
private:
	double x, y;

public:
	Point(double x, double y) : x(x), y(y)
	{ }

	double GetX() const { return x; }
	double GetY() const { return y; }

	bool SaveToFile()
	{
		ofstream outFile;

		outFile.open("point.bin", ios::out | ios::binary);

		if (!outFile)
			return false;

		outFile.write((char*)&x, sizeof(x));
		outFile.write((char*)&y, sizeof(double));

		outFile.close();

		return true;
	}

	bool LoadFromFile()
	{
		ifstream inFile("point.bin", ios::binary);

		if (!inFile)
			return false;

		inFile.read((char*)&x, sizeof(x));
		inFile.read((char*)&y, sizeof(y));

		inFile.close();
		return true;

	}
};

int main()
{
	Point pt(8, 9);
	if (pt.SaveToFile())
		cout << "OK!" << endl;
	else
		cout << "Error!" << endl;

	Point pt2(0, 0);
	if (pt2.LoadFromFile())
		cout << "OK!" << endl;
	else
		cout << "Error!" << endl;

	cout << "pt2.x = " << pt2.GetX() << endl;
	cout << "pt2.y = " << pt2.GetY() << endl;
}
