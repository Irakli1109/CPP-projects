#include <iostream>
#include "BST.h"

using namespace std;

BST::BST()
    : myRoot(0)
{}

BST::~BST() { //destructor definition
    destructorAux(myRoot);
}

void BST::destructorAux(TreeNode* node) {
    if (node) {
        /*This deletion behaves like post order traverse
        **it first deleted left subtree, then right and
        **finally deletes their parent. LRP:left-right-parent
        */
        destructorAux(node->Lchild);
        destructorAux(node->Rchild);
        delete node;
    }
}

BST::BST(const BST& original) { //vopy constructor calls for auxilary function
    copyConstructorAux(this->myRoot, original.myRoot);
}

void BST::copyConstructorAux(TreeNode*& nodeTo, TreeNode* nodeFrom) const {
    if (nodeFrom == 0) { //if tree is empty
        nodeTo = 0;
    }
    else {
        nodeTo = new TreeNode(nodeFrom->item); //creating new node
        copyConstructorAux(nodeTo->Lchild, nodeFrom->Lchild); // calling left subtree
        copyConstructorAux(nodeTo->Rchild, nodeFrom->Rchild); //calling right subtree
    }
}

const BST& BST::operator=(const BST& rightHandSide) {
    if (this != &rightHandSide) {
        this->~BST();//first step is to destruct the exsisting BST
        copyConstructorAux(this->myRoot, rightHandSide.myRoot); //then to copy values from second tree
    }
    return *this; //return tree address
}

bool BST::empty() const {
    return myRoot == 0;  //just checks if root is 0
}

/*** Traversals ***/
void BST::inorder(ostream& out) const {  //inorder public traversal that calls auxiliary private function
    inorderAux(out, myRoot);
}

void BST::inorderAux(ostream& out, TreeNode* subtreePtr) const { //performing inorder LVR traversal
    if (subtreePtr != 0) {
        inorderAux(out, subtreePtr->Lchild);  //L
        out << subtreePtr->item << " ";       //V
        inorderAux(out, subtreePtr->Rchild);  //R
    }
}

void BST::preorder(ostream& out) const { //preorder public traversal that calls auxiliary private function
    preorderAux(out, myRoot);
}

void BST::preorderAux(ostream& out, TreeNode* subtreePtr) const { //VLR-preorder traversal
    if (subtreePtr != 0) {
        out << subtreePtr->item << " ";          //V
        preorderAux(out, subtreePtr->Lchild);    //L
        preorderAux(out, subtreePtr->Rchild);    //R
    }
}

void BST::postorder(ostream& out) const {//postorder public traversal that calls auxiliary private function
    postorderAux(out, myRoot);
}

void BST::postorderAux(ostream& out, TreeNode* subtreePtr) const { //LRV-preorder traversal
    if (subtreePtr != 0) {
        postorderAux(out, subtreePtr->Lchild);    //L
        postorderAux(out, subtreePtr->Rchild);    //R
        out << subtreePtr->item << " ";           //V
    }
}

bool BST::search(const int& data) const {
    return searchAux(myRoot, data);   //search uses private searchAux method
}

bool BST::searchAux(TreeNode* subtreeRoot, const int& data) const {
    if (subtreeRoot == 0)  //if subtree is empty
        return false;  //not found
    if (data < subtreeRoot->item) //goto left subtree
        return searchAux(subtreeRoot->Lchild, data);
    else if (data > subtreeRoot->item) //goto right subtree
        return searchAux(subtreeRoot->Rchild, data);
    else
        return true; //found
}

void BST::insert(const int& data) { //inserting item in the tree with BST condition (iterating way)
    TreeNode* locPtr = myRoot;
    TreeNode* parent = 0;
    bool found = false; //checking if item is in BST

    while (!found && locPtr != 0) {
        parent = locPtr;
        if (data < locPtr->item) // goto left subtree
            locPtr = locPtr->Lchild;
        else if (locPtr->item < data) //goto right subtree
            locPtr = locPtr->Rchild;
        else
            found = true; //value was found in BST
    }
    if (!found) { //if item is not in BST
        locPtr = new TreeNode(data); //construct new node with specified value at item
        if (parent == 0)   //BST is empty
            myRoot = locPtr;
        else if (data < parent->item) //inserting to the left
            parent->Lchild = locPtr;
        else //inserting to the right
            parent->Rchild = locPtr;
    }
    else //if found value in BST
        cerr << "Item is already in the BST!!!\n";
}


void BST::remove(const int& data)
{
    bool found; // cheking if item is found
    TreeNode* x; //node which should be deleted
    TreeNode* parent; //x's parent node

    search2(data, found, x, parent);
    if (!found) { //if item is not in BST
        cerr << "Item is not in BST!!!\n";
        return;
    }
    if (x->Lchild != 0 && x->Rchild != 0) { //case when node has 2 child
        TreeNode* xSucc = x->Rchild;
        parent = x;
        while (xSucc->Lchild != 0) { //finding x's successor
            parent = xSucc;
            xSucc = xSucc->Lchild;
        }
        x->item = xSucc->item; //move xSucc to x and then change x
        x = xSucc;
    }
    // case when node has 0 or 1 child
    TreeNode* subtree = x->Lchild;
    if (subtree == 0) //there is no child on left
        subtree = x->Rchild;

    if (parent == 0)  //if only root is in BST
        myRoot = subtree; //remove root
    else if (parent->Lchild == x) //left child of parent
        parent->Lchild = subtree;
    else
        parent->Rchild = subtree;

    delete x; //freeing memory of x
}

void BST::search2(const int& data, bool& found, TreeNode*& locPtr, TreeNode*& parent) const {
    locPtr = myRoot; //pointing to the root
    parent = 0; //root does not have a parent
    found = false; //set found false

    while (!found && locPtr != 0) { //until not found and node adress is 0
        if (data < locPtr->item) {//goto left subtree
            parent = locPtr;
            locPtr = locPtr->Lchild;
        }
        else if (locPtr->item < data) {//goto right subtree
            parent = locPtr;
            locPtr = locPtr->Rchild;
        }
        else  //item found
            found = true;
    }
}

void BST::display(ostream& out)const { //display method call preorder traversal
    preorder(out);
}

ostream& operator<<(ostream& out, const BST& object) { //operator overloading
    object.display(out);
    return out;
}
