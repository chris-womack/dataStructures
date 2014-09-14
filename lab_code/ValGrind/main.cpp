#include <iostream>

using namespace std;

//node for single-linked list
struct node
{
    int x;
    string name;
    node *next;
};
/*
Valgrind is a tool that can be used to find:

Use of uninitialised memory
Reading/writing memory after it has been free'd
Reading/writing off the end of malloc'd blocks
Reading/writing inappropriate areas on the stack
Memory leaks -- where pointers to malloc'd blocks are lost forever
Mismatched use of malloc/new/new [] vs free/delete/delete []

We'll look at some examples of each of these.
*/

int main()
{

    /*These should generate uninitialized memory errors. This is an error
    generated when memory has been allocated for a variable, but not initialized.
    Here, we see that i has been allocated, i2 has been allocated, and x has
    been allocated, but nothing has been initialized.

    We should get an error for all of this code in Valgrind, even though
    the code will compile and run just fine.
    */
    int *i = new int;
    cout<<*i<<endl;

    int *i2;
    int x;
    i2 = &x;
    cout<<*i2<<endl;

    /*Allocating the memory for sLL but then never deleting it creates
    a memory leak. You should get a message in Valgrind that X blocks
    are possibly lost as a result of this command. You can get rid of this
    error by deleting each of the nodes individually?*/
    node *sLL = new node[9];

    delete []sLL; //delete the array

    /*Illegal read or write error. Here, you get an error because Valgrind
    says you are reading or writing to a place that you shouldn't. The *next
    pointer was created, but memory was not allocated, so you don't have rights
    yet to use that memory. You should get a message that memory is not stack'd,
    malloc'd or (recently) free'd. This means that you haven't created a local
    variable, or allocated memory for your pointer.*/
    node *first = new node;
    node *next;
    first->next = next;
    cout<<first->next->x<<endl;

    //free the same block twice
    /*Attempting to free already freed memory will also cause a problem.
    */
    delete []sLL;

    return 0;
}
