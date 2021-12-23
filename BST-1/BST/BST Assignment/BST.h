#ifndef BST_H
#define BST_H

#include <iostream>
#include "TreeNode.h"
using namespace std;

class BST {

public:
    BST();//constructor
    ~BST();//destructor
    BST(const BST& original); //copy constructor
    const BST& operator=(const BST& rightHandSize); //assignment operator
    bool empty() const; //checking if tree is empty
    void inorder(ostream& out) const; //LVR
    void preorder(ostream& out) const; //VLR
    void postorder(ostream& out) const; //LRV
    bool search(const int& data) const; //searching for item in tree
    void insert(const int& data); //inserting item in tree by BST condition
    void remove(const int& data); //removing tree just like to not violate BST condition
    void display(ostream& out) const; //displaying tree in preorder fashion

private:

    void destructorAux(TreeNode* node); //helper for destructor
    void copyConstructorAux(TreeNode*& nodeTo, TreeNode* nodeFrom) const; //helper for copy constructor
    void inorderAux(ostream& out, TreeNode* subtreePtr) const; //helper method for inorder method
    void preorderAux(ostream& out, TreeNode* subtreePtr) const; //helper method for preorder method
    void postorderAux(ostream& out, TreeNode* subtreePtr) const; //helper method for postorder method
    bool searchAux(TreeNode* subtreeRoot, const int& data) const; //helper for search method
    void search2(const int& data, bool& found, TreeNode*& locPtr, TreeNode*& parent) const; //needed for removal
    /*** Data Member ***/
    TreeNode* myRoot; // pointer to the SBT root
};
ostream& operator<<(ostream& out, const BST& object); //operator overloading
#endif
