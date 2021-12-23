#include <iostream>
#include <cstddef>
#include "Employee.h"
using namespace std;

#ifndef CHEF_H
#define CHEF_H

class Chef : public Employee {
    string cuisineExpert;
public:
    Chef(); //default constructor 
    Chef(string Name, string ID, char empClass, double Salary, string expertise);
    void Calculate_salary(double profitOrTip); //calc salary for chef
    void display(ostream& out);
};


#endif // CHEF_H



