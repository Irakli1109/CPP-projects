#include <iostream>
#include "Owner.h"
#include "Employee.h"
using namespace std;

//description of calculate_salary
void Owner::Calculate_salary(double profitOrTip) {
    double Salary = 15000 + 6 * profitOrTip / 10;  //monthly salary for owner
    setSalary(Salary);
}
//explicit value constructor
Owner::Owner(string Name, string ID, char empClass, double Salary) :Employee(Name, ID, empClass, Salary)
{}
//default constructor
Owner::Owner() : Employee()
{}
