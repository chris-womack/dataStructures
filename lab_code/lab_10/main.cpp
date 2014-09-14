// Chris Womack
// Dr. Hoenigman
// Lab_10

/*
    The Hash function used was the one from class. It sums the lenght of the string and then mods this value by the size of the table.
    It is not the best for strings, but I wanted to focus on collision detection so I used this to ensure enough collisions for testing.
    The program will ask for the number of elements to be inputed into the hash table. This value will be multiplied by 1.33 to give space for the values.
*/

#include <iostream>
#include <string.h>

using namespace std;

// nodes for chaining
class Node{
private:
    string name;
    Node* prev;
    Node* next;

public:
    Node(){
        name = "NULL";
        prev = NULL;
        next = NULL;
    }
    ~Node(){
    }

    string getName(){
        return name;
    }
    void setName(string n){
        name = n;
    }

    Node* getPrev(){
        return prev;
    }
    Node* setPrev(Node* n){
        prev = n;
    }

    Node* getNext(){
        return next;
    }
    Node* setNext(Node* n){
        next = n;
    }

};

unsigned int hash(const char* s, unsigned int seed = 0)
{
    unsigned hash = seed;
    while (*s)
    {
        hash = hash * 101  +  *s++;
    }
    return hash;
}

// hash function
// x is string to hash, M is hash table size
int h(string name, int hashTableSize){
    int nameLength = name.size()+1;           // get length and add termination spot
    char *charArr = new char[nameLength];
    charArr[name.size()] = 0;                   // NULL termination

    // copy string into char array
    memcpy(charArr, name.c_str(), name.size());    // copy x.c_str into array ch with size x.size()

    int sum = 0;
    for(int i = 0; i < name.length(); i++){
        sum+=charArr[i];
    }
    //% guarantees result between 0 and M
    return sum%hashTableSize;
}

int i(string name, Node* hashTable[], int hashTableSize, int index, int* insertCount){

    if(hashTable[index]->getName() == "NULL"){
        hashTable[index]->setName(name);
        Node* tmp = new Node();
        tmp->setPrev(hashTable[index]);
        hashTable[index]->setNext(tmp);
        (*insertCount)++;

    }else{
        Node* tmp2 = hashTable[index];
        while(tmp2->getName() != "NULL" && tmp2->getName() != name){
            tmp2 = tmp2->getNext();
        }
        if(tmp2->getName() != name){
            tmp2->setName(name);
            Node* tmp = new Node();
            tmp->setPrev(tmp2);
            tmp2->setNext(tmp);
            (*insertCount)++;
        }else{
            cout << "Name has already been entered." << endl;
        }
    }
    return index;
}

void d(string name, Node* hashTable[], int hashTableSize, int index, int arrLen, int* insertCount){

    if(hashTable[index]->getNext() != NULL){

        if(hashTable[index]->getNext()->getNext() != NULL){

            Node* tmp2 = hashTable[index];
            while(tmp2->getName() != name and tmp2->getNext() != NULL){
                tmp2 = tmp2->getNext();
            }
            if(tmp2->getName() == name and tmp2->getPrev() != NULL){
                if(tmp2->getNext() != NULL){
                    Node* Next = tmp2->getNext();
                    Node* Prev = tmp2->getPrev();
                    Next->setPrev(Prev);
                    Prev->setNext(Next);
                    delete tmp2;
                }else{
                    Node* Prev = tmp2->getPrev();
                    Prev->setName(NULL);
                    delete tmp2;
                }
                (*insertCount)--;
            }else if(tmp2->getName() == name and tmp2->getPrev() == NULL){
                hashTable[index] = hashTable[index]->getNext();
                hashTable[index]->setPrev(NULL);
                delete tmp2;
            }else{
                cout << "Name was not found." << endl;
            }

        }else{

            if(hashTable[index]->getName() == name){
                hashTable[index]->setName("NULL");
                Node* del = hashTable[index]->getNext();
                hashTable[index]->setNext(NULL);
                delete del;
                (*insertCount)--;
            }else{
                cout << "Name was not found." << endl;
            }
        }
    }else{
        cout << "Name was not found." << endl;
    }
}

void f(string name, Node* hashTable[], int index){
    if(hashTable[index]->getName() == name){
        cout << "Yes, " << name << " was found at position " << index << " in the hash table." << endl;
    }else if(hashTable[index]->getName() != name){
        Node* tmp = hashTable[index];
        while(tmp->getName() != name && tmp->getNext() != NULL){
           tmp = tmp->getNext();
        }
        if(tmp->getName() == name){
            cout << "Yes, " << name << " was found at position " << index << " in the hash table." << endl;
        }else{
            cout << name << " was not found in the hash table" << endl;
        }
    }
}

void p(Node* hashTable[], int hashTableSize, int arrLen){
    cout << endl;
    cout << "The names contained in the list are as follow:" << endl;
    cout << endl;

    for(int i = 0; i < hashTableSize; i++){
        if(hashTable[i]->getName() != "NULL"){
            if(hashTable[i]->getNext() != NULL){
                Node* tmp = hashTable[i];
                while(tmp->getNext()->getNext() != NULL){
                    tmp = tmp->getNext();
                    cout << tmp->getName() << endl;
                }
            }
            cout << hashTable[i]->getName() << endl;
        }
    }
}


int main()
{
    int index = 0;
    int countTmp = 0;
    int option = 0;
    int entryAmount = 0;
    int insertCount = 0;

    string name;
    string firstname;
    string lastname;

    // try to size initial load of hash table
    cout << endl;
    cout << "How many entries do you intend to add." << endl;
    cin >> entryAmount;

    const int hashTableSize = entryAmount * 1.33 + 1;

    Node* hashTable[hashTableSize];
    for(int i = 0; i < hashTableSize; i++){
        hashTable[i] = new Node();
    }

    while(true){
        cout << endl;
        cout << "1) Insert a name that has not been inserted." << endl;
        cout << "2) delete a name from the hash table." << endl;
        cout << "3) Find a value in the hash table." << endl;
        cout << "4) Print the contents of the hash table." << endl;
        cout << "5) Exit the Program." << endl;
        cin >> option;

        if(option == 1){
            cout << "Enter the name you wish to insert in the form of: firstname lastname" << endl;
            cin >> firstname >> lastname;

            // concat strings
            name = firstname + " " + lastname;

            // get index
            index = h(name, hashTableSize);

            // insert function
            i(name, hashTable, hashTableSize, index, &insertCount);

        }else if(option == 2){

            cout << "Enter the name you wish to delete in the form of: firstname lastname" << endl;
            cin >> firstname >> lastname;

            // concat strings
            name = firstname + " " + lastname;

            // get an index
            index = h(name, hashTableSize);

            // delete function
            d(name, hashTable, hashTableSize, index, entryAmount, &insertCount);

        }else if(option == 3){

            cout << "Enter the name you wish to find in the form of: firstname lastname" << endl;
            cin >> firstname >> lastname;

            // concat strings
            name = firstname + " " + lastname;

            index = h(name, hashTableSize);
            f(name, hashTable, index);

        }else if(option == 4){

            // print function
            p(hashTable,hashTableSize, entryAmount);

        }else{
            break;
        }
    }
}
