#include <iostream>
using namespace std;


class Circle
{
private:
    double x, y, r;

public:
    static const double Pi;

    Circle(double x, double y, double r) : x(x), y(y), r(r) {}

    void Show(string msg)
    {
        cout << msg << " => ";
        cout << "x= " << x << ", y= " << y << ", r = " << r << endl;
    }

    double X() const { return x; }
    double Y() const { return y; }
    double R() const { return r; }

    double Area()
    {
        return Circle::Pi * r * r;
    }

};

const double Circle::Pi = 3.1415;

int main()
{
     << endl;
   
    Circle cr(1, 2, 2.5);
    cout << "Area = " << cr.Area() << endl;
}
