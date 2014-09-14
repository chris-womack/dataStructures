#include <iostream>
#include "linkedListEx.h"

using namespace std;

CNode::CNode(int value){
	x = value;
    next = 0;
    previous = 0;
}

CNode::~CNode(){
    cout<<"calling destructor"<<endl;
}

void CNode::setNext(CNode *n){
    next = n;
}
CNode* CNode::getNext(){
	return next;
}

void CNode::setPrevious(CNode *p){
    previous = p;
}
CNode* CNode::getPrevious(){
	return previous;
}

void CNode::setX(int xIn){
    x = xIn;
}

int CNode::getX(){
    return x;
}
