#pragma once

class Triangle
{
	double width;
	double height;

public:
	Triangle();
	Triangle(double width, double height);
	double calcP() const;
	double calcS() const;
	void display() const;
};

