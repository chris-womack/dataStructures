// Chris Womack
// Dr. Hoenigman
// Assignment II

#include "Lab_6_header.h"
#include <iostream>

using namespace std;
//***************************************************************************//
// Node
//***************************************************************************//
// Node constructor
Node::Node(int value){
    integer = value;
    next = 0;
    prev = 0;
}
// Node destructor
Node::~Node(){}


// get the next position
Node* Node::getNext(){
    return next;
}
// set the next position
void Node::setNext(Node*n){
    next = n;
}


// get the previous position
Node* Node::getPrev(){
    return prev;
}
// set the previous position
void Node::setPrev(Node*n){
    prev = n;
}


// get the integer
int Node::getInt(){
    return integer;
}
// set the integer
void Node::setInt(int value){
   integer = value;
}


//***************************************************************************//
// Stack Single (Uses Node but doesn't use ->next)
//***************************************************************************//
// stack constructor
Stack::Stack(){
    Head = NULL;
    Tail = NULL;
    tmp = NULL;
}
// stack destructor
Stack::~Stack(){}


// Stack push
Stack* Stack::push(int *stac_count){

    int integer;

    cout << "Enter an integer to push to the stack." << endl;
    cin >> integer;

    // first time through
    if((*stac_count) == 0){
        Head = new Node(integer);   // allocate new mem for first element
        Tail = new Node(0);     // allocate mem for tail
        Tail->setPrev(Head);    // point tail back to head
        (*stac_count)++;        // tracks elements
    }else{
        tmp = new Node(0);      // allocate new mem
        tmp->setPrev(Tail);     // tell tmp to point back to tail
        Tail->setInt(integer);  // set tail integer to input value
        Tail = tmp;             // move tail up one
        (*stac_count)++;        // tracks elements
    }
}
// Stack pop
Stack* Stack::pop(int *stac_count){
    int integer;

    if((*stac_count) == 0){
        cout << "Stack is empty, push values to stack to pop" << endl;
    }else{
        tmp = Tail;                 // set tmp var to move tail
        Tail = Tail->getPrev();     // set tail to previous node
        integer = Tail->getInt();   // pull int from previous
        delete tmp;                 // delete tmp
        (*stac_count)--;            // track elements in stack

        // return integer value
        cout << "Integer popped from the stack is " << integer << endl;
    }
}
// Stack print
Stack* Stack::print(int *stac_count){
    tmp = Tail->getPrev();  // set tmp to previous node
    if((*stac_count) == 0){
        cout << "Stack is empty, push values to stack to print" << endl;
    }else{
        while(tmp != NULL){                 // continue till tmp is at bottom of stack
            cout << tmp->getInt() << endl;  // print the int value at current node
            tmp = tmp->getPrev();           // move tmp to previous node
        }
    }
}
// delete current node left in stack
Stack* Stack::del(int *stac_count){
    tmp = Tail;
    Tail = Tail->getPrev();
    delete tmp;
    (*stac_count)--;
}

//***************************************************************************//
// Stack Double (Functionality is the same but next is set)
//***************************************************************************//
// stack constructor
StackD::StackD(){
    Head = NULL;
    Tail = NULL;
    tmp = NULL;
}
// stack destructor
StackD::~StackD(){}


// Stack push (changed for double implementation)
StackD* StackD::push(int *stac_count){

    int integer;

    cout << "Enter an integer to push to the stack." << endl;
    cin >> integer;

    // first time through
    if((*stac_count) == 0){
        Head = new Node(integer);   // allocate new mem for first element
        Tail = new Node(0);     // allocate mem for tail
        Head->setNext(Tail);    // point head to the tail node                  (***Double Difference***)
        Tail->setPrev(Head);    // point tail back to head
        (*stac_count)++;        // tracks elements
    }else{
        tmp = new Node(0);      // allocate new mem
        tmp->setPrev(Tail);     // tell tmp to point back to tail
        Tail->setInt(integer);  // set tail integer to input value
        Tail->setNext(tmp);     // point the current not to the new tail        (***Double Difference***)
        Tail = tmp;             // move tail up one
        (*stac_count)++;        // tracks elements
    }
}
// Stack pop  (no changes for double implementation)
StackD* StackD::pop(int *stac_count){
    int integer;

    if((*stac_count) == 0){
        cout << "Stack is empty, push values to stack to pop" << endl;
    }else{
        tmp = Tail;                 // set tmp var to move tail
        Tail = Tail->getPrev();     // set tail to previous node
        integer = Tail->getInt();   // pull int from previous
        delete tmp;                 // delete tmp
        (*stac_count)--;            // track elements in stack

        // return integer value
        cout << "Integer popped from the stack is " << integer << endl;
    }
}
// Stack print (no changes for double implementation)
StackD* StackD::print(int *stac_count){
    tmp = Tail->getPrev();  // set tmp to previous node
    if((*stac_count) == 0){
        cout << "Stack is empty, push values to stack to print" << endl;
    }else{
        while(tmp != NULL){                 // continue till tmp is at bottom of stack
            cout << tmp->getInt() << endl;  // print the int value at current node
            tmp = tmp->getPrev();           // move tmp to previous node
        }
    }
}
// delete current node left in stack
StackD* StackD::del(int *stac_count){
    tmp = Tail;
    Tail = Tail->getPrev();
    delete tmp;
    (*stac_count)--;
}

