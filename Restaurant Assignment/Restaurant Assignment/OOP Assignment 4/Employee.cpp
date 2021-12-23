#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee()  //default value constructor implementation
    : name(" "), employeeId(" "), employeeClass(' '), salary(0)
{}

Employee::Employee(string Name, string ID, char empClass, double Salary) //explicit value constructor implementation
    : name(Name), employeeId(ID), employeeClass(empClass), salary(Salary)
{}
void Employee::display(ostream& out) { //virtual display function definition
    out << "Name      ----   " << name << endl;
    out << "ID        ----   " << employeeId << endl;
    out << "Class     ----   " << employeeClass << endl;
    out << "Salary    ----   " << salary << endl;
}
/*** Setter Definitions ***/
void Employee::setName(string Name) {
    name = Name;
}

void Employee::setEmployeeId(string ID) {
    employeeId = ID;
}

void Employee::setEmployeeClass(char empClass) {
    employeeClass = empClass;
}

void Employee::setSalary(double Salary) {
    salary = Salary;
}
/*** Getter for salary ***/
double Employee::getSalary() {
    return salary;
}
//<< operator overloading definition
ostream& operator<<(ostream& out, Employee& emp) {
    emp.display(out);
    return out;
}
