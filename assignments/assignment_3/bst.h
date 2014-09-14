// Chris Womack
// Dr. Hoenigman
// Assignment III

#ifndef BST_HEADER_H_INCLUDED
#define BST_HEADER_H_INCLUDED

#include <string>

using namespace std;

//  book or nodes of tree
class Book{
private:
    string ISBN;
    long long ISBN_int;
    string title;
    string author;
    int price;
    string price_str;
    int stock;
    Book* left;
    Book* right;
    Book* parent;

public:
    Book();      // constructor
    ~Book();     // destructor

    // get and set ISBN
    string getISBN();
    void setISBN(string number);

    // get and set ISBN integer
    long long getISBN_int();
    void setISBN_int(string number);

    // get and set title
    string getTitle();
    void setTitle(string name);

    // get and set author
    string getAuthor();
    void setAuthor(string name);

    // get and set price
    string getPrice_str();
    void setPrice_str(string number);

    // get and set price
    float getPrice();
    void setPrice(string number);

    // get and set stock
    int getStock();
    void setStock(string number);
    void setStock_int(int number);

    // get and set left child
    Book *getLeft();
    void setLeft(Book*);

    // get and set right child
    Book *getRight();
    void setRight(Book*);

    // get and set parent
    Book *getParent();
    void setParent(Book*);
};

// tree object containing book nodes
class BST{
private:
    Book* Head;
    Book* current;
    Book* par;
    Book* tmp;

public:
    BST(Book* root);      // constructor
    ~BST();     // destructor

    // comments on all functions in .cpp file
    Book* getHead();
    void setHead(Book* Node);
    Book* getCurrent();
    void setCurrent(Book* Node);
    Book* getTmp();
    void setTmp(Book* Node);

    BST *insertBook(string author, string title, string ISBN, string price, string stock);
    //Book *searchTitle(string key);
    //Book *searchISBN(BST* library, Book* root, string key);
    BST* findBook();
    BST* sellBook();
   // Book* printInventory(Book* Node);
    BST *printBargain();
};

Book* searchISBN(BST* library, Book* current, long long key);
void printInv(Book* current);
void printBar(Book* current, float price);

#endif //  BST_HEADER_H_INCLUDED

