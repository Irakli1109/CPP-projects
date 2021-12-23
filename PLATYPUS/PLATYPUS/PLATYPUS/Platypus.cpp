#include "platypus.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
/*
*default constructor that automatically sets the values of
*boolean type class private variables alive and died false.
*/
platypus::platypus()
{
    alive = false;
    died = false;
}
/*
*explicit value constructor that initializes 4 class private variables
*gender, weight, age and name of platypus while creating an object
*/
platypus::platypus(char gen, float weig, short ag, char name) {
    if (gen == 'm' || gen == 'f') //only precondition that gender must be male or female
    {
        gender = gen;
        weight = weig;
        age = ag;
        name_initial = name;
        alive = true;
        mutant = false;
        died = false;
    }
    else
        cerr << "*** This kind of Platypus couldn't exist ***\n\n"; //notifying the user about mistake
}
/*
*print function that outputs platypus information in a clear way
*it has parameter with type ostream to output either by cout, cerr, clog etc.
*/
void platypus::print(ostream& out) const {
    out << "Name    || " << name_initial << "\nGender  || " << ((gender == 'm') ? "Male" : "Female")
        << "\nAge     || " << age << " month(s)\nWeight  || " << weight << " pounds\nMutant  || "
        << ((mutant == 1) ? "YES" : "NO") << "\nIsAlive || " << ((alive == 1) ? "YES" : "NO") << endl;
}
/*
*age_me function which increase the age of platypus by one month
*it consists 2% chance of mutation and 10*weight % chance of dying
*and all of these are implemented by generating random numbers
*/
void platypus::age_me() {
    if (alive) { //precondition that platypus is alive
        int const mutation_rate = 2;
        float const death_chance = 10 * weight; //constants for easy modification
        age++;
        srand(time(0));
        if (rand() % 100 + 1 <= mutation_rate) mutant = true;
        if (rand() % 100 + 1 <= death_chance) { alive = false; died = true; }
    }
    else
        cerr << "*** Unfortunately platypus " << name_initial << " is DEAD ***\n\n";
}
/*
*fight function get platypus object and determines the
*winner between caller and parameter platypuses by fight ratio
*/
void platypus::fight(platypus& object) {
    if (alive == true && object.GetAlive() == true) { //precondition that both platypuses are alive
        srand(time(0));
        float const fightRatio = weight / object.GetWeight() * 50;
        if ((fightRatio > rand() % 100 + 1))
            object.SetAlive(false); //to set platypus object dead
        else
            alive = false;
    }
    else
        cerr << "One of your platypus is DEAD and cannot fight\n\n";
}
/*
*eat function increases platypus weight by percent
*from 0.1 to 5% of its current weight
*/
void platypus::eat() {
    if (alive) {
        srand(time(0));
        weight += (rand() % 50 + 1) * weight / 1000; //formula to get new weight
    }
    else
        cerr << "*** Unfortunately platypus " << name_initial << " is DEAD ***\n\n";
}
/*
*hatch function that sets platypus alive, not mutant and with 0 month
*it has 50% of being male or female and weigh 0.1 to 1 pound
*/
void platypus::hatch(char nam) { //parameter is name_initial for user to set name
    if (!died) { //precondition that platypus is not already dead
        alive = true;
        mutant = false;
        age = 0;
        srand(time(0));
        gender = (rand() % 2) ? 'm' : 'f';      //50% chance of gender
        weight = (float)(rand() % 10 + 1) / 10;  //weight to be random from 0.1 to 1 pound
        name_initial = nam;
    }
    else
        cerr << "*** Unfortunately platypus is DEAD and cann't hatch ***\n\n";
}

float platypus::GetWeight() const {  // getters on Weight
    return weight;
}

short platypus::GetAge() const { //getter of age
    return age;
}

char platypus::GetName() const { //getter of name
    return name_initial;
}

bool platypus::GetAlive() const {   // getters on Alive
    return alive;
}

char platypus::GetGender() const { //getter of gender
    return gender;
}

void platypus::SetAlive(bool status) {  //mutator of Alive
    alive = status;
}

void platypus::SetWeight(float platypuss_mass) { //mutator of weight
    weight = platypuss_mass;
}

void platypus::SetName(char first_name) { //mutator of first_name
    name_initial = first_name;
}

void platypus::SetAge(short platypus_age) { //mutator of age
    age = platypus_age;
}

void platypus::SetGender(char platypus_gender) { //mutator of gender
    gender = platypus_gender;
}

void platypus::SetMutant(bool mutantOrNot) { //mutator of mutant
    mutant = mutantOrNot;
}
ostream& operator << (ostream& o, platypus const& p) { //cout operator overloading
    p.print(o);
    return o;
}
