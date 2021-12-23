/*-- Staque.h --------------------------------------------------------------

  This header file defines a Stack data type.
  Basic operations:
    constructor:      Constructs an empty stack
    destructor:       Deletes unnecessary memory to avoid leakage
    = overload:       it copies each value of nodes to the new Staque and avoid leakage, check also for self assignment
    copy constructor: creates and then assigns one staque with the values of another
    empty:            Checks if a stack is empty
    push:             Modifies a stack by adding a value at the top
    top:              Accesses the top stack value; leaves stack unchanged
    back:             Accesses the back stack value; leaves stack unchanged
    removeLast:       Modifies stack by removing the value which has added last
    removeN:          Removes n element specified by the user by using LIFO rule
    remove2E1O        Deletes 2 even and 1 odd number in staque by LIFO rule
    display:          Displays all the stack elements
    << overload:      Overloads << operator to use << with lists more conveniently
--------------------------------------------------------------------------*/

#include <iostream>
#include <cstddef>
using namespace std;

#ifndef STAQUE_H
#define STAQUE_H

class Staque
{
public:
    /***** Function Members *****/
    /***** Constructors *****/
    Staque() {
        /*-----------------------------------------------------------------------
          An empty Stack object has been constructed
          Everything is initialized as 0 or NULL.
       ------------------------------------------------------------------------*/
        myTop = NULL;
        myBack = NULL;
        mySize = 0;
    }

    Staque(const Staque& original) {
        /*-----------------------------------------------------------------------
          Copy constructor that assigns each noe value of original list
          to the staque located on the left of equal sign.
       ------------------------------------------------------------------------*/
        myTop = NULL;
        myBack = NULL;
        mySize = 0;
        if (!original.empty()) {
            myTop = new Node(original.top()); //initialization of myTop
            Node* lastPtr = myTop;
            Node* origPtr = original.myTop->next;
            mySize = 1; //size is 1 because first node is already created
            while (origPtr != 0) {
                lastPtr->next = new Node(origPtr->data);
                lastPtr->next->prev = lastPtr;
                lastPtr = lastPtr->next;
                origPtr = origPtr->next;
                mySize++;
            }
            myBack = lastPtr; //myBack gets last node's address
        }
    }

    /***** Destructor *****/
    ~Staque() {
        /*------------------------------------------------------------------------
            Class destructor:
            The linked list in the stack has been deallocated.
          ------------------------------------------------------------------------*/
        if (!empty()) { //if list is empty then no deletion is needed
            removeN(mySize);
        }
    }

    /***** Assignment *****/
    const Staque& operator= (const Staque& rightHandSide) {
        /*------------------------------------------------------------------------
          assignment operator that does similar job as copy-constructor
          but additionally it check for self assignment and avoid memory leakage.
        ------------------------------------------------------------------------*/
        if (this != &rightHandSide) {
            this->~Staque(); //avoiding memory leakage
            if (rightHandSide.empty()) {
                myTop = NULL;
                myBack = NULL;
                mySize = 0;
            }
            else {
                myTop = new Node(rightHandSide.top());
                myBack = myTop;
                mySize = 1;
                Node* lastPtr; //pointer to store node addresses
                Node* rhsPtr;  //pointer to the rightHandSide node
                lastPtr = myTop;
                rhsPtr = rightHandSide.myTop->next;
                while (rhsPtr != NULL) {
                    lastPtr->next = new Node(rhsPtr->data);
                    lastPtr->next->prev = lastPtr;
                    lastPtr = lastPtr->next;
                    rhsPtr = rhsPtr->next;
                    mySize++;
                }
                myBack = lastPtr;
            }

        }
        return *this; //returning object dereferenced value
    }

    /*------------------------------------------------------------------------
       Check if stack is empty.
       Returns true if stack is empty and false otherwise.
      -----------------------------------------------------------------------*/
    bool empty() const {
        return mySize == 0;
    }


