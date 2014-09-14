#include <iostream>
#include "TreeClass.h"
#include <string>

/*With the linked lists we've worked with so far, each node had at most
two pointers to other nodes. In the double-linked list, there was a next
and previous pointer.

When we look at tree structures, it's for data where next and previous is
not enough. We need to create a hierarchical structure, or a structure where
there are multiple paths from each node. For example, instead of having one
link between cities, we could have links to multiple cities.

In a tree, there is a parent node, and the parent has child nodes. For the
trees we will look at here, the parent has at most two children. This is what
makes it a binary tree, there are two possible choices from each parent.

For our nodes, we'll use classes.

Need a tree class and a node class.

*/

using namespace std;

//recursively print cities in the tree
void printCityNames(City *root){
    if(root->getLeftChild()!=NULL)
        printCityNames(root->getLeftChild());
    if(root->getRightChild()!=NULL)
        printCityNames(root->getRightChild());
    cout<<root->getName()<<endl;

}
//recursively counting up from 0
void myFunction(int counter)
{
    if(counter == 0) //this is base case
        return;
    else{
//        cout <<counter<<endl;
        myFunction(--counter);
        //return to here
        cout <<counter<<endl;
       return;
    }
}

int main()
{
    //recursion
    myFunction(10);


    //This example just uses the City nodes, they're not
    //part of the Tree class yet.
    City *next;
    next = new City("Denver");
    City *root = next;
    cout<<root<<" "<<next<<endl;

    City *left = new City("Las Vegas");
    City *right = new City("Chicago");
    next->setLeftChild(left);
    next->setRightChild(right);

    //move to the left child
    next = next->getLeftChild();
    next->setParent(root);
    //create two new cities
    left = new City("Los Angeles");
    right = new City("Dallas");
    next->setLeftChild(left);
    next->setRightChild(right);

    next = next->getLeftChild();
    right = new City("Seattle");
    next->setRightChild(right);

    //print names of the cities, starting at root
    printCityNames(root);

    //Things to consider in building the tree:
    //what are the properties of the nodes?
    //what are the properties of the tree?
    Tree *tree;
    tree = new Tree();
    tree->addCity("Denver");

    return 0;
}