//***************************************************************************//
// Queue array functions
//***************************************************************************//
// enqueue for array
void enquArr(int stac[], int *stack_head, int *stack_tail, int *stack_size, int *overlap, int *qucount){
    int integer;
    cout << "Input integer to push to the stack" << endl << "::: ";
    cin >> integer;

    if((*stack_tail) == (*stack_head) && (*overlap) == 1){
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


//***************************************************************************//
// Queue Single (Used a double, but ->Prev is set to NULL)
//***************************************************************************//
// Que constructor
Que::Que(){
    Head = NULL;
    Tail = NULL;
    tmp = NULL;
}
// Que destructor
Que::~Que(){}


// enqueue
Que* Que::enqu(int *que_count){

    int integer;

    cout << "Enter an integer to push to the stack." << endl;
    cin >> integer;

    // first time through
    if((*que_count) == 0){
        Head = new Node(integer);   // allocate new mem for first element
        Tail = new Node(0);     // allocate mem for tail
        Head->setNext(Tail);    // point head to tail
        (*que_count)++;         // tracks elements in que
    }else{
        tmp = new Node(0);      // allocate new mem
        Tail->setNext(tmp);     // point tail to next node
        Tail->setInt(integer);  // set integer at tail to value
        Tail = tmp;             // move tail up one
        (*que_count)++;         // tracks elements in que
    }
}
// dequeue
Que* Que::deq(int *que_count){
    int integer;

    if((*que_count) == 0){
        cout << "Stack is empty, push values to stack to pop" << endl;
    }else{
        tmp = Head;                 // set temp to Head
        integer = tmp->getInt();    // get int value at head node
        Head = Head->getNext();     // set head to next node
        delete tmp;                 // delete tmp
        (*que_count)--;             // track elements in que

        // return integer value
        cout << "Integer popped from the stack is " << integer << endl;
    }
}
// print queue
Que* Que::print(int *que_count){
    tmp = Head;  // set tmp to head
    if((*que_count) == 0){
        cout << "Stack is empty, push values to stack to print" << endl;
    }else{
        while(tmp->getNext() != NULL){      // continue till tmp is at end of que
            cout << tmp->getInt() << endl;  // print the int value at current node
            tmp = tmp->getNext();           // move tmp to next node
        }
    }
}
// delete current node left in queue
Que* Que::del(int *que_count){
    tmp = Head;
    Head = Head->getNext();
    delete tmp;
    (*que_count)--;
}


//***************************************************************************//
// Queue Double (Functionality is the same but previous is set)
//***************************************************************************//
// Que constructor
QueD::QueD(){
    Head = NULL;
    Tail = NULL;
    tmp = NULL;
}
// Que destructor
QueD::~QueD(){}


// enqueue (changed for double implementation)
QueD* QueD::enqu(int *que_count){

    int integer;

    cout << "Enter an integer to push to the stack." << endl;
    cin >> integer;

    // first time through
    if((*que_count) == 0){
        Head = new Node(integer);   // allocate new mem for first element
        Tail = new Node(0);     // allocate mem for tail
        Head->setNext(Tail);    // point head to tail
        Tail->setPrev(Head);    // point tail back to head                      (***Double Difference***)
        (*que_count)++;         // tracks elements in que
    }else{
        tmp = new Node(0);      // allocate new mem
        tmp->setPrev(Tail);     // point tmp back to tail                       (***Double Difference***)
        Tail->setNext(tmp);     // point tail to next node
        Tail->setInt(integer);  // set integer at tail to value
        Tail = tmp;             // move tail up one
        (*que_count)++;         // tracks elements in que
    }
}
// dequeue (no changes for double implementation)
QueD* QueD::deq(int *que_count){
    int integer;

    if((*que_count) == 0){
        cout << "Stack is empty, push values to stack to pop" << endl;
    }else{
        tmp = Head;                 // set temp to Head
        integer = tmp->getInt();    // get int value at head node
        Head = Head->getNext();     // set head to next node
        delete tmp;                 // delete tmp
        (*que_count)--;             // track elements in que

        // return integer value
        cout << "Integer popped from the stack is " << integer << endl;
    }
}
// print queue (no changes for double implementation)
QueD* QueD::print(int *que_count){
    tmp = Head;  // set tmp to head
    if((*que_count) == 0){
        cout << "Stack is empty, push values to stack to print" << endl;
    }else{
        while(tmp->getNext() != NULL){      // continue till tmp is at end of que
            cout << tmp->getInt() << endl;  // print the int value at current node
            tmp = tmp->getNext();           // move tmp to next node
        }
    }
}
// delete current node left in queue
QueD* QueD::del(int *que_count){
    tmp = Head;
    Head = Head->getNext();
    delete tmp;
    (*que_count)--;
}


//***************************************************************************//
// Was going to do the double array algorithm, never made it.
//***************************************************************************//
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


//***************************************************************************//
// Main Functions for each combination
//***************************************************************************//
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
                // stack is full
                cout << "Stack is full, pop some of the values from the stack to push more" << endl;
            }else{
                // push integer to stack
                cout << "Input integer to push to the stack" << endl << "::: ";
                cin >> integer;
                // first run through
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

void stacklinked(){
    int integer;
    int command_1;
    int stac_count = 0;

    Stack *stac = new Stack();

    while(true){
        cout << endl << "(1) PUSH (Enter integer for insertion into stack, LIFO)"
         << endl << "(2) POP (Display integer and delete it from stack, LIFO)"
          << endl << "(3) PRINT STACK (Displays stack, LIFO)"
           << endl << "(4) Exit Program" << endl << "::: ";
        cin >> command_1;

        //cout << List->getInt() << endl;
        if(command_1 == 1){
            // PUSH to the stack LIFO style
            stac->push(&stac_count);
        }else if(command_1 == 2){
            // POP from stack LIFO style
            stac->pop(&stac_count);
        }else if(command_1 == 3){
            // PRINT stack
            stac->print(&stac_count);
        }else{
            // Delete stack and Exit Progam
            while(stac_count != 0){
                cout << "Deleting element number " << stac_count << endl;
                stac->del(&stac_count);
            }
            break;
        }
    }
}

void stackDblinked(){
    int integer;
    int command_1;
    int stac_count = 0;

    StackD *stacD = new StackD();

    while(true){
        cout << endl << "(1) PUSH (Enter integer for insertion into stack, LIFO)"
         << endl << "(2) POP (Display integer and delete it from stack, LIFO)"
          << endl << "(3) PRINT STACK (Displays stack, LIFO)"
           << endl << "(4) Exit Program" << endl << "::: ";
        cin >> command_1;

        //cout << List->getInt() << endl;
        if(command_1 == 1){
            // PUSH to the stack LIFO style
            stacD->push(&stac_count);
        }else if(command_1 == 2){
            // POP from stack LIFO style
            stacD->pop(&stac_count);
        }else if(command_1 == 3){
            // PRINT stack
            stacD->print(&stac_count);
        }else{
            // Delete stack and Exit Progam
            while(stac_count != 0){
                cout << "Deleting element number " << stac_count << endl;
                stacD->del(&stac_count);
            }
            break;
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

void queuelinked(){
    int integer;
    int command_1;
    int que_count = 0;

    Que *que = new Que();

    while(true){
        cout << endl << "(1) ENQUEUE (Enter integer for insertion into queue, FIFO)"
         << endl << "(2) DEQUEUE (Display integer and delete it from queue, FIFO)"
          << endl << "(3) PRINT QUEUE (Displays queue contents, FIFO)"
           << endl << "(4) Exit Program" << endl << "::: ";
        cin >> command_1;

        //cout << List->getInt() << endl;
        if(command_1 == 1){
            // PUSH to the queue FIFO style
            que->enqu(&que_count);
        }else if(command_1 == 2){
            // POP from queue FIFO style
            que->deq(&que_count);
        }else if(command_1 == 3){
            // PRINT stack
            que->print(&que_count);
        }else{
            // Delete stack and Exit Progam
            while(que_count != 0){
                cout << "Deleting element number " << que_count << endl;
                que->del(&que_count);
            }
            break;
        }
    }
}

void queueDblinked(){
    int integer;
    int command_1;
    int que_count = 0;

    QueD *queD = new QueD();

    while(true){
        cout << endl << "(1) ENQUEUE (Enter integer for insertion into queue, FIFO)"
         << endl << "(2) DEQUEUE (Display integer and delete it from queue, FIFO)"
          << endl << "(3) PRINT QUEUE (Displays queue contents, FIFO)"
           << endl << "(4) Exit Program" << endl << "::: ";
        cin >> command_1;

        //cout << List->getInt() << endl;
        if(command_1 == 1){
            // PUSH to the queue FIFO style
            queD->enqu(&que_count);
        }else if(command_1 == 2){
            // POP from queue FIFO style
            queD->deq(&que_count);
        }else if(command_1 == 3){
            // PRINT stack
            queD->print(&que_count);
        }else{
            // Delete stack and Exit Progam
            while(que_count != 0){
                cout << "Deleting element number " << que_count << endl;
                queD->del(&que_count);
            }
            break;
        }
    }
}
