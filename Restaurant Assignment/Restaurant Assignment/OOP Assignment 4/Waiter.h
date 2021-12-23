#include <iostream>
#include <cstddef>
#include "Employee.h"
using namespace std;

#ifndef WAITER_H
#define WAITER_H

class Waiter : public Employee {
    double yearsOfService;
public:
    Waiter();
    Waiter(string Name, string ID, char empClass, double Salary, double experience);
    void Calculate_salary(double profitOrTip);
    void display(ostream& out);
};


#endif // WAITER_H




