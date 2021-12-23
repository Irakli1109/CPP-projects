/*---------------------------------------------------------------------
                  Driver program to test the Staque class.
  ----------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "Staque.h"

int main()
{
    Staque x, z;
    x.push(10);
    x.push(15);
    x.push(20);
    x.push(25);
    x.push(30);
    cout << x << " --- Staque X\n";
    Staque y = x; //copy constructor call
    cout << y << " --- Staque Y\n";
    x.removeN(2);
    cout << x << "       --- Staque X\n";
    z = x; //assignment call
    cout << z << "       --- Staque Z\n";
    y.remove2E1O();
    cout << y << "          --- Staque Y\n";
    y.push(19);
    y.push(28);
    y.push(5);
    cout << y << "  --- Staque Y\n";
    x.removeLast();
    x.removeLast();
    cout << x << "             --- Staque X\n";
    Staque a = z; //copy constructor call
    a.push(60);
    a.push(3);
    a.push(27);
    cout << a << "-- Staque A\n";

    return 0;
}
