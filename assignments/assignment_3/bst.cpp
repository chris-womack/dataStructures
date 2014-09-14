// Chris Womack
// Dr. Hoenigman
// Assignment III

#include "bst.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
//***************************************************************************//
// Book Books
//***************************************************************************//
// Book constructor
Book::Book(){
    // string isbn
    string ISBN = "NULL";

    // int isbn
    long long ISBN_int = 0;

    // title
    string title = "NULL";

    // author
    string author = "NULL";

    // convert price to int for compare
    float price = 0;

    string price_str = "NULL";

    // convert stock to int for compare
    int stock = 0;

    Book* left = NULL;
    Book* right = NULL;
    Book* parent = NULL;
}
// Book destructor
Book::~Book(){}

// get and set ISBN
string Book::getISBN(){
    return ISBN;
}
void Book::setISBN(string number){
    ISBN = number;
}

// get and set ISBN
long long Book::getISBN_int(){
    return ISBN_int;
}
void Book::setISBN_int(string number){
    number.erase(0,6);
    stringstream ss(number);
    ss >> ISBN_int;
}

// get and set title
string Book::getTitle(){
    return title;
}
void Book::setTitle(string name){
    title = name;
}

// get and set author
string Book::getAuthor(){
    return author;
}
void Book::setAuthor(string name){
    author = name;
}

// get and set price
string Book::getPrice_str(){
    return price_str;
}
void Book::setPrice_str(string number){
    price_str = number;
}
float Book::getPrice(){
    return price;
}
void Book::setPrice(string number){
    stringstream sstr(number);
    sstr >> price;
}

// get and set stock
int Book::getStock(){
    return stock;
}
void Book::setStock(string number){
    stringstream sstr_s(number);
    sstr_s >> stock;
}
void Book::setStock_int(int number){
    stock = number;
}

// get the left child
Book* Book::getLeft(){
    return left;
}
// set the left child
void Book::setLeft(Book*n){
    left = n;
}

// get the right child
Book* Book::getRight(){
    return right;
}
// set the right child
void Book::setRight(Book*n){
    right = n;
}

// get the parent
Book* Book::getParent(){
    return parent;
}
// set the parent
void Book::setParent(Book*n){
    parent = n;
}



//***************************************************************************//
// BST Single (Uses Book but doesn't use ->next)
//***************************************************************************//
// BST constructor
BST::BST(Book* root){
    Head = root;
    current = NULL;
    par = NULL;
    tmp = NULL;
}
// BST destructor
BST::~BST(){}


Book* BST::getHead(){
    return Head;
}
void BST::setHead(Book* Node){
    Head = Node;
}

Book* BST::getCurrent(){
    return current;
}
void BST::setCurrent(Book* Node){
    current = Node;
}

Book* BST::getTmp(){
    return tmp;
}
void BST::setTmp(Book* Node){
    tmp = Node;
}


// BST insert book into tree
// Inserts books into BST based on the ISBN name.
BST* BST::insertBook(string aut, string til, string IS, string pri, string sto){

    // create new node to be inserted and initialize all values
    tmp = new Book();
    tmp->setAuthor(aut);
    tmp->setTitle(til);
    tmp->setISBN(IS);
    tmp->setISBN_int(IS);
    tmp->setPrice(pri);
    tmp->setPrice_str(pri);
    tmp->setStock(sto);
    tmp->setLeft(NULL);
    tmp->setRight(NULL);

    // parent node
    par = NULL;
    // current node
    current = Head;


    while(current != NULL){
        par = current;      // starts at head of tree and compares
        if(tmp->getISBN_int() < current->getISBN_int()){    // for less than current node isbn go left
            current = current->getLeft();
            //cout << "went left" << endl;
        }else{                                              // for greater than current node isbn go right
            current = current->getRight();
            //cout << "went right" << endl;
        }
    }

    // set new node parent to the last node
    tmp->setParent(par);
    if(tmp->getISBN_int() < par->getISBN_int()){            // set the child of the parent: if tmp ISBN < par ISBN set left
        par->setLeft(tmp);
        //cout << "   placed left" << endl;
    }else{                                                  // set the child of the parent: if tmp ISBN > par ISBN set right
        par->setRight(tmp);
        //cout << "   placed right" << endl;
    }
}

// BST sell a book in the tree
// Given the title or ISBN find a book and sell it.
BST* BST::sellBook(){
    int stock_sell;
    stock_sell = current->getStock();   // get current stock
    stock_sell--;                       // decrement value
    current->setStock_int(stock_sell);  // set new value to decremented value
}

//
// open functions
//

Book* searchISBN(BST* library, Book* current, long long key){
    library->setCurrent(current);

    //cout.precision(15);
    //cout << library->getCurrent()->getISBN_int() << endl;
    //cout << key << endl;

    // base case of search
    if(library->getCurrent()->getISBN_int() == key or library->getCurrent() == NULL){
        return library->getCurrent();
    }

    // start at head and taverse tree
    if(key < library->getCurrent()->getISBN_int()){     // if key < current ISBN: go left
        // cout << "went left" << endl;
        searchISBN(library, library->getCurrent()->getLeft(), key);

    }else{                                              // if key > current ISBN: go right
        // cout << "went right" << endl;
        searchISBN(library, library->getCurrent()->getRight(), key);

    }
}

void printInv(Book* root){
    Book* returnNode;       // start at head
    returnNode = root;

    // semi base case, cathes right node
    if(root->getLeft() == NULL){    // if no left child
        if(root->getStock() > 0){   // check for availability
            cout << root->getISBN() << endl;    // cout
        }
    }else{
        printInv(root->getLeft());  // run recursion on left child
        if(root->getStock() > 0){   // check for stock of current
        cout << root->getISBN() << endl;    // cout current
        }
    }

    if(root->getRight() == NULL){   // if no child on right do nothing
    }else{                          // else run recursion on right
        printInv(root->getRight());
    }
}

void printBar(Book* root, float price){
    Book* returnNode;
    returnNode = root;

    if(root->getLeft() == NULL){    // if no left child
        if(root->getStock() > 0 and root->getPrice() <= price){ // if available and less than  price cout info
            cout << endl;
            cout << root->getTitle() << endl;
            cout << root->getISBN() << endl;
            cout << "Price $" << root->getPrice_str() << endl;
        }
    }else{                          // has left child
        printBar(root->getLeft(), price);   // run recursion on left child
        if(root->getStock() > 0 and root->getPrice() <= price){ // if available and less than price cout info
        cout << endl;
        cout << root->getTitle() << endl;
        cout << root->getISBN() << endl;
        cout << "Price $" << root->getPrice_str() << endl;
        }
    }

    if(root->getRight() == NULL){   // has no right child
    }else{                          // has right child run recursion on
        printBar(root->getRight(), price);
    }
}
