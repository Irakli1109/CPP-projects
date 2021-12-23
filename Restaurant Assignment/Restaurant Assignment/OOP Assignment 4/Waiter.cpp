#include <iostream>
#include "Employee.h"
#include "Waiter.h"
using namespace std;
//calculating waiter salary
void Waiter::Calculate_salary(double profitOrTip) {
    if (profitOrTip >= 0) {
        double Salary = 3000 + profitOrTip;  //monthly salary for Waiter
        setSalary(Salary);
    }
    else
        cerr << "Tip couldn't be negative\n";
}
//explicit value constructor for waiter
Waiter::Waiter(string Name, string ID, char empClass, double Salary, double experience) :Employee(Name, ID, empClass, Salary)
{
    yearsOfService = experience;
}
//default constructor
Waiter::Waiter() : Employee()
{
    yearsOfService = 0;
}
//waiter display that calls employee display
void Waiter::display(ostream& out) {
    Employee::display(out);
    out << "Service   ----   " << yearsOfService << " Year(s)" << endl << endl;
}
