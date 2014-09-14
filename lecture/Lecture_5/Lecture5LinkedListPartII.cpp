#include <iostream>
#include "linkedListEx.h"

//double linked list
//insert a node
//search the list
//remove a node

using namespace std;

int main()
{
    /*Doubly linked lists contain a pointer going forward and backward,
    not just forward as we saw with the singly linked list. Using the class
    classNode from yesterday, we need to set the previous pointer for each
    instance we create.
    */
    CNode *classNode;
    classNode = new CNode(0);
    cout<<classNode<<endl;

    //save the beginning for later
    CNode *head;
    head = classNode;

    //create what classNode points to
    CNode *next;
    next = new CNode(1);
    classNode->setNext(next);
    //we also need to set the previous for next.
    //there's no previous for classNode, since it's the beginning
    next->setPrevious(classNode);

    //repeat example from yesterday, adding the previous pointer
    int i = 2;
    while(i < 7){
        next = new CNode(i);
        classNode = classNode->getNext();
        classNode->setNext(next);
        next->setPrevious(classNode);
        i++;

    }
    //lets go backwards through the list
    //move to the end
    classNode = next;
    /*classNode should be pointing to last address
        because that's where we left it when we exited loop
    We can go backwards by getting the previous until previous
    is null, then we know we've reached the beginning.
    */
    //this gets the previous address, but doesn't change anything
    while(classNode->getPrevious()!=0){
        cout<<classNode->getX()<<endl;
        classNode = classNode->getPrevious();//move to previous
        //we're not setting anything because linked list
        //already set up

    }
    //are we back to the beginning?
    //classNode should match where we started
    cout<<classNode<<endl;

    /*The real value of linked lists is we can add and remove nodes without
    needing to shift a bunch of items. For example, insert something into the
    beginning of the list*/
    //first, deleting
    //I'm going to remove the second item in the list
    /*we need to know what it's next and previous are so that we can keep
    them and re-route the connections to bypass the item*/
    //set this up like pseudocode
    CNode *n1;
    CNode *n2;
    CNode *n3;
    //this is the first in the list
    n1 = head;
    n2 = n1->getNext();
    n3 = n2->getNext();
    //print values to n1, n2, n3 to verify results
    cout<<"n1="<<n1->getX()<<endl;
    cout<<"n2="<<n2->getX()<<endl;
    cout<<"n3="<<n3->getX()<<endl;

    n1->setNext(n2->getNext());//could also use n3
    n3->setPrevious(n2->getPrevious());
    /*there's no way to access what was n2 anymore, the pointers
    to it have been removed. We need to delete it to free the memory,
    otherwise, we have memory leak*/
    //remove n2
    delete n2;

    //how would we test that this process worked?
    classNode = head;
    while(classNode->getNext()!=0){
        cout<<classNode->getX()<<endl;
        classNode = classNode->getNext();
    }
    //this is the list_insert pseudocode on page 238
    //we stored the head of the linked list, we'll use it here
    CNode *newNode;
    //we are adding something, we need to allocate the memory
    //not just using a reference to an existing CNode instance
    //order matters here
    newNode = new CNode(99);
    CNode *tmp;
    tmp = head->getNext(); //this is current next
    head->setNext(newNode); //set a new next
    newNode->setNext(tmp);

    //searching, find the node with a 99
    //we're not putting this in a function, but you could
    //start at the beginning
    classNode = head;
    int k = 99; //key to find
    //the loop until found or the end
    while(classNode->getNext()!=0 && classNode->getX()!=k){
        classNode = classNode->getNext();
    }
    cout<<"value found: "<<classNode->getX()<<endl;

    //now, lets destroy everything
    classNode = cHead;
    cout<<"starting class garbage collection"<<endl;
    CNode *cn;
    cn = classNode->getNext();
    while(classNode->getNext() != 0){
        cout<<"deleting"<<classNode<<endl;
        delete classNode; //free the memory
        classNode = cn;
        cn = cn->getNext();
    }

    return 0;
}