    void push(const int& value) {
        /*------------------------------------------------------------------------
          it pushes the value in list. if it is odd
          it will go the left side and if it is even
          it goes on front of the staque
         -----------------------------------------------------------------------*/
        if (mySize == 0) {
            myTop = new Node(value);
            myBack = myTop;
            myTop->order = mySize + 1;
        }
        else {
            Node* temp1;
            Node* temp2;
            if (value % 2) { //varaint for odd numbers
                temp1 = myBack;
                myBack = new Node(value);
                temp2 = myBack;
                temp1->next = temp2;
                myBack->prev = temp1;
                myBack->order = mySize + 1;
            }
            else { //even cases
                temp1 = myTop;
                myTop = new Node(value);
                temp2 = myTop;
                temp1->prev = temp2;
                myTop->next = temp1;
                myTop->order = mySize + 1;
            }
        }
        mySize++;
    }
    void display(ostream& out) const {
        /*------------------------------------------------------------------------
          Display values stored in the stack.
         -----------------------------------------------------------------------*/
        Node* nodeAddr = myTop;
        for (int i = 1; i <= mySize; i++) {
            out << nodeAddr->data << " ";
            nodeAddr = nodeAddr->next;
        }
    }

    int top() const {
        /*--------------------------------------------------------------------------
        function returns the integer value which is in front of the list
        ---------------------------------------------------------------------------*/
        if (!empty()) //precondition
            return myTop->data;
        else {
            cout << "/*** Staque is Empty ***/\n";
            return -1;
        }
    }



    int back() const {
        /*--------------------------------------------------------------------------
        function returns the integer value which is in back of the list
        ---------------------------------------------------------------------------*/
        if (!empty()) //precondition
            return myBack->data;
        else {
            cout << "/*** Staque is Empty ***/\n";
            return -1;
        }
    }

    void removeLast() {

        /*------------------------------------------------------------------------
        removes the value of staque which was added last time
       -----------------------------------------------------------------------*/

        if (!empty()) { //precondition
            Node* ptr;
            if (mySize == 1) {
                ptr = myTop;
                myTop = NULL;
                myBack = NULL;
            }
            else {
                if (myTop->order > myBack->order) { //the use of rank to consider which last to be deleted
                    ptr = myTop;
                    myTop = myTop->next;
                    myTop->prev = NULL;
                }
                else {
                    ptr = myBack;
                    myBack = myBack->prev;
                    myBack->next = NULL;
                }
            }
            mySize--;
            delete ptr;
        }
        else
            cerr << "/*** Staque is Empty ***/\n";  //precondition for removal that list should not be empty
    }

    void removeN(int number) {
        //removes the number of values which indicated by the user by calling removeLast n times
        if (empty() || number > mySize)
            cerr << "/*** Staque is Empty or you required more elements to be deleted than existed ***/\n";  ////precondition for removal that list should not be empty
        else {
            for (int i = 1; i <= number; i++)
                removeLast();
        }
    }

    void remove2E1O() {
        /*---------------------------------------------------
        function to remove 2 even and 1 odd numbers in staque if it exists
        -----------------------------------------------------*/
        //precondition that 2 even and 1 odd numbers exist
        if ((myTop->data) % 2 != 0 || (myTop->next->data) % 2 != 0 || (myBack->data) % 2 != 1 || mySize == 0) //precondition
            cerr << "/*** Deletion is impossible ***/\n";
        else {
            Node* ptr;
            for (int i = 0; i < 2; i++) {
                ptr = myTop;
                myTop = myTop->next;
                myTop->prev = NULL;
            }
            ptr = myBack;
            myBack = myBack->prev;
            myBack->next = NULL;
            mySize -= 3;
            delete ptr; //avoid leakage
        }
    }

private:
    /*** Node class ***/
    class Node
    {
    public:
        int data,
            order;
        Node* next,
            * prev;
        //--- Node constructor
        Node(int value) {
            /*-------------------------------------------------------------------
              constructor gets only integer value to initialize the node
              and sets the other variables 0 or NULL.
             -------------------------------------------------------------------*/
            data = value;
            order = 0;
            next = NULL;
            prev = NULL;
        }
    };

    /***** Data Members *****/
    Node* myTop;    // pointer to point the top of the stack
    Node* myBack;   // pointer to point the back of  the stack
    int mySize;     //number of nodes
}; // end of class declaration

ostream& operator << (ostream& o, Staque const& s) { //cout operator overloading
    s.display(o);
    return o;
}

#endif
