#include <iostream>
#include "Employee.h"
#include "Chef.h"
using namespace std;

void Chef::Calculate_salary(double profitOrTip) {
    double Salary = 10000 + 2 * profitOrTip / 10;  //monthly salary for Chef
    setSalary(Salary);
}

Chef::Chef(string Name, string ID, char empClass, double Salary, string expertise) :Employee(Name, ID, empClass, Salary)
{
    cuisineExpert = expertise;  //unique variable for chef class
}

Chef::Chef() : Employee()
{
    cuisineExpert = " "; //default value for cuisine expertise
}

void Chef::display(ostream& out) {
    Employee::display(out);
    out << "Expertise ----   " << cuisineExpert << endl << endl;
}
