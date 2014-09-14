#include <iostream>

using namespace std;

struct CNode{
	int x;
	int y;
};

void arrayTest(int a[]){
	a[1] = 5;
	for(int i = 0; i < 3; i++){
		cout << &a[i] << endl;
	}

};

void scopeTest(int i2){
	cout << "i2 = " << i2 << endl;
};

void pointerTest(int *p){
    *p = 99;
}

int main()
{
	//int i;

	int a[3];   // possibly the same as int *a = new int[3];

	scopeTest[i];
	//cout << "i2 = " << i2 << endl;

	CNode node;
	node.x = 5;

	//CNode node[5];    // static array of objects
	int i[5];
	int *ip;
	ip = &i;
	*ip = 5;    // this changes *ip and i

    int *ipNew;
    ipNew = new int;
    *ipNew = 5;  // this only changes *ipNew
    pointerTest(ipNew);
    cout << "ipNew: " << *ipNew << endl;

    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    arrayTest(a);
    for(int i = 0; i < 3; i++){
        cout << "value " << a[i];
		cout << ": address " << &a[i] << endl;
    }


	return 0;
}
