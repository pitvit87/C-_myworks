#include "DialogManager.h"
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"


void DialogManager::circleDialog()
{
	double radius;
	std::cout << "  Input circle radius: ";
	std::cin >> radius;
	//
	Circle* c = new Circle(radius);
	c->display();
	delete c;
}

void DialogManager::rectangleDialog()
{
	double width;
	double hight;
	std::cout << "  Input rectangle width: ";
	std::cin >> width;
	std::cout << "  Input rectangle hight: ";
	std::cin >> hight;
	//
	Rectangle* r = new Rectangle(width, hight);
	r->display();
	delete r;
}

void DialogManager::triangleDialog()
{
	double width;
	double hight;
	std::cout << "  Input triangle width:";
	std::cin >> width;
	std::cout << "  Input triangle hight:";
	std::cin >> hight;
	//
	Triangle* t = new Triangle(width, hight);
	t->display();
	delete t;
}
