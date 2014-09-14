// Chris Womack
// Dr. Hoenigman
// Lab 9

#include <iostream>
#include <string>
#include "TreeClass.h"

using namespace std;

int main()
{
    int city_count = 0;

    string yorn;
    string parent;
    string new_city;

    City *root;
    City *current;
    Tree *cityTree = new Tree();

    while(true){

        cout << "Do you wish to enter a new city. (yes or no)" << endl;
        cin >> yorn;

        if(yorn == "yes"){
            // first time through
            if(city_count == 0){
                cout << "What is the name of the new city." << endl;
                cin >> new_city;
                cout << endl;
            }else{
                cout << "What is the name of the parent city." << endl;
                cin >> parent;
                cout << "What is the name of the new city." << endl;
                cin >> new_city;
                cout << endl;
            }

            // first node is set
            if(city_count == 0){
                root = new City(new_city);
                city_count++;
                cout << "Root Node added." << endl;
            }else{      // add node: first left, then right
                cityTree->addCity(root, parent, new_city, &city_count);
            }
        }else{
            break;
        }
        cout << endl;
        // recursive counting
        cout << "Using Recursion the number of city's in the tree is " << cityTree->CountNodes_R(root) << endl;
        // pointer counting for verification
        cout << "Using Pointers the number of city's in the tree is " << city_count << endl;
        cout << "Using NO Recursion the number of city's in the tree is " << cityTree->CountNodes(root) << endl;
        cout << endl;
    }
}
