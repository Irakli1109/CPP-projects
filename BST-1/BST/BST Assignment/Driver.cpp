#include <iostream>

using namespace std;
#include "BST.h"

int main() {
    BST myTree;
    myTree.insert(10);
    myTree.insert(20);
    myTree.insert(30);
    myTree.insert(15);
    myTree.insert(5);
    myTree.insert(4);
    myTree.insert(6);

    cout << "After all insertions:\n\n";
    cout << "Inorder   --  ";
    myTree.inorder(cout);
    cout << endl << "Preorder  --  ";
    cout << myTree;
    cout << endl << "Postorder --  ";
    myTree.postorder(cout);

    myTree.remove(15);
    cout << "\n\nAfter the deletion of 15:";

    cout << "\n\nInorder   --  ";
    myTree.inorder(cout);
    cout << endl << "Preorder  --  ";
    cout << myTree;
    cout << endl << "Postorder --  ";
    myTree.postorder(cout);

    myTree.remove(10);
    cout << "\n\nAfter the deletion of 10:";

    cout << "\n\nInorder   --  ";
    myTree.inorder(cout);
    cout << endl << "Preorder  --  ";
    cout << myTree;
    cout << endl << "Postorder --  ";
    myTree.postorder(cout);

    cout << "\n\nAfter the deletion of 100:\n";
    myTree.remove(100);

    cout << "\nInorder   --  ";
    myTree.inorder(cout);
    cout << endl << "Preorder  --  ";
    cout << myTree;
    cout << endl << "Postorder --  ";
    myTree.postorder(cout);

    myTree.insert(50);
    cout << "\n\nAfter the insertion of 50:";

    cout << "\n\nInorder   --  ";
    myTree.inorder(cout);
    cout << endl << "Preorder  --  ";
    cout << myTree;
    cout << endl << "Postorder --  ";
    myTree.postorder(cout);

    cout << "\n\nAfter the insertion of 5:\n";
    myTree.insert(5);

    cout << "\nInorder   --  ";
    myTree.inorder(cout);
    cout << endl << "Preorder  --  ";
    cout << myTree;
    cout << endl << "Postorder --  ";
    myTree.postorder(cout);

    cout << "\n\nIs BST empty?\n" << "Returned: " << myTree.empty();

    cout << "\n\nIs Element 10 in BST?\n" << "Returned: " << myTree.search(10);

    cout << "\n\nIs Element 50 in BST?\n" << "Returned: " << myTree.search(50);
    cout << endl;

    BST obj = myTree;
    cout << endl << "Used copy constructor -- " << obj << endl;
    cout << "Initial Binary Tree   -- " << myTree << endl;

    BST obj1;
    obj1.insert(100);
    obj1.insert(50);
    obj1.insert(200);
    obj1.insert(25);
    obj1.insert(75);
    obj1.insert(150);

    cout << "\nAnother tree After insertions  -- " << obj1;
    obj1 = myTree; //assiging new values

    cout << "\nTree after assignment operator -- " << obj1 << endl;

    return 0;
}
