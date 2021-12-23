#include <iostream>
#include "Platypus.h"

using namespace std;

int main() {

    int i = 5;

    platypus p1('f', 3.2, 10, 'T');
    platypus p2('m', 2.4, 7, 'Z');
    platypus p3;
    p3.hatch('A');
    cout << p1 << endl << p2 << endl << p3 << endl;

    while (i--) {
        p1.eat();
        cout << "After eat\n" << p1 << endl;
        p1.age_me();
        cout << "After aging\n" << p1 << endl;
        p2.eat();
        cout << "After eat\n" << p2 << endl;
        p2.age_me();
        cout << "After aging\n" << p2 << endl;
        p3.eat();
        cout << "After eat\n" << p3 << endl;
        p3.age_me();
        cout << "After aging\n" << p3 << endl;
    }

    p2.fight(p1);
    cout << p1 << endl << p2 << endl;

    if (p1.GetAlive()) p1.fight(p3);
    else p2.fight(p3);

    cout << p1 << endl << p2 << endl << p3 << endl;

    return 0;
}

