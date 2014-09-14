#include "Lab_4_header.h"

using namespace std;

// constructor
City::City(string city, string word){
    place = city;
    Msg = word;
    next = 0;
    prev = 0;
}

// destructor
City::~City(){}

// get the next position
City* City::getNext(){
    return next;
}

// set the next position
void City::setNext(City *n){
    next = n;
}

// get the previous position
City* City::getPrev(){
    return prev;
}

// set the previous position
void City::setPrev(City *n){
    prev = n;
}

// get the message
string City::getMsg(){
    return Msg;
}

// set the message
void City::setMsg(string message){
    Msg = message;
}

// get the city
string City::getPlace(){
    return place;
}

// set the city
void City::setPlace(string city){
   place = city;
}

// transmit the message through all cities
void City::transmitMsg(City* current, string message, int k, int *op_count){

    if(k == 0){
        // loop through nodes till we hit the end of linked list
        while(current->getNext() != NULL){
            (*op_count)++;

            // initialize next pointer to point to next node
            City *next = current->getNext();
            (*op_count)++;

            // set the next nodes message to message
            next->setMsg(message);
            (*op_count)++;

            // erase current nodes message
            current->setMsg("NULL");
            (*op_count)++;

            // set current to next node
            current = current->getNext();
            (*op_count)++;
        }
    }else{
        // loop through nodes till we hit the end of linked list
        while(current->getPrev() != NULL){
            (*op_count)++;

            // initialize next pointer to point to next node
            City *prev = current->getPrev();
            (*op_count)++;

            // set the next nodes message to message
            prev->setMsg(message);
            (*op_count)++;

            // erase current nodes message
            current->setMsg("NULL");
            (*op_count)++;

            // set current to next node
            current = current->getPrev();
            (*op_count)++;
        }
    }
}

