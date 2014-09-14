#include <iostream>
#include "linkedListEx.h"

using namespace std;
/*Moving between array items uses the index of the item in the array.
If you want to insert an item in the array, you need to change the index
of many other items in the array and possibly even change the size of the
array.

With a linked list, you have a collection of items and a pointer between
those items that sets the order. Each item is a node, either a struct or
a class*/

//node
struct node{
    int x;
    node *next; //pointer to another node. it's the same type
};

int main()
{

    /*We can allocate memory statically, and when you know how much
    memory you need, this works great, and it's actually better to do
    it this way. For example, a 5-item array is allocated like:
    */
    int myArray[5];

    /*Another option is to allocate the memory dynamically, as it's
    needed. With dynamic allocation, we create a pointer, and then
    allocate memory for the pointer using the new keyword, such as: */
    int *iArray;
    iArray = new int[5];
    for(int z = 0; z < 5; z++)
        cout<<iArray[z]<<"\n";
    /*With the previous example, *iArray points to the beginning of a 5-integer
    array. We don't need to point to the address of an existing variable.

    Can also navigate array with pointer arithmetic.
    */

    /*Creates a pointer to a struct node, but no memory has yet been allocated
    for the node*/
    node *root;
    node *head;
    /*Allocate memory to the node. This doesn't use a constructor, which is why
    it isn't node(). */
    root = new node;
    head = root;
    /*Set value of x for root.
    Notice the syntax, it's different than anything we've done so far.
    The -> operator is used for pointers to objects that have members.
    */
    root->x = 5;
    cout<<root->x<<endl;

    //is equivalent to
    (*root).x = 1;
    cout<<root->x<<endl;

    /*Setting next for root. First, we need to create another pointer of
    type node, and then allocate memory for node, and then set
    root->next to point to the newly allocated node.*/
    node *n1;
    n1 = new node;
    //check the address of n1
    cout<<"address of n1: "<<n1<<endl;

    root->next = n1;
    //check address of root->next, it's the same as address of n1
    cout<<"address of next: "<<root->next<<endl;

    /*Adding nodes over and over until you've added all you need.
    If you were using an array of items, you would allocate all memory
    at one time. But, with a linked list, you add items one at a time
    by keeping track of the current end of the list and appending another
    node onto the end.

    To do this, we need our list and a pointer to the end of
    our list.
    */

    int i = 0;
    while(i < 5){
        //root is a pointer, we're getting the address of the last
        //node in the list
        root = root->next;
        cout<<root<<endl;
        node *n2 = new node;
        n2->x = i+2;
        n2->next = 0; //null
        root->next = n2;
        i++;
    }
    //reset the pointer to the beginning of the linked list
    root = head;
    /*root is a pointer, it's just an address, and we can use
    it to point to any address. In this next example, we're
    using root to store root->next, which is also an address.
    Once we have the next node, we can get the x value for that
    node.
    */
    for(int j = 0; j < 5; j++){
        cout<<root->x<<endl;
        root = root->next;

    }

    /*All previous examples used structs as the object. But, the
    objects can also be built from classes. For this example, we're going
    to use a class as the node. There is a convention in C++ that we
    haven't discussed yet. Classes are usually defined in a separate file,
    and then our main code will will include a header file that defines
    the class. This is cleaner, reduces the code in any one file, and is
    actually preferred by the compiler.

    There are two files on Moodle: linkedListEx.h and linkedListEx.cpp
    The .h file contains the declaration for the class, and the linkedListEx.cpp
    contains the implementation of the class. To use this code, you need
    to include linkedListEx.h in your program, the same way I did at the top
    of this file.

    Once you've included that file, you can create instances of CNode.
    */
    CNode *classNode;
    classNode = new CNode(0);
    CNode *cHead;
    cHead = classNode;
    //need a new instance of CNode
    CNode *next;
    next = new CNode(1);
    //next and classNode->getNext should be the same address
    cout<<next<<endl;
    classNode->setNext(next);
    cout<<classNode->getNext()<<endl;

    i = 0;
    while(i < 5){
        CNode *next;
        next = new CNode(i+2);
        classNode = classNode->getNext();
        classNode->setNext(next);
        cout<<classNode->getX()<<endl;

        i++;
    }
    //Question: why doesn't the 0 print?

    //we must explicity free the memory
    //this is called garbage collection
    /*starting with the struct, you can delete each node at
    a time, but you want to make sure you get the next pointer
    before you delete a node, otherwise, there's no path to
    the next node.*/

    //we stored the beginning of the linked list in head
    root = head;
    cout<<"starting garbage collection"<<endl;
    node *n;
    n = root->next; //store the next so it's not lost
    while(root->next != 0){
        cout<<"deleting "<<root<<endl;
        delete root;
        root = n; //this is root->next
        n = n->next;
    }

    //for the class
    /*The destructor for our class prints "calling destructor"
    but, we haven't seen those words print yet. When we delete
    the classNode objects, we should see that they are destroyed.*/
    classNode = cHead;
    cout<<"starting class garbage collection"<<endl;
    CNode *cn;
    cn = classNode->getNext();
    while(classNode->getNext() != 0){
        cout<<"deleting"<<classNode<<endl;
        delete classNode;
        classNode = cn;
        cn = cn->getNext();
    }
    return 0;
}
