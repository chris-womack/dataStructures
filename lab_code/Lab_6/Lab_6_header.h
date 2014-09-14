// Chris Womack
// Dr. Hoenigman
// Assignment II

#ifndef LAB_6_HEADER_H_INCLUDED
#define LAB_6_HEADER_H_INCLUDED

using namespace std;

class Node{
private:
    int integer;
    Node* next;
    Node* prev;
public:
    Node(int);      // constructor
    ~Node();     // destructor

    // get and set next
    Node *getNext();
    void setNext(Node*);

    // get and set previous
    Node *getPrev();
    void setPrev(Node*);

    // get and set integer
    int getInt();
    void setInt(int);

};

class Stack{
private:
    Node* Head;
    Node* Tail;
    Node* tmp;
public:
    Stack();      // constructor
    ~Stack();     // destructor

    Stack *push(int*);
    Stack *pop(int*);
    Stack *print(int*);
    Stack *del(int*);
};


class StackD{
private:
    Node* Head;
    Node* Tail;
    Node* tmp;
public:
    StackD();      // constructor
    ~StackD();     // destructor

    StackD *push(int*);
    StackD *pop(int*);
    StackD *print(int*);
    StackD *del(int*);
};

class Que{
private:
    Node* Head;
    Node* Tail;
    Node* tmp;
public:
    Que();      // constructor
    ~Que();     // destructor

    Que *enqu(int*);
    Que *deq(int*);
    Que *print(int*);
    Que *del(int*);
};

class QueD{
private:
    Node* Head;
    Node* Tail;
    Node* tmp;
public:
    QueD();      // constructor
    ~QueD();     // destructor

    QueD *enqu(int*);
    QueD *deq(int*);
    QueD *print(int*);
    QueD *del(int*);
};

void enquArr(int*, int*, int*, int*, int*, int*);
void dequArr(int*, int*, int*, int*, int*, int*);
void printquArr(int*, int*, int*, int*, int*, int*);

int stackBump(int, int);

void stackArray();
void stacklinked();
void stackDblinked();

void queueArray();
void queuelinked();
void queueDblinked();

void garbageCollection();

#endif // LAB_6_HEADER_H_INCLUDED
