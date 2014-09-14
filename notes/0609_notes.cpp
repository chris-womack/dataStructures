#include <iostream>

using namespace std;

// this takes in an address and adjust the value at that address
void negative(int& i)
{
	i = -i;
}

// this takes in a pointer and changes the value
void neg_p(int *x)
{
	*x = -(*x);
}

//
void myFunc(int x)
{
	cout << "address of x" << &x << endl;
}


int main()
{
	// view address
	int i = 5;
	cout<<"address of i: " << &i <<" value of i:"<<i<<endl;
	
	// address view of an array
	int myArray[10];
	for(int x = 0; x < 10; x++)
		cout<<myArray[x]<<" address of myArray: "<< &myArray[x]<<endl;
		
	// pointers
	int *t;		// declare the address
	t = &i;		// point the pointer to something in this case i
	cout<<"*t = "<<*t<<endl;	// derefernce the pointer in order to see the value at that address
	cout<<"t = "<< t<<endl;		// without dereferncing the pointer you just see the address
	cout<<"&i = "<< &i<<endl;	// address of &i which is the same as the value of t
	
	*t = 6;		// this changes the value of whatever is at t, in this case i
	cout << "t = " << *t << " i = " << i << endl;
	
	t+=10;	// this is dangerous, as it changes the value of the t meaning the address changes
	cout << "*t = "<< *t << " t = "<< t << endl;
	*t = 5; // now we have stored the value at t which is in a new place of memory
	
	
	i = 5;
	negative(i);
	cout << "negative of i is: "<< i << endl; 
	
	int *x;
	x = &i;
	
	neg_p(x);
	cout << "negative of *x is: " << *x << endl;
	
	cout << "address of i: " << &i << endl;
	myFunc(i);

	return 0;
}
