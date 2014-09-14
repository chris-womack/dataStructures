// Chris Womack
// Dr. Hoenigman
// Lab_7

#include "Lab_6_header.h"
#include <iostream>

using namespace std;

// constructor
Link::Link(int value){
    integer = value;
    next = 0;
    prev = 0;
}

// destructor
Link::~Link(){}

// get the next position
Link* Link::getNext(){
    return next;
}

// set the next position
void Link::setNext(Link*n){
    next = n;
}

// get the previous position
Link* Link::getPrev(){
    return prev;
}

// set the previous position
void Link::setPrev(Link*n){
    prev = n;
}

// get the integer
int Link::getInt(){
    return integer;
}

// set the integer
void Link::setInt(int value){
   integer = value;
}

Link* Link::push(Link* List, int *push_des){

    int check = 0;
    Link *Add;

    cout << "Input integer to push to the stack" << endl << "::: ";
    cin >> integer;

    if(*push_des == 0){
        // PUSH to stack LIFO style
        Add = new Link(integer);
        List = Add;
        *push_des = 1;
    }else{
        Add = new Link(integer);
        Add->setPrev(List);

        // Add variable
        cout << endl;
        cout << "Add" << endl;
        cout << "Address of Add ::: "  << Add << endl;
        cout << "Value of Int ::::: "  << Add->getInt() << endl;
        cout << "Address of Prev :: "  << Add->getPrev() << endl;

        // List before
        cout << endl;
        cout << "List before being set equal; In function" << endl;
        cout << "Address of List :: "  << List << endl;
        cout << "Value of Int ::::: "  << List->getInt() << endl;
        cout << "Address of Prev :: "  << List->getPrev() << endl;

        List = Add;
        List->getPrev()->setInt(Add->getPrev()->getInt());

        // List After
        cout << endl;
        cout << "List after being set equal; In function" << endl;
        cout << "Address of List :: "  << List << endl;
        cout << "Value of Int ::::: "  << List->getInt() << endl;
        cout << "Address of Prev :: "  << List->getPrev() << endl;

        // Previous int
        cout << endl;
        cout << "Previous Integer" << endl;
        cout << "Value of PrevInt : "  << List->getPrev()->getInt() << endl;
    }
    return List;
}

Link* Link::pop(Link *List, int *push_des){
    int integer;

    if(*push_des == 0){
        cout << endl << "The stack is empty, push an integer to the stack in order to pop values"
            << endl;
        *push_des = 0;
    }else if(List->getPrev() == NULL){
        integer = List->getInt();
        cout << endl << "Integer popped from the stack is " << integer << endl;
        Link *deleter;
        deleter = List;
        delete deleter;
        *push_des = 0;
        cout << "in 1" << endl;
    }else{
        integer = List->getInt();
        cout << endl << "Integer popped from the stack is " << integer << endl;
        Link *deleter;
        deleter = List;
        List = List->getPrev();
        delete deleter;
        *push_des = 1;
        cout << "in 2" << endl;
    }
}

// enqueue for array
void enquArr(int stac[], int *stack_head, int *stack_tail, int *stack_size, int *overlap, int *qucount){
    int integer;
    cout << "Input integer to push to the stack" << endl << "::: ";
    cin >> integer;

    if((*stack_tail) == (*stack_head) && (*overlap) == 1){
        cout << endl;
        cout << "The queue is full, dequeue a value to add the new value" << endl;
    }else{
        stac[*stack_tail] = integer;
        if((*stack_tail) == (*stack_size)-1 && (*overlap) == 0){
            (*stack_tail) = 0;
            (*overlap) = 1;
        }else{
            (*stack_tail)++;
        }
        (*qucount)++;
    }
}

// dequeue for array
void dequArr(int stac[], int *stack_head, int *stack_tail, int *stack_size, int *overlap, int *qucount){

    int integer;

    if((*stack_head) == (*stack_tail) && overlap == 0){
        cout << "Queue is empty, enqueue a value to populate list" << endl;
    }else if((*qucount) == 0){
        cout << "Queue is empty, enqueue a value to populate list" << endl;
    }else{
        integer = stac[(*stack_head)];
        if((*stack_head) == (*stack_size)-1){
            (*stack_head) = 0;
        }else{
            (*stack_head)++;
        }
        cout << "The integer dequeued from the queue is " << integer << endl;
        (*qucount)--;
    }

    if((*qucount) == 0){
        (*overlap) = 0;
    }
}

// print queue array
void printquArr(int stac[], int *stack_head, int *stack_tail, int *stack_size, int *overlap, int *qucount){

    int traverse = 0;
    traverse = (*stack_head);

    if((*qucount) == 0){
        (*stack_head) = 0;
        (*stack_tail) = 0;
    }

    if((*overlap) == 1){
        for(int i = (*stack_head); i < (*stack_size); i++){
        cout << stac[i] << endl;
        }
        for(int j = 0; j < (*stack_tail); j++){
            cout << stac[j] << endl;
        }

    }else{
        for(int k = (*stack_head); k < (*stack_tail); k++){
            cout << stac[k] << endl;
        }
    }
}

int *stackBump(int stackArray[], int stack_size){
    // double stack size
    int orig_size = stack_size;
    int new_size = stack_size*2;

    // copy array;
    int newArray[stack_size];

    for(int i = 0; i < orig_size; i++){
        newArray[i] = stackArray[i];
        delete &stackArray[i];
    }
    return newArray;
}

