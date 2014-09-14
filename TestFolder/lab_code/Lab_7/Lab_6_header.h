// Chris Womack
// Dr. Hoenigman
// Lab_7

#ifndef LAB_6_HEADER_H_INCLUDED
#define LAB_6_HEADER_H_INCLUDED
#include <string>   // needed for the string type to be defined

using namespace std;

class Link{
private:
    int integer;
    Link *next;
    Link *prev;

public:
    Link(int);      // constructor
    ~Link();        // destructor

    // get and set next
    Link *getNext();
    void setNext(Link *n);

    // get and set previous
    Link *getPrev();
    void setPrev(Link *n);

    // get and set integer
    int getInt();
    void setInt(int);

    Link *push(Link*, int*);
    Link *pop(Link*, int*);

};

void enquArr(int*, int*, int*, int*, int*, int*);
void dequArr(int*, int*, int*, int*, int*, int*);
void printquArr(int*, int*, int*, int*, int*, int*);

int stackBump(int, int);

void stackArray();
void stackLinked();
void stackDblinked();

void queueArray();
void queueLinked();
void queueDblinked();

void garbageCollection();

#endif // LAB_6_HEADER_H_INCLUDED
