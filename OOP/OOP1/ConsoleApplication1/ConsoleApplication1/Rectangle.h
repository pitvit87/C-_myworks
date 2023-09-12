#pragma once

class Rectangle
{
	double width;
	double height;
public:
	Rectangle();
	Rectangle(double width, double height);
	double calcP() const;
	double calcS() const;
	void display() const;
};

