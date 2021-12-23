#include <iostream>
#include "Employee.h"

using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

class Database {
public:
    Database();  //default constructor for database
    ~Database(); //destructor freeing memory
    Database(const Database& original); //copy constructor
    const Database& operator=(const Database& rightHandSide); //assignment operator
    void push(Employee* object); //pushing objects in front
    void pop(Employee* object); //deleting specified object if it is in database
    void lastEmployeed(); //returns last employeed object's data
    void display(ostream& out); //displaying database from last employeed to first employeed
private:

    class Node {
    public:
        Node(Employee* object);  //Node constructor gets emploee pointer object

        /*** data member for Node ***/
        Employee* data;
        Node* next;
    };
    /*** Data members for Database ***/
    Node* first;
    int mySize;
};
//node constructor
inline Database::Node::Node(Employee* object = NULL) {
    data = object;
    next = NULL;
}
//destructor for database
inline Database::~Database() {
    Node* temp1 = first;
    Node* temp2 = first;
    while (temp1 != NULL) {
        temp1 = temp2->next;
        delete temp2;
        temp2 = temp1;
    }
}
//database constructor
inline Database::Database()
    : first(NULL), mySize(0)
{}
//copy constructor definition
inline Database::Database(const Database& original) {
    first = NULL;
    if (mySize != 0) {
        mySize = original.mySize;
        first = new Node(original.first->data);
        Node* lastPtr = first;
        Node* origPtr = original.first->next;
        while (origPtr != NULL) {
            lastPtr->next = new Node(origPtr->data);
            lastPtr = lastPtr->next;
            origPtr = origPtr->next;
        }
    }
}
//assignment operator overloading
inline const Database& Database::operator=(const Database& rightHandSide) {
    if (this != &rightHandSide) {
        this -> ~Database(); //deleting database
        if (rightHandSide.mySize == 0) {
            first = NULL;
            mySize = 0;
        }
        else {
            mySize = rightHandSide.mySize;
            first = new Node(rightHandSide.first->data);
            Node* lastPtr = first;
            Node* rhsPtr = rightHandSide.first->next;
            while (rhsPtr != NULL) {
                lastPtr->next = new Node(rhsPtr->data);
                lastPtr = lastPtr->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    return *this;
}
//pushing object from the top like stack
inline void Database::push(Employee* object) {
    if (mySize == 0)   //check against self-assignment
        first = new Node(object);
    else {
        Node* temp = first;
        first = new Node(object);
        first->next = temp;
    }
    mySize++;
}
//pop removes the specified object if it is in database
inline void Database::pop(Employee* object) {
    Node* tempAddress = first;
    Employee* tempData = first->data;
    int checker = 0;
    if (tempData == object)
        checker = 1; //checker is to identify if object is in database
    else {
        while (tempAddress->next->data != object || tempAddress != NULL) {
            tempAddress = tempAddress->next;
        }
        if (tempAddress != NULL)
            checker = 1;
    }
    if (checker) { 
        if (tempAddress == first)  //if deleting first node
            first = first->next;
        else {
            Node* target = tempAddress->next;
            tempAddress->next = target->next;
            delete target;
            mySize--;
        }
    }
    else cerr << "This object is not employed!\n";
}
//returns last employeed person
inline void Database::lastEmployeed() {
    cout << *(first->data);
}
//displaying entire database
inline void Database::display(ostream& out) {
    Node* temp = first;
    out << "In Total: " << mySize << " Employ/Employee\n\n";
    while (temp != NULL) {
        out << *(temp->data) << endl;
        temp = temp->next;
    }
}
//overloading << operator for database
ostream& operator<<(ostream& out, Database& object) {
    object.display(out);
    return out;
}
#endif // DATABASE_H
