#include "Struct.h"
#include <iostream>
#include <string>

using namespace std;

//////////////////////
//BattleShip Functions
//////////////////////

// constructor and destructor
BattleShip::BattleShip(){
    Node* Head = NULL;
    Node* Tail = NULL;
    Node* tmp = NULL;
}
BattleShip::~BattleShip(){}

// get set Head
Node* BattleShip::getHead(){
    return Head;
}
void BattleShip::setHead(Node* node){
    Head = node;
}

// get set Tail
Node* BattleShip::getTail(){
    return Tail;
}
void BattleShip::setTail(Node* node){
    Tail = node;
}

// get set tmp
Node* BattleShip::getTmp(){
    return tmp;
}
void BattleShip::setTmp(Node* node){
    tmp = node;
}


//////////////////////
//Submarine Functions
//////////////////////

// constructor and destructor
Submarine::Submarine(){
    Node* Head = NULL;
    Node* Tail = NULL;
    Node* tmp = NULL;
}
Submarine::~Submarine(){}

// get set Head
Node* Submarine::getHead(){
    return Head;
}
void Submarine::setHead(Node* node){
    Head = node;
}

// get set Tail
Node* Submarine::getTail(){
    return Tail;
}
void Submarine::setTail(Node* node){
    Tail = node;
}

// get set tmp
Node* Submarine::getTmp(){
    return tmp;
}
void Submarine::setTmp(Node* node){
    tmp = node;
}


//////////////////////
//Cruiser Functions
//////////////////////

// constructor and destructor
Cruiser::Cruiser(){
    Node* Head = NULL;
    Node* Tail = NULL;
    Node* tmp = NULL;
}
Cruiser::~Cruiser(){}

// get set Head
Node* Cruiser::getHead(){
    return Head;
}
void Cruiser::setHead(Node* node){
    Head = node;
}

// get set Tail
Node* Cruiser::getTail(){
    return Tail;
}
void Cruiser::setTail(Node* node){
    Tail = node;
}

// get set tmp
Node* Cruiser::getTmp(){
    return tmp;
}
void Cruiser::setTmp(Node* node){
    tmp = node;
}


//////////////////////
//Destroyer Functions
//////////////////////

// constructor
Destroyer::Destroyer(){
    Node* Head = NULL;
}
// destructor
Destroyer::~Destroyer(){}

// get set Head
Node* Destroyer::getHead(){
    return Head;
}
void Destroyer::setHead(Node* node){
    Head = node;
}
