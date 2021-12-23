#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

class TreeNode {

    friend class BST; //BST could access all members from TreeNode

public:

    TreeNode();  //default constructor

    TreeNode(int i, TreeNode* L = 0, TreeNode* R = 0); //explicit value constructor

    int getItem() const; // accessor function

private:
    /*** Members for TreeNode ***/
    int item;
    TreeNode* Lchild;
    TreeNode* Rchild;
};

inline TreeNode::TreeNode() { //Treenode default constructor
    Lchild = Rchild = NULL;
}


inline TreeNode::TreeNode(int i, TreeNode* L, TreeNode* R) //TreeNode explicit value constructor
    : item(i), Lchild(L), Rchild(R) //initializer list
{}


inline int TreeNode::getItem() const { //getter for TreeNode item
    return item;
}

#endif
