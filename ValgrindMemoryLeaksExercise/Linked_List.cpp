//	Ian Smith
//	CSCI - 2270
//	Summer 2014
//
//	FILE: Linked_List.cpp
//
//	Implementation file for the singly linked list class

#include "Node.h"
#include "Linked_List.h"

/*************
 * 	CONSTRUCTORS
 **************/
Linked_List::Linked_List(){
	head = 0;
}
/*************
 * 	DESTRUCTOR
 **************/
Linked_List::~Linked_List(){
	///Linked list is being destroyed!
	///Make sure everything is deleted
	Node * tmp;
	while(head != 0){
		tmp = head->getNext();
		delete head;
		head = tmp;
	}
}
/*************
 * 	ACCESSORS
 **************/
 ///Returns the length of the list
int Linked_List::getLength(){
////NOTE:
////There are two ways I could do this: have an attribute that keeps track of the length, or calculate it each time.
////	What are the trade-offs of doing it one way or the other?

	int count = 0;
	Node * tmp = this->head;	//Start at the head
	while (tmp != 0){			//Loop through the list until the end
		tmp = tmp->getNext();
		count++;
	}
	return count;
 }
////NOTE:
////The following two functions are standard list operations, because you can access every element in the list just by calling these two functions.
///This is a standard list function. Return the first thing in the list.
Node * Linked_List::first(){
	return this->head;
}
///This is also a standard list function. Return a pointer to the element at a specific index.
Node * Linked_List::nth(int index){
	int count = 0;
	Node * tmp = head;
	while(count != index){
		tmp = tmp->getNext();
		count++;
	}
	return tmp;
}
/*************
 * 	MUTATORS
 **************/
///Insert a value at the specified index
void Linked_List::insert(int value, int index){
	///Edge case: inserting at start of list
	if (index == 0){
////NOTE:
////I'll do crap like this a lot in these files: use a variable on both the left and right side of an assignment statement.
//// Why is this okay? Should I be worried about head being overwritten before it gets used on the right side?

		head = new Node(value,head,0);	//Create a new node with the given value that points at the previous head
										//Then set head = new node
	}
	///General case: inserting into middle of list
	else {
		int count = 0;	//Make a count to keep track of what index we are at
		Node * tmp = head;	//Make a tmp pointer to help us walk through the list
		///Loop until we are at the spot before the index we want to insert at
		while (count != index-1){
			///If tmp == 0, the user tried to insert off the end of the list
			///	return gracefully to avoid a seg fault
			if (tmp == 0){
				return;
			}
			tmp = tmp->getNext();	//Continue walking down list
			count++;	//Increment count to keep index
		}
////NOTE:
////Here I am again playing fast and loose with order of operations.
//// Why does the following statement not crash and burn terribly?

		tmp->setNext(new Node(value,tmp->getNext(),0));	//Set the next pointer of tmp (which points to index-1) to the new node so that it will be at index
														//The new node will have the value passed in, and a next pointer that points to what used to be at index (tmp.getNext())
	}
}
///Remove a node at the specified index
Node * Linked_List::remove(int index){
	if (this->head == 0){
		return 0;
	} else {
		///This function is very similar to the insert function above!
		Node * tmp;
		if (index == 0){
			tmp = this->head;
			this->head = this->head->getNext();
			return tmp;
		} else {
			int count = 0;
			tmp = head;
			while (count != index-1){	//Why not stop at index instead of index-1?
				if (tmp == 0){
					return 0;
				}
				tmp = tmp->getNext();
				count++;
			}
			Node * tmp2 = tmp->getNext();
			tmp->setNext(tmp2->getNext());
			return tmp2;
		}
	}
}
