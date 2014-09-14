#include <iostream>
#include "LinkedListNotes.h"
//#include "LinkedListNotes.cpp"

using namespace std;

struct node{
	int x;
	node *next;	// this will be an address
};

int main()
{
    /*
	int a[4];
	for(int i = 0; i < 4; i++)
		cout << "address of a " << &a[i] << endl;

	// dynamic memory allocation
	int *iArray;
	iArray = new int[5]; //
	for(int z = 0; z < 5; z++){
		cout << iArray[z] << endl;
	}

	node *root;
	node *head;
	root = new node;

	// head and root point to the same place
	head = root;

	root->x = 5; // this will allows us to get to x. if not it woud be root.x

	// allocate memory for next node
	node *n1;
	n1 = new node; // give me space for something the size node.
	root->next = n1;

	cout << "address of n1 " << n1 << endl;
	cout << "address of root->next " << root->next << endl;

	int i = 0;
	while(i < 5){
		root = root->next;
		node *n2 = new node;
		n2->x = i+2;	 // this sets value of x in struct n2
		n2->next = 0; 	 // this sets value of next in struct n2
		root->next = n2;
		i++;
	}

	root = head;
	for(int j = 0; j < 5; j++){
		cout << root-> x << endl;
		root = root->next;
	}

	// header files
	CNode *classNode;
	classNode = new CNode(0);
	CNode *cHead;
	cHead = classNode; // store the starting location

	CNode *next;
	next = new CNode(1);
	classNode->setNext(next);

	i = 0;
	while(i < 5){
        CNode *next;
        next = new CNode(i+2);
        classNode = classNode->getNext();
        classNode->setNext(next);
        cout << classNode->getX() << endl;
        i++;
	}
	*/

	CNode *classNode = new CNode(0);
	CNode *next = new CNode(1);
	classNode->setNext(next);
	next->setPrevious(classNode);

	CNode *n1;
	CNode *n2;
	CNode *n3;
	n1 = new CNode(9);
	n2 = new CNode(1);
	n3 = new CNode(5);
	n2->setNext(n2);
	n2->setNext(n3);
	n3->setPrevious(n2);
	n2->setPrevious(n1);

	// we want to delete n2
	n1->setNext(n2->getNext()); // this is n3
	n3->setPrevious(n2->getPrevious()); // this is n1
	delete n2;

	// we want to add a new node n5 that contains a 3
	CNode *n5 = new CNode(99);
	// normal mode
	CNode *tmp;
	tmp = n1->getNext();    // this is node 3
	n1->setNext(n5);        // set n1 to point to n5 next
	n5->setPrevious(tmp->getPrevious()); // set n5 to point to n1
	tmp->setPrevious(n5);   // set n3 to point to n5 prev
	n5->setNext(tmp);        // set n5 to point to n3

	/*
	// not normal
	n1->setNext(n5);
	n3->setPrevious(n5)
	n5->setNext(n3);
	n5->setPrevious(n1);
	*/


	// linked list search
	CNode *head;
	head = n1;
	while(head->getNext() != 0 and head->getX() != 99){
        head = head->getNext();
	}

    cout << "value found " << head->getX() << endl;

    // garbage collection
    head = n1; // move back to the beginning
    CNode *cn;
    cn = n1->getNext();

    while(n1->getNext() != 0){
        cout << "deleting " << n1 << endl;
        delete n1;
        n1 = cn;
        cn = cn->getNext();
    }
    delete n1;

	return 0;
}
