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

	return 0;
}
