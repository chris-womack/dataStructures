// Chris Womack
// Dr. Hoenigman
// Lab 9

#include <iostream>
#include "TreeClass.h"
#include <string>
using namespace std;

//***************************************************************************//
// City Nodes
//***************************************************************************//
City::City(string n){
	name = n;
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
    next = NULL;
    prev = NULL;
}
City::~City(){
    cout<<"calling destructor"<<endl;
}

// get set left
void City::setLeftChild(City *n){
    leftChild = n;
}
City* City::getLeftChild(){
	return leftChild;
}

// get set right
void City::setRightChild(City *n){
    rightChild = n;
}
City* City::getRightChild(){
	return rightChild;
}

// get set prev
void City::setPrev(City *n){
    prev = n;
}
City* City::getPrev(){
	return prev;
}

// get set next
void City::setNext(City *n){
    next = n;
}
City* City::getNext(){
	return next;
}

// get set parent
void City::setParent(City *n){
    parent = n;
}
City* City::getParent(){
	return parent;
}

// get set name
string City::getName(){
    return name;
}
void City::setName(string l){
    name = l;
}

//***************************************************************************//
// Stack Double (Functionality is the same but next is set)
//***************************************************************************//
// stack constructor
Stack::Stack(City* root){
    Head = root;
    Next = Head;
    Tail = Head;
    tmp_s = NULL;
}
// stack destructor
Stack::~Stack(){}

Stack* Stack::build(int *stack_count){
    bool check = 0; // check to see if head node is full

    // head with no children
    if(Head->getLeftChild() == NULL and Head->getRightChild() == NULL){
        (*stack_count)++;
    // head with only left child
    }else if(Head->getLeftChild() != NULL and Head->getRightChild() == NULL){
        Head->setNext(Head->getLeftChild());
        Head->getNext()->setPrev(Head);
        Tail = Tail->getNext();

        Next = Next->getNext();
        (*stack_count)++;
        (*stack_count)++;
        check = 0;

        cout << endl << "in head loop 2" << endl;
    // head with left and right child
    }else if(Head->getLeftChild() != NULL and Head->getRightChild() != NULL){
        Head->setNext(Head->getLeftChild());
        Head->getNext()->setPrev(Head);
        Head->getNext()->setNext(Head->getRightChild());
        Tail = Tail->getNext()->getNext();

        Next = Next->getNext();
        (*stack_count)++;
        (*stack_count)++;
        check = 1;
    }

    // all other nodes
    if(*stack_count == 2 and check == 1){
        while(true){
            // nodes with no children
            if(Next->getLeftChild() == NULL and Next->getRightChild() == NULL){
                Next = Next->getNext();
                (*stack_count)++;
            // nodes with left child
            }else if(Next->getLeftChild() != NULL and Next->getRightChild() == NULL){
                Tail->setNext(Next->getLeftChild());
                Tail = Tail->getNext();
                Next = Next->getNext();
                (*stack_count)++;
            // nodes with left and right child
            }else if(Next->getLeftChild() != NULL and Next->getLeftChild() != NULL){
                Tail->setNext(Next->getLeftChild());
                Tail->getNext()->setNext(Next->getRightChild());
                Tail = Tail->getNext()->getNext();
                Next = Next->getNext();
                (*stack_count)++;
            }

            // if the next pointer catches the tail and no children we have reached the end of the stack
            if(Next == Tail and Next->getLeftChild() == NULL and Next->getRightChild() == NULL){
                break;
            }

        }
    }
}

// Stack print (no changes for double implementation)
Stack* Stack::print(int *stac_count){
    tmp_s = Tail->getPrev();  // set tmp to previous node
    if((*stac_count) == 0){
        cout << "Stack is empty, push values to stack to print" << endl;
    }else{
        while(tmp_s != NULL){                 // continue till tmp is at bottom of stack
            cout << tmp_s->getName() << endl;  // print the int value at current node
            tmp_s = tmp_s->getPrev();           // move tmp to previous node
        }
    }
}
// delete current node left in stack
Stack* Stack::del(int *stac_count){
    tmp_s = Tail;
    Tail = Tail->getPrev();
    delete tmp_s;
    (*stac_count)--;
}


//***************************************************************************//
// Tree Class
//***************************************************************************//
Tree::Tree(){
    root = NULL;
    tmp_t = NULL;
}
Tree::~Tree(){
        //will need to delete all cities in the tree
}

// adds city using recursion
void Tree::addCity(City* Node, string prnt_city, string new_city, int * city_count){
            // check for a left node and the name
            if(Node->getLeftChild() != NULL && Node->getName() != prnt_city){
                cout << "going down left" << endl;
                // call addCity again traversing downt the left node
                addCity(Node->getLeftChild(), prnt_city, new_city, city_count);
                cout << "returning left" << endl;
            }
            // check for a right node and the name
            if(Node->getRightChild() != NULL && Node->getName() != prnt_city){
                cout << "going down right" << endl;
                // call addCity again traversing down the right node
                addCity(Node->getRightChild(), prnt_city, new_city, city_count);
                cout << "returning right" << endl;
            }

            // once the previous code finds the node
            if(Node->getName() == prnt_city){
                tmp_t = new City(new_city);               // create new node
                cout << "New city created" << endl;
                // try to set left first
                if(Node->getLeftChild() == NULL){
                    Node->setLeftChild(tmp_t);
                    (*city_count)++;
                    cout << "Left Node added" << endl;
                // then if not NULL set right
                }else if(Node->getRightChild() == NULL){
                    Node->setRightChild(tmp_t);
                    (*city_count)++;
                    cout << "Right Node added" << endl;
                }else{
                    cout << "The Parent Node is full." << endl;
                }
            }
}

int Tree::CountNodes(City *Node){
    int stack_count = 0;

    // create stack
    Stack *stac = new Stack(Node);

    // build the stack everytime
    stac->build(&stack_count);
    return stack_count;
}

int Tree::CountNodes_R(City *Node){
    // empty tree
    if(Node == NULL){
        cout << "City tree is empty, please add cities." << endl;
    // base case: node with no children
    }else if(Node != NULL and Node->getLeftChild() == NULL and Node->getRightChild() == NULL){
        return 1;
    // all other cases
    }else{
        // case 1: node with two children
        if(Node->getLeftChild() != NULL and Node->getRightChild() != NULL){
            return (CountNodes_R(Node->getLeftChild()) + CountNodes_R(Node->getRightChild()) + 1);
        // case 2: node with only a left child
        }else if(Node->getLeftChild() != NULL and Node->getRightChild() == NULL){
            return (CountNodes_R(Node->getLeftChild()) + 1);
        }
    }
}

