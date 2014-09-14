//	Ian Smith
//	CSCI - 2270
//	Summer 2014
//
//	FILE: Stack.h
//
//	Header file for stack class

#include "Linked_List.h"
#include "Double_Linked_List.h"
#include "Node.h"

#ifndef STACK_H
#define STACK_H

class Stack {
	private:
		/*************
		 * 	ATTRIBUTES
		 **************/
		int option;
		int index;
		int * array;
		Linked_List * sLL;
		Double_Linked_List * dLL;
		/*************
		 * 	HELPER FUNCTIONS
		 **************/
////NOTE:
//// Helper functions are private functions that are only there to be used by the class
//// to make its own job easier. You can't call these from outside the class!
////	The list of public functions is often referred to as the API.
////	By only allowing the user to interact with your class in certain ways you can
////	make sure they won't accidentally break anything and then blame you.
		void printArray();
		void printSLL();
		void printDLL();
	public:
		/*************
		 * 	CONSTRUCTORS
		 **************/
		Stack();
		Stack(int option);
		/*************
		 * 	DESTRUCTORS
		 **************/
		~Stack();
		/*************
		 * 	ACCESSORS
		 **************/
////NOTE:
//// Why might I put the print in the stack class instead of in the list classes themselves?
		void print();
		/*************
		 * 	MUTATORS
		 **************/
		void push(int value);
		Node * pop();
};
#endif
