#include <iostream>
using namespace std;

class Pint
{
private:
    int* p;


public:
    Pint(int value)
    {
    
      
        this->p = new int;
    
        *(this->p) = value;
      
    }

    Pint() : Pint(0) {}

    void Show(string msg)
    {
        cout << msg << " = " << *p << endl;
    }

        Pint(const Pint& obj) : Pint(*obj.p)
        {}

    ~Pint()
    {
        delete p;
    }

    Pint& operator=(const Pint& obj)
    {
        *p = *obj.p;
        return *this;
    }
};

int main()
{


    Pint i1(12);
    i1.Show("i1");

    Pint i2 = i1;
    i2.Show("i2");


    i1 = i2;
    i2.Show("i2");
}