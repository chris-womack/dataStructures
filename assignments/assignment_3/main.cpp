// Chris Womack
// Dr. Hoenigman
// Assignment III

#include "bst.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    char ch;
    int char_int;
    int line_count = 0;
    int option = 0;

    long long isbn = 0;
    float price;

    string line;
    string attrib[5];

    Book* root;
    Book* foundISBN = NULL;
    BST* library;

    // open input file stream
    ifstream inventory ("inventory.txt");

    // read in all lines from inventory file
    while(getline(inventory, line) != NULL){
        istringstream str(line);    // convert to string stream

        // split string into the 5 attributes: Author, Title, ISBN, Price, Quantity
        for(int i = 0; i < 5; i++){
            getline(str, attrib[i], ';');
        }

        // erase first space from all strings and $ from price
        attrib[1].erase(0,1);
        attrib[2].erase(0,1);
        attrib[3].erase(0,2);
        attrib[4].erase(0,1);

        // assign root node
        if(line_count == 0){
            root = new Book();
            root->setAuthor(attrib[0]);
            root->setTitle(attrib[1]);
            root->setISBN(attrib[2]);
            root->setISBN_int(attrib[2]);
            root->setPrice(attrib[3]);
            root->setPrice_str(attrib[3]);
            root->setStock(attrib[4]);

            // create the binary search tree library
            library = new BST(root);

        }else{  // if not the first run, then add node to bst library

            // insert book into bst
            library->insertBook(attrib[0],attrib[1],attrib[2],attrib[3],attrib[4]);
        }

        // track how many lines inputed
        line_count++;
    }

    // at this point library has been built

    while(true){
        // options for editing library
        cout << endl;
        cout << "Choose and option below." << endl;
        cout << "1) Find a Book by ISBN" << endl;
        cout << "2) Sell a Book by ISBN" << endl;
        cout << "3) Print entire inventory" << endl;
        cout << "4) Print bargain books" << endl;
        cout << "5) End Program" << endl;
        cin >> option;

        if(option == 1){    // find
            cout << "Enter the books exact ISBN number. Example: 3540760474" << endl;
            cin >> isbn;

            // search for node with ISBN number
            foundISBN = searchISBN(library, library->getHead(), isbn);

            // not ISBN, not found
            if(foundISBN->getISBN_int() != isbn){
                cout << endl;
                cout << "Book not found." << endl;
            }else{                                      // else print all info
                cout << endl;
                cout << "Author   :: " << foundISBN->getAuthor() << endl;
                cout << "Title    :: " << foundISBN->getTitle() << endl;
                cout << "ISBN #   :: " << foundISBN->getISBN() << endl;
                cout << "Price    :: $" << foundISBN->getPrice() << endl;
                cout << "In Stock :: " << foundISBN->getStock() << endl;
            }
        }else if(option == 2){  // sell
            cout << "Enter the books exact ISBN number. Example: 3540760474" << endl;
            cin >> isbn;

            // search for the node with ISBN number
            foundISBN = searchISBN(library, library->getHead(),isbn);

            if(foundISBN->getISBN_int() != isbn){       // if not found, cout not found
                cout << endl;
                cout << "Book not found." << endl;
            }else{
                if(library->getCurrent()->getStock() == 0){     // if there are no books, cout no books
                    cout << endl;
                    cout << "No more copies of this book are for sale" << endl;
                }else{                                          // else decrement with sell book and print info
                    library->setCurrent(foundISBN);
                    library->sellBook();
                    cout << endl;
                    cout << "Title    :: " << library->getCurrent()->getTitle() << endl;
                    cout << "ISBN #   :: " << library->getCurrent()->getISBN() << endl;
                    cout << "In Stock :: " << library->getCurrent()->getStock() << endl;
                }
            }

        }else if(option == 3){  // print inventory
            printInv(library->getHead());
        }else if(option == 4){  // print bargain
            cout << "Enter price that you are willing to pay. Example: 15.99" << endl;
            cin >> price;
            printBar(library->getHead(), price);
        }else{
            break;
        }
    }
    inventory.close();
    return 0;
}
