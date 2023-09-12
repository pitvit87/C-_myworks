#include <iostream>
using namespace std;


class Double
{
private:
    double value;

public:
    explicit Double(double value) : value(value) {}
    double GetValue() const { return value; }
  
    explicit Double(const Double& obj)
    {
        value = obj.value + 10;
    }
};

int main()
{
    Double D1(10.5);
    cout << D1.GetValue() << endl;
    Double D2 = D1;
    cout << D2.GetValue() << endl;

    Double AD[] = { Double(1.1),Double(2.2), Double(3.3) };

}
