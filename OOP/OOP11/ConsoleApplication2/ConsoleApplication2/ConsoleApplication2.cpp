#include <iostream>
#include <fstream>
using namespace std;

class Point
{
public:
	double x, y;

};

ofstream& operator<<(ofstream& stream, Point& pt)
{
	stream.open("point.txt");
	stream << pt.x << endl;
	stream << pt.y << endl;
	stream.close();
	return stream; 
}

ifstream& operator>>(ifstream& stream, Point& pt)
{
	stream.open("point.txt");
	stream >> pt.x;
	stream >> pt.y;
	stream.close();
	return stream;
}

int main()
{
	Point p1{ 2.2, 5.5 };

	ofstream outF;
	outF << p1;

	Point p2{ 0.0, 0.0 };
	ifstream inF;
	inF >> p2;

	cout << "p2.x = " << p2.x << endl;
	cout << "p2.y = " << p2.y << endl;

}
