#include <iostream>
#include "triangle.h"
#include <math.h>


Triangle::Triangle()
{
    width = 0.0;
    height = 0.0;
}

Triangle::Triangle(double width, double height)
{
    this->width = width;
    this->height = height;
}

double Triangle::calcP() const
{
    return sqrt(((width / 2) * (width / 2)) + (height * height))
        + sqrt(((width / 2) * (width / 2)) + (height * height)) + width;
}

double Triangle::calcS() const
{
    return (width * height) / 2;
}

void Triangle::display() const
{
    std::cout << "  Triangle: width = " << width << "; height = " << height;
    std::cout << "; P = " << calcP();
    std::cout << "; S = " << calcS();
    std::cout << "\n";
}

