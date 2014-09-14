#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Node{
private:
    string ship;
    bool occupy;
    bool hit;

    Node* next;
    Node* prev;
public:
    Node();
    ~Node();

    string getShip();
    void setShip(string type);

    bool getOccupy();
    void setOccupy(bool value);

    bool getHit();
    void setHit(bool value);

    Node* getNext();
    void setNext(Node* node);

    Node* getPrev();
    void setPrev(Node* node);
};

#endif // NODE_H_INCLUDED
