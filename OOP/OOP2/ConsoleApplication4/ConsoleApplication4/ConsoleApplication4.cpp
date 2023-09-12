#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int y = 5;

    int* px;
    int* py;
    px = &x;
    cout << px << " " << &x << endl;
    cout << *px << " " << x << endl;

    *px = 99;
    cout << *px << " " << x << endl << endl;
    py = &y;
    cout << py << " " << &y << endl << endl; 
    cout << *py << " " << y << endl << endl;

    py = px;
    cout << *px << " " << *py << " " << x << endl << endl;
}
