//	Ian Smith
//	CSCI - 2270
//	Summer 2014
//
//	FILE: Stack.cpp
//
//	Implementation file for stack class

#include <iostream>
#include "Node.h"
#include "Linked_List.h"
//#include "Double_Linked_List.h"
#include "Stack.h"


/*************
 * 	HELPER FUNCTIONS
 **************/
///Helper function to print if the stack is an array
void Stack::printArray(){
	std::cout << "PRINTING STACK\n";
	std::cout << "TOP\n";
	///Loop through the array and print each element
	for (int i=0;i<index;i++){
		std::cout << this->array[i] << "\n";
	}
	std::cout << "BOTTOM\n";
}
///Helper function to print if the stack is a sLL
void Stack::printSLL(){
	Node * tmp = this->sLL->first();
	std::cout << "PRINTING STACK\n";
	std::cout << "TOP\n";
	///Walk through the list by following the chain of pointers, and print each node
	while (tmp != 0){
		std::cout << tmp->getValue() << "\n";
		tmp = tmp->getNext();
	}
	std::cout << "BOTTOM\n";
}

/*************
 * 	CONSTRUCTORS
 **************/
///Default constructor. If the user doesn't choose a data structure, I will choose for them.
Stack::Stack(){
	option = 1;	//Default to sLL. I think it is the most efficient for stacks.
	this->sLL = new Linked_List();
}
///Accepts a choice from the user and then creates the appropriate data structure
Stack::Stack(int new_option){
	this->option = new_option;
	if (this->option == 0){
		this->array = new int[10];	//This is the way to dynamically allocate an array
									//Doing this means that memory won't be used if I decide on sLL or dLL instead
		this->index = 0;
	}else if (this->option == 1){
		this->sLL = new Linked_List();
	}
}
/*************
 * 	DESTRUCTORS
 **************/
Stack::~Stack(){
	///Always do garbage collection!
	if (this->option == 0){
		delete []array;
	}else if (this->option == 1){
		delete sLL;	//I already defined how to delete all the nodes of a list in the sLL deconstructor
					// so all I need to do here is say "delete"
	}
}
/*************
 * 	ACCESSORS
 **************/
///This is the public function that can be called to print. It then chooses which of the appropriate private helper
/// functions to call upon.
///The term for a public function that exists only to turn around and use one or more private functions is a "wrapper" function.
void Stack::print(){
	if (this->option == 0){
		this->printArray();
	}else if (this->option == 1){
		this->printSLL();
	}
}
/*************
 * 	MUTATORS
 **************/
///Function to push onto the stack
void Stack::push(int value){
	///Method of pushing changes depending on which data structure we are working with
	///	Note that the user of the class doesn't have to care. They can just call push().
	if (this->option == 0){
		if (index == 10){
			std::cout << "Array full\n";
		} else {
			this->index++;				// increment index
			this->array[index] = value;	//Add value into array at index
		}
	}else if (this->option == 1){
		this->sLL->insert(value,0);	//Call our insert function on index 0 (the top of the stack)
	}
}
///Function to pop off the stack
Node * Stack::pop(){
	///Method to pop changes depending on data structure
	if (this->option == 0){
		if (index == 0) {
			return 0;
		} else {
			int tmp = this->array[0];
			for(int i=1;i<index;i++){	//Shift the array down
				this->array[i-1] = this->array[i];
			}
			this->index--;				//Decrement index
			return new Node(tmp);
		}
	}else if (this->option == 1){
		if (sLL->getLength() == 0){
			return 0;
		} else {
			return this->sLL->remove(0);	//Call our remove function on index 0 (the top of the stack)
		}
	}
}
