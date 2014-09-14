//	Ian Smith
//	CSCI - 2270
//	Summer 2014
//
//	FILE: Node.cpp
//
//	Implementation file for node class

#include "Node.h"

/*************
* 	CONSTRUCTORS
**************/
///Default constructor
///	I doubt this will ever be used, but it is good form to
///	ALWAYS have a default constructor. You never know how
///	your class is going to be used down the line.
Node::Node(){
	this->value = 0;
	this->next = 0;
	this->previous = 0;
}
///Constructor that accepts a starting value
Node::Node(int new_val){
	this->value = new_val;
	this->next = 0;
	this->previous = 0;
}
///Constructor that accepts a starting value, and starting pointers
Node::Node(int new_val, Node * new_next, Node * new_previous){
	this->value = new_val;
	this->next = new_next;
	this->previous = new_previous;
}
/*************
 * 	DESCTRUCTOR
 **************/
Node::~Node(){
	///Good practice to zero out pointers that are no longer in use
	///	Because this node is being destroyed if this function is called,
	///	we know these (should) be no longer in use
	next = 0;
	previous = 0;
}
/*************
 * 	GETTERS
 **************/
////Pretty straightforward here, just a getter to match each attribute.
int Node::getValue(){
	return this->value;
}
Node * Node::getNext(){
	return this->next;
}
Node * Node::getPrevious(){
	return this->previous;
}
/*************
 * 	SETTERS
 **************/
////One setter to match each attribute
void Node::setValue(int new_val){
	this->value = new_val;
}
void Node::setNext(Node * new_next){
	this->next = new_next;
}
void Node::setPrevious(Node * new_previous){
	this->previous = new_previous;
}
