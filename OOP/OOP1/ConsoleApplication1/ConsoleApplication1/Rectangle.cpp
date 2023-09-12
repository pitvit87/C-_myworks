#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle()
{
    width = 0.0;
    height = 0.0;
}

Rectangle::Rectangle(double width, double height)
{
    this->width = width;
    this->height = height;
}

double Rectangle::calcP() const
{
    return (width + height) * 2;
}

double Rectangle::calcS() const
{
    return width*height;
}

void Rectangle::display() const
{
    std::cout << "  Rectangle: width = " << width;
    std::cout << "; height = " << height;
    std::cout << "; P = " << calcP();
    std::cout << "; S = " << calcS();
    std::cout << "\n";
}
