// Chris Womack
// Dr. Hoenigman
// Lab 9

#ifndef LINKEDLISTEX_H_INCLUDED
#define LINKEDLISTEX_H_INCLUDED

#include <string>

using namespace std;

class City{
private:
	string name;        // key
	City *leftChild;    // left
	City *rightChild;   // right
	City *prev;         // previous
	City *next;         // next
	City *parent;       // parent


public:
	// constructor/destructor
	City(string);
	~City();

	// get and set left
	City *getLeftChild();
	void setLeftChild(City *n);

	// get and set right
	City *getRightChild();
	void setRightChild(City *p);

	// get and set prev
	City *getPrev();
	void setPrev(City *n);

	// get and set next
	City *getNext();
	void setNext(City *p);

	// get and set parent
	City *getParent();
	void setParent(City *p);

	// get and set name
    string getName();
    void setName(string l);
};


class Stack{
private:
    // stack nodes
    City *Head;
    City *Next;
    City *Tail;
    City *tmp_s;

public:
    Stack(City* root);
    ~Stack();

    Stack* build(int* stack_count);
    Stack *print(int*);
    Stack *del(int*);
};

class Tree{
private:
    // city nodes
    City *root;     // root node of tree
    City *tmp_t;

public:
    Tree();
    ~Tree();

    // add a city given parent and new city
    void addCity(City *Node, string prnt_city, string new_city, int *city_count);
    int CountNodes(City *Node);
    int CountNodes_R(City *Node);
};

#endif // LINKEDLISTEX_H_INCLUDED
