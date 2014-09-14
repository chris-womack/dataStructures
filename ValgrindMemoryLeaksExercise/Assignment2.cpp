//	Ian Smith
//	CSCI - 2270
//	Summer 2014
//
//	FILE: Assignment2.cpp
//
//	Driver file for Assignment 2. Makes use of the following classes:
//		Node
//		Linked_List
//		Double_Linked_List
//		Stack
//		Queue

#include <iostream>
#include <string>
#include "Node.h"
#include "Linked_List.h"
#include "Stack.h"

using namespace std;

///The main function! This serves as the UI that allows the user to interact with our code.
///	Note that all main really does is present some cout statements and then call functions
///	we have already written based on user input.
///
///	In object-oriented programming this kind of main function is sometimes called the "driver"
int main(){
    //create an array stack
    Stack * stack;
	stack = new Stack(0);
    int i = 1;
    while (i < 10){
        cout<<"pushing "<<i<<endl;
        stack->push(i);
        i++;
    }
    //print the stack
    stack->print();

    //pop off the stack
    bool emp = false;
    while(!emp){
        Node * tmp = stack->pop();
        if (tmp == 0){
            cout << "STACK EMPTY\n";
            emp = true;
        } else {
            cout << "POPPED: " << tmp->getValue() << endl;
            delete tmp;
        }
    }

    ///If sLL stack was chosen
    Stack *stackSLL = new Stack(1);
    int i2=1;

    while(i2 < 10){
        cout<<"pushing "<<i2<<endl;
        stackSLL->push(i2);

        i2++;

    }
    stackSLL->print();

    emp = false;
    while(!emp){

        ///If pop was chosen
        Node * tmp = stackSLL->pop();
        if (tmp == 0){
            cout << "STACK EMPTY\n";
            emp = true;
        } else {
            cout << "POPPED: " << tmp->getValue() << endl;
        }
    }

    stackSLL->print();

	return 0;
}
