#include <iostream>
#include <string.h>

using namespace std;

// hash function
// x is string to hash, M is hash table size
int h(string x, int M){
    int xlength = x.size()+1;           // get length and add termination spot
    char *ch = new char[xlength];
    ch[x.size()] = 0;                   // NULL termination

    // copy string into char array
    memcpy(ch, x.c_str(), x.size());    // copy x.c_str into array ch with size x.size()

    int sum = 0;
    for(int i = 0; i < x.length(); i++){
        sum+=ch[i];
    }
    //% guarantees result between 0 and M
    return sum%M;
}

void i(){
}

void d(){
}

void f(){
}

void p(){
}

int main()
{
    // we need the string that we're going to hash
    // we need to convert that string to an integerd
    // function that produces a has value for the string

    // create hash table array
    int hashTableSize = 50;
    string hashTable[hashTableSize];
    string x = "Lonesome Dove";
    int i = h(x, hashTableSize);
    cout << "i = " << i << endl;

    // put string in hash table
    hashTable[i] = x;
    cout << hashTable[i] << endl;   // value at the index of i

    // collision
    x = "Go Cat Go.";
    i = h(x, 50);
    cout << "Go Cat, Go " << i << endl;

    x = "Go Dog, Go";
    i = h(x, 50);
    cout << "Go Dog, Go " << i << endl;

    cout << 10%1000 << endl;

    return 0;
}
