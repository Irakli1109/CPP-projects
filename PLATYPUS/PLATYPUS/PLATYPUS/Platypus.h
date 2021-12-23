#ifndef PLATYPUS_H
#define PLATYPUS_H
#include <iostream>
using namespace std;
class platypus
{
    float weight;
    short age;
    char name_initial;
    char gender;
    bool alive;
    bool mutant;
    bool died; //variable that is only needed for hatch function

public:
    platypus();
    platypus(char, float, short, char);
    void print(ostream&) const;
    void age_me();
    void fight(platypus&);
    void eat();
    void hatch(char);
    //getters' declarations
    float GetWeight() const;
    short GetAge() const;
    char GetName() const;
    char GetGender() const;
    bool GetAlive() const;
    bool GetMutant() const;
    //setters' declarations
    void SetWeight(float);
    void SetAge(short);
    void SetName(char);
    void SetGender(char);
    void SetAlive(bool);
    void SetMutant(bool);
};
ostream& operator << (ostream&, platypus const&); //overloaded function declaration

#endif // PLATYPUS_H
