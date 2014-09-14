#include "LinkedListNotes.h"

using namespace std;

CNode::CNode(int value){
    x = value;
    next = 0;
}

CNode::~CNode(){}

void CNode::setNext(CNode *n){
    next = n;
}

CNode* CNode::getNext(){
    return next;
}

void CNode::setX(int xIn){
    this->x = x;
}

int CNode::getX(){
    return x;
}
