/*
Lecture 2 - Memory and pointers

In CSCI1300, we very briefly discussed computer memory and some notion of variable scoping.
In this class, we will go much more in-depth on computer memory, including
what it is, why it matters to you as a program, how memory management affects
program structure and efficiency, and how C++ in particular really, really
cares what you do with memory.

Computer memory is divided into numbered locations, where each location
has an address that can store one byte. A variable is assigned an address
when it is created. A variable that takes up more than one byte is still given
the address of its first byte
*/
#include <iostream>

using namespace std;
/*The argument type here is an integer reference, rather than an integer value.
Since the reference is what is passed to the function, the value of x can change
and it will change outside of the function as well, even though the function
doesn't return a value.*/
void neg(int& x) {
   x = -x;
}
/*In this example, int *x declares a pointer called x and then dereferences it
with *x=-(*x). When the function is called, a pointer should be passed to the function,
not the pointer value. The value of x is changing in the function, which will also change
it in the main function where negate_p is called.*/
void negate_p(int *x)  {
   *x = -(*x);
}

void myFunct(int i){
    cout<<"address of i:"<<&i<<"\n";
}

int main()
{
    //pointers, scope, pass by value, pass by reference
    /*Create a variable called i that has a value of 5. That
    variable also has an address in memory, and you can get that
    address using &i
    */
    int i = 5;
    cout<<"address of i:"<<&i<<" "<<"value of i:"<<i<<"\n";
    /*Previous statement should have output a large number
    starting with 0x and the number 5 as value of i. The 0x number
    is the hexidecimal address of i, it's the location on the memory
    stack where i is created. If we create another variable i2, it is also
    created in memory at a different address. The two variables could be
    created at consecutive memory locations. An integer is 4 bytes, so if the
    variables are stored consecutively, then we would see the address increase
    by four bytes.
    */
    int i2 = 6;
    cout<<"address of i2:"<<&i2<<" "<<"value of i2:"<<i2;
    //There is more about hexidecimal numbering and binary in the written notes

    /*You can see the contiguous memory in an array declaration. Recall, an
    array is a collection of value that are all the same type. You declare an
    array and its size before adding any values, which means that you allocate
    all memory needed for the array up front. We can look at the addresses of each
    memory location in the array.
    */
    /*This creates an array of 10 integers*/
	int myArray[10];
	/*I created myArray, but I didn't set the contents of the array to anything meaningful.
	 * If I print the contents of myArray, it's just garbage.
	 */
    for(int x = 0; x < 10; x++)
        cout<<myArray[x]<<"\n";

    /*Or, we can look at the address of each item in myArray and see that the address
    increases by 4 for each index. The int is 4 bytes and it's an array of ints.
    */
    for(int x = 0; x < 10; x++)
        cout<<&myArray[x]<<"\n";

    /*POINTERS
    We talk about memory and bytes because memory management can be a big part of
    development. There are ways to write code to use memory efficiently and ways to use
    memory inefficiently. In today's computers, efficient memory management is not as
    big of an issue as it once was. However, for operating systems programming and
    embedded systems it is still an issue that needs to be considered. It is also
    important for code that runs millions and millions of iterations. If each iteration
    can be sped up just a tiny, tiny amount by good memory management, overall, the
    program will run considerably faster.
    */
    // Declaring pointers
    int *t;
    t = &i;
    /* t is a pointer that points to the address of i. t is identified by an address
    rather than a name and it needs to be told what that address is before we can
    use it. t references a location.
    */
    cout <<"t is "<< t << "\n";
    cout <<"i is "<< &i << "\n";
    /*To get the value being stored at the address t, we need to dereference t.
    */
    cout <<"the value of t is "<< *t << "\n";
    cout <<"the value of i is "<< i << "\n";
    /*Both *t and i will have the same value, since they're at the same memory
    location. We can change one and notice that the other value also changes.
    */
    *t = 6;
    cout <<"the value of t is "<< *t << "\n";
    cout <<"the value of i is "<< i << "\n";
    /*Here's where you need to be careful. You can change the pointer t
    and it's perfectly legal, but may not be what you want. For example,
    it you want to increment the value of *t, *t++, but accidentally do
    t++, you've changed the address that t refers to. But, if you do
    t++, and then *t = 20, you've just overwritten some area in memory and you
    don't know what you've damaged.
    */
    t+=10;
    cout <<"the value of t is "<< *t << "\n";

    int *x;
    x = &i;

    *x = 5;
    /*One of the nice things about pointers is that you can pass a variable by
    reference to a function, allowing the value of the variable to change without
    returning the value. This is more efficient than pass by value, where passing a value
    creates a copy in memory of the original variable.
    */
    neg(i);
    cout<<"x=:"<<*x<<"\n";
    neg(*x);
    cout<<"x=:"<<*x<<"\n";
    negate_p(x);
    cout<<"x=:"<<*x<<"\n";


    /*pass by value example. Here, passing i to the function myFunct makes a
    copy of i in memory instead of passing the address reference. In myFunct, the
    address of i is printed, notice that it is different than the address of the  i
    passed to myFunct*/
    cout<<"address of i: "<<&i<<"\n";
    myFunct(i);

    /*Pointers become necessary when we put things in lists, or we want one data structure
    to be linked to another in some order. If we change that order, we don't need to shuffle
    an array, we just remove an item by changing what the items before and after it point to.
    */

    return 0;
}
