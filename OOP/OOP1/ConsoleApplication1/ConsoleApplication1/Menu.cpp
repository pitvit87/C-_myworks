#include "Menu.h"
#include <iostream>

void Menu::display() const
{
    system("cls");
    std::cout << "\n\t =====================";
    std::cout << "\n\t  Geometry Calculator ";
    std::cout << "\n\t =====================";
    std::cout << "\n\t   1 - Circle Calc    ";
    std::cout << "\n\t   2 - Rectangle Calc ";
    std::cout << "\n\t   3 - Triangle Calc  ";
    std::cout << "\n\t   4 - Exit Program   ";
    std::cout << "\n\t =====================";
}

int Menu::defineChoice()
{
    std::cout << "\n\n> Choose need operation: ";
    std::cin >> choice;
    return choice;
}

bool Menu::allowContinue()
{
    std::cout << "\n >Continue (y/n)? - ";
    std::cin >> allow;
    return (allow == 'y');
}
