#include <iostream>
#include "Employee.h"
#include "Owner.h"
#include "Chef.h"
#include "Waiter.h"
#include "Database.h"
using namespace std;

int main() {

    Database restaurant; //database for restaurant

    Employee* owner, * chef1, * chef2, * w1, * w2, * w3;
    //infos of employees
    

    owner = new Owner("Jack", "03091821497", 'O', 15000);
    chef1 = new Chef("Jane",  "53001912124", 'C', 10000, "Italian");
    chef2 = new Chef("Simon", "10532834111", 'C', 10000, "French");
    w1 = new Waiter("Anne",   "12345678900", 'W', 3000, 3);
    w2 = new Waiter("John",   "11111111111", 'W', 3000, 5);
    w3 = new Waiter("Liz",    "12141620320", 'W', 3000, 7);
    
    //add infos of employees to database
    restaurant.push(owner);
    restaurant.push(chef1);
    restaurant.push(chef2);
    restaurant.push(w1);
    restaurant.push(w2);
    restaurant.push(w3);

    double profit, tip1, tip2, tip3;

    /*** April statistics ***/
    profit = 6000;  //setting profit and tip for April
    tip1 = 1000;
    tip2 = 1300;
    tip3 = 1500;

    owner->Calculate_salary(profit);
    chef1->Calculate_salary(profit);
    chef2->Calculate_salary(profit);
    w1->Calculate_salary(tip1);
    w2->Calculate_salary(tip2);
    w3->Calculate_salary(tip3);

    cout << "Month: April\n" << restaurant;

    /*** May statistics ***/
    profit = 10000;  //setting profit and tip for May
    tip1 = 700;
    tip2 = 1000;
    tip3 = 2000;

    owner->Calculate_salary(profit);
    chef1->Calculate_salary(profit);
    chef2->Calculate_salary(profit);
    w1->Calculate_salary(tip1);
    w2->Calculate_salary(tip2);
    w3->Calculate_salary(tip3);

    cout << "Month: May\n" << restaurant;
    
    /*** May statistics ***/
    profit = -7000;  //profit loss for June due to lockdown
    tip1 = 100;
    tip2 = 150;
    tip3 = 200;

    owner->Calculate_salary(profit);
    chef1->Calculate_salary(profit);
    chef2->Calculate_salary(profit);
    w1->Calculate_salary(tip1);
    w2->Calculate_salary(tip2);
    w3->Calculate_salary(tip3);

    cout << "Month: June\n" << restaurant;

    return 0;
}
