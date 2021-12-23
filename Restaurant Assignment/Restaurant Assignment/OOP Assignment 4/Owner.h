#include <iostream>
#include <cstddef>
#include "Employee.h"
using namespace std;

#ifndef OWNER_H
#define OWNER_H
class Owner : public Employee {
public:
    Owner(); //default consturctor
    Owner(string Name, string ID, char empClass, double Salary); //explicit value constructor
    void Calculate_salary(double profitOrTip);
};



#endif // OWNER_H




