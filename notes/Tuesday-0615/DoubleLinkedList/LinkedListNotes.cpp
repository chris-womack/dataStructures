#include "LinkedListNotes.h"
#include <iostream>

using namespace std;

CNode::CNode(int value){
    x = value;
    next = 0;
    previous = 0;
}

CNode::~CNode(){
    cout << "destructor" << endl;
}

void CNode::setNext(CNode *n){
    next = n;
}

CNode* CNode::getNext(){
    return next;
}

void CNode::setPrevious(CNode *n){
    previous = n;
}

CNode* CNode::getPrevious(){
    return previous;
}

void CNode::setX(int xIn){
    this->x = x;
}

int CNode::getX(){
    return x;
}