void stackArray(){

    int command_1;
    int integer = 0;
    int stack_top = 0;
    int stack_size = 40;
    int stac[stack_size];
    int push_des = 0;

    while(true){
        cout << endl << "(1) PUSH (Enter integer for insertion into stack, LIFO)"
         << endl << "(2) POP (Display integer and delete it from stack, LIFO)"
          << endl << "(3) PRINT STACK (Displays stack, LIFO)"
           << endl << "(4) Exit Program" << endl << "::: ";
        cin >> command_1;

        if(command_1 == 1){
            // PUSH stack LIFO style
            if(stack_top == (stack_size - 1)){
                // stack is full, call stackBump function
                //int newArray[];
                //newArray = stackBump(stackArray, stack_size);
                cout << "Stack is full, pop some of the values from the stack to push more" << endl;
            }else{
                // push integer to stack
                cout << "Input integer to push to the stack" << endl << "::: ";
                cin >> integer;
                if(stack_top == 0 && push_des == 0){
                    stac[stack_top] = integer;
                    push_des = 1;
                }else{
                    stack_top++;
                    stac[stack_top] = integer;
                }
            }
        }else if(command_1 == 2){
            // POP stack LIFO style
            if(push_des == 0){
                // stack is empty
                cout << endl << "Stack is empty, push an integer to the stack before running POP" << endl;
            }else{
                stack_top--;
                integer = stac[stack_top+1];
                cout << endl << "Integer popped from the stack is " << integer << endl;
            }
        }else if(command_1 == 3){
            if(push_des == 0){
                cout << push_des << endl;
                cout << endl << "Stack is empty, push an integer to the stack before running POP" << endl;
            }else{
                // print stack
                cout << endl;
                for(int i = stack_top; i >= 0; i--){
                    cout << stac[i] << endl;
                }
            }
        }else{
            break;
        }
    }
}

void stackLinked(){
    int integer;
    int command_1;
    int push_des = 0;
    int counter = 0;

    Link *List = new Link(0);
    Link *Current;

    while(true){
        cout << endl << "(1) PUSH (Enter integer for insertion into stack, LIFO)"
         << endl << "(2) POP (Display integer and delete it from stack, LIFO)"
          << endl << "(3) PRINT STACK (Displays stack, LIFO)"
           << endl << "(4) Exit Program" << endl << "::: ";
        cin >> command_1;

        //cout << List->getInt() << endl;
        if(command_1 == 1){
            // PUSH to the stack LIFO style
            Current = List;
            List = List->push(List, &push_des);

            // List outside function
            cout << endl;
            cout << "List outside the function" << endl;
            cout << List << endl;
            cout << List->getInt() << endl;
            cout << List->getPrev() << endl;

            //if(counter > 0){
                //cout << List->getPrev()->getInt();
        }else if(command_1 == 2){
            // POP from stack LIFO style
            List->pop(List, &push_des);
            //cout << List->getInt() << endl;
            //cout << List->getPrev() << endl;
        }else if(command_1 == 3){
            // PRINT stack
            Link *traverse;
            //cout << List->getInt() << endl;
            traverse = List->getPrev();
            while(traverse->getPrev() != NULL){
                cout << traverse->getInt() << endl;
                traverse = traverse->getPrev();
            }
        }else{
            // Delete stack and Exit Progam
        }
        counter++;
    }
}

void stackDblinked(){
    int command_1;

    while(true){
        cout << endl << "(1) PUSH (Enter integer for insertion into stack, LIFO)"
         << endl << "(2) POP (Display integer and delete it from stack, LIFO)"
          << endl << "(3) PRINT STACK (Displays stack, LIFO)"
           << endl << "(4) Exit Program" << endl << "::: ";
        cin >> command_1;

        if(command_1 == 1){
        }else if(command_1 == 2){
        }else if(command_1 == 3){
        }else{
        }
    }
}

void queueArray(){

    int command_1;
    int qucount = 0;
    int stack_head = 0;
    int stack_tail = 0;
    int stack_size = 40;
    int stac[stack_size];
    int overlap = 0;

    while(true){
        cout << endl << "(1) ENQUEUE (Enter integer for insertion into queue, FIFO)"
         << endl << "(2) DEQUEUE (Display integer and delete it from queue, FIFO)"
          << endl << "(3) PRINT QUEUE (Displays queue contents, FIFO)"
           << endl << "(4) Exit Program" << endl << "::: ";
        cin >> command_1;

        if(command_1 == 1){
            enquArr(stac, &stack_head, &stack_tail, &stack_size, &overlap, &qucount);
        }else if(command_1 == 2){
            dequArr(stac, &stack_head, &stack_tail, &stack_size, &overlap, &qucount);
        }else if(command_1 == 3){
            printquArr(stac, &stack_head, &stack_tail, &stack_size, &overlap, &qucount);
        }else{
            break;
        }
    }
}

void queueLinked(){
    int command_1;

    while(true){
        cout << endl << "(1) ENQUEUE (Enter integer for insertion into queue, FIFO)"
         << endl << "(2) DEQUEUE (Display integer and delete it from queue, FIFO)"
          << endl << "(3) PRINT QUEUE (Displays queue contents, FIFO)"
           << endl << "(4) Exit Program" << endl << "::: ";
        cin >> command_1;

        if(command_1 == 1){
        }else if(command_1 == 2){
        }else if(command_1 == 3){
        }else{
        }
    }
}

void queueDblinked(){
    int command_1;

    while(true){
        cout << endl << "(1) ENQUEUE (Enter integer for insertion into queue, FIFO)"
         << endl << "(2) DEQUEUE (Display integer and delete it from queue, FIFO)"
          << endl << "(3) PRINT QUEUE (Displays queue contents, FIFO)"
           << endl << "(4) Exit Program" << endl << "::: ";
        cin >> command_1;

        if(command_1 == 1){
        }else if(command_1 == 2){
        }else if(command_1 == 3){
        }else{
        }
    }
}

void garbageCollection(){
}


