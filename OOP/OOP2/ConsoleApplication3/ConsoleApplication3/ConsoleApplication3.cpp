#include <iostream>
using namespace std;

class B;

class A
{
private:
    int a;

public:

    void Fn(A& obj)
    {
        a = 8;
        obj.a = 3;
    }
    friend void Fn2(A&, B&);

};

class B
{
private:
    int b;
    friend void Fn2(A&, B&);
};

void Fn2(A& obj1, B& obj2)
{
    obj1.a = 3;
    obj2.b = 8;
    void Show(int obj1.a, int obj2.b)
        {

        }
}

void main()
{
    std::cout <<  obj1.a;
}
