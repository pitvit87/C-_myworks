#include "Circle.h"
#include <iostream>

Circle::Circle()
{
    radius = 0.0;
}

Circle::Circle(double radius)
{
    this->radius = radius;
}

double Circle::calcP() const
{
    return 2 * 3.14 * radius;
}
 
 double Circle::calcS() const
{
    return 3.14 * radius * radius;
}

void Circle::display() const
{
    std::cout << "  Circle: radius = " << radius;
    std::cout << "; P = " << calcP();
    std::cout << "; S = " << calcS();
    std::cout << "\n";
}
