#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

//////////////////////
//Node Functions
//////////////////////

// constructor and destructor
Node::Node(){
    string ship = "NULL";   // type
    bool occupy = 0;        // occupation
    bool hit = 0;           // hit bool

    Node* next = NULL;
    Node* prev = NULL;
}
Node::~Node(){}

// get set ship type
string Node::getShip(){
    return ship;
}
void Node::setShip(string type){
    ship = type;
}
// get set occupy
bool Node::getOccupy(){
    return occupy;
}
void Node::setOccupy(bool value){
    occupy = value;
}

// get set hit
bool Node::getHit(){
    return hit;
}
void Node::setHit(bool value){
    hit = value;
}

// get set Next
Node* Node::getNext(){
    return next;
}
void Node::setNext(Node* node){
    next = node;
}

// get set Previous
Node* Node::getPrev(){
    return prev;
}
void Node::setPrev(Node* node){
    prev = node;
}
