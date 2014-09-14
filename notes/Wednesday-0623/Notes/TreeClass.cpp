#include <iostream>
#include "TreeClass.h"
#include <string>
using namespace std;

City::City(string n){
	name = n;
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
}

City::~City(){
    cout<<"calling destructor"<<endl;
}

void City::setLeftChild(City *n){
    leftChild = n;
}
City* City::getLeftChild(){
	return leftChild;
}

void City::setRightChild(City *n){
    rightChild = n;
}
City* City::getRightChild(){
	return rightChild;
}

void City::setParent(City *n){
    parent = n;
}
City* City::getParent(){
	return parent;
}

string City::getName(){
    return name;
}


Tree::Tree(){
    root = NULL;
}
Tree::~Tree(){
        //will need to delete all cities in the tree
}
void Tree::addCity(string na){
        //do we have an empty tree
        if(root == NULL){
            City* c = new City(na);

            root = c;
            cout<<"root added"<<endl;

        }else{

            cout<<"not the root, do more stuff"<<endl;
        }
    }

