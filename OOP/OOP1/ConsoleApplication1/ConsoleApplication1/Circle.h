#pragma once

class Circle
{ 
	double radius;
	
public:
	Circle();
	Circle(double radius);
	double calcP() const;
	double calcS() const;
	void display() const;
};

