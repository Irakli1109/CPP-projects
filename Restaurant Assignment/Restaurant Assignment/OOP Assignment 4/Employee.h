#include <iostream>
#include <cstddef>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee {
    /*** Data members for Employee abstract class ***/
    string name;
    string employeeId;
    char employeeClass;
    double salary;

public:
    Employee(); //default constructor
    Employee(string Name, string ID, char empClass, double Salary); // explicit value constructor
    void virtual display(ostream& out); //display virtual function
    virtual void Calculate_salary(double profitOrTip) = 0; //pure virtual function
    /*** Setters ***/
    void setName(string Name);
    void setEmployeeId(string ID);
    void setEmployeeClass(char empClass);
    void setSalary(double Salary);
    //getter
    double getSalary();
};
//<< operator overloading
ostream& operator<<(ostream& out, Employee& emp);

#endif // EMPLOEE_H


