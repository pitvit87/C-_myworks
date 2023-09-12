#include <iostream>
using namespace std;

class A
{
public:
    virtual void Show()
    {
        cout << "A::Show" << endl;
    }
};

class B : public A
{
public:
    void Show() override
    {
        cout << "B::Show" << endl;
    }


};

class C : public B
{
public:
    void Show() override
    {
        cout << "C::Show" << endl;
    }
};

void ShowInfo(A* pA)
{
    pA->Show();
}

class Figure
{
protected:
    string name;

public:
    Figure(string _name) : name(_name)
    { }
    
    virtual double Area() const = 0;
    
    virtual string GetName() const = 0;
    
};

class Rectangle : public Figure
{
protected:
    double a, b;

public:
    Rectangle(double _a, double _b) : Figure("Rectangle"), a(_a), b(_b)
    { }

    double Area() const override
    {
        return a * b;
    }

    string GetName() const override
    {
        return name;
    }
};

class Circle : public Figure
{
protected:
    double r;

public:
    Circle(double _r) : Figure("Circle"), r(_r)
    { }

    double Area() const override
    {
        return 3.1415 * r * r;
    }

    string GetName() const override
    {
        return name;
    }

};

int main()
{
    Circle cr(2.5);
    Rectangle rect(5, 8);

    cout << "cr.area = " << cr.Area() << endl;
    cout << "rect.area = " << rect.Area() << endl;
    cout << "cr.Name = " << cr.GetName() << endl;
    cout << "rect.Name = " << rect.GetName() << endl;

    Figure* pF;
    pF = &cr;
    cout << "cr.area = " << pF->Area() << endl;

    pF = &rect;
    cout << "rect.area = " << pF->Area() << endl;

    //Figure fg("Figure");
    //double x = fg.Area();

    Figure* AF[2] = {
        &cr, &rect
    };

    double summArea = 0.0;
    for (int i = 0; i < 2; i++)
        summArea += AF[i]->Area();

    cout << "summArea = " << summArea << endl;

}
