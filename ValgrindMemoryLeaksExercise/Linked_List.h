//	Ian Smith
//	CSCI - 2270
//	Summer 2014
//
//	FILE: Linked_List.h
//
//	Header file for the singly linked list class

#ifndef LL_H
#define LL_H

#include "Node.h"

class Linked_List {
	private:
		/*************
		 * 	ATTRIBUTES
		 **************/
		 Node * head;

	public:
		/*************
		 * 	CONSTRUCTORS
		 **************/
		Linked_List();
		/*************
		 * 	DESTRUCTOR
		 **************/
		~Linked_List();
////NOTE:
////Yes, I used getter/setter in the last class, and yes I am using accessor/mutator in this one.
////	Literally no one in our field can agree on what to call these. I can't even agree with myself.
		/*************
		 * 	ACCESSORS
		 **************/
		int getLength();
		Node * first();
		Node * nth(int index);
		/*************
		 * 	MUTATORS
		 **************/
		void insert(int value, int index);
		Node * remove(int index);

};
#endif
