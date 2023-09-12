#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

template<typename t1, typename t2, typename t3>
class MathOperations
{
private:
    t1 a;
    t2 b;
    t3 c;

public:
    MathOperations(t1 _a, t2 _b, t3 _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }

    MathOperations() : MathOperations(0,0,0) 
    { }

    ~MathOperations()
    { }

    void Show(string msg)
    {
        cout << msg << "=>(" << a << ", " << b << ", " << c << ")" << endl;
    }

    t1 GetA() { return a; }
    t2 GetB() { return b; }
    t3 GetC() { return c; }

    double Avg_3_Types()
    {
        return (a + b + c) / 3;
    }

    double GeometricMean_3_Types()
    {
        return pow((a * b * c), 1.0 / 3.0);
    }

};

int main()
{
    setlocale(LC_ALL, "rus");

    MathOperations <int, float, double> MO1(6, 3.2, 5.3356);
    MO1.Show("MO1");
    cout << "Среднее арифметическое(MO1): " << MO1.Avg_3_Types() << endl;
    cout << "Среднее геометическое(MO1): " << MO1.GeometricMean_3_Types() << endl ;
        
}
