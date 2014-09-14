// Chris Womack
// Dr. Hoenigman

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Lab_5_header.h"
#include "Lab_5_header.cpp"

using namespace std;


void delete_node(string node, City *Head, int *op_count){

    City *Traverse;
    Traverse = Head;
    op_count++;
    op_count++;

    // search for Denver in Linked List
    while(Traverse->getPlace() != node and Traverse->getNext() != NULL){
        Traverse = Traverse->getNext();
        op_count++;
    }

    // Delete node Denver in LinkedList
    if(Traverse->getPlace() == node){
        Traverse->getPrev()->setNext(Traverse->getNext());
        Traverse->getNext()->setPrev(Traverse->getPrev());
        delete Traverse;
        op_count++;
        op_count++;
        op_count++;
    }
    op_count++;

    // Print Cities to show deletion of Denver
    Traverse = Head;
    while(Traverse->getNext() != NULL){
        Traverse = Traverse->getNext();
        cout << Traverse->getPlace() << endl;
        op_count++;
        op_count++;
    }
    cout << endl;
}

void add_node(City *Head, int *op_count){

    string new_city, prev_city;
    cout << "Input the new city to add to network as well as the city that should precede it seperated by a space." << endl;
    cin >> new_city;
    cin >> prev_city;
    cout << endl;

    City *Traverse;
    Traverse = Head;
    op_count++;
    op_count++;

    while(Traverse->getPlace() != prev_city and Traverse->getNext() != NULL){
        Traverse = Traverse->getNext();
        op_count++;
    }

    // add the new city to the grid
    if(Traverse->getPlace() == prev_city){

        City *NewCity = new City("NULL","NULL");

        if(prev_city == "Boston"){
            NewCity->setPlace(new_city);
            NewCity->setPrev(Traverse->getPrev()->getNext());
            Traverse->setNext(NewCity);
            op_count++;
            op_count++;
            op_count++;

        }else{
            NewCity->setPlace(new_city);
            NewCity->setNext(Traverse->getNext());
            NewCity->setPrev(Traverse->getNext()->getPrev());
            Traverse->getNext()->setPrev(NewCity);
            Traverse->setNext(NewCity);
            op_count++;
            op_count++;
            op_count++;
            op_count++;
            op_count++;

        }
        op_count++;
    }
    op_count++;

    // Print Cities to show Addition of New City
    Traverse = Head;
    while(Traverse->getNext() != NULL){
        Traverse = Traverse->getNext();
        cout << Traverse->getPlace() << endl;
        //cout << Traverse->getNext() << endl;
        op_count++;
        op_count++;
    }
    cout << endl;;
}

int main()
{
    // input file
    ifstream line_file("messageln.txt");
    ofstream output("output.txt");

    // Names array
    string cityArr[] = {"Los_Angeles", "Phoenix", "Denver",
    "Dallas", "St_Louis", "Chicago", "Atlanta",
    "Washington,D.C", "New_York", "Boston"};

    int op_count = 0;

    // initialize reference node
    City *Head  = new City("null", "null");
    op_count++;

    // Create the linked list
    City *LA  = new City(cityArr[0], "null");
    Head->setNext(LA);
    op_count++;
    op_count++;

    City *PHX = new City(cityArr[1], "null");
    LA->setNext(PHX);
    op_count++;
    op_count++;

    City *DEN = new City(cityArr[2], "null");
    PHX->setNext(DEN);
    PHX->setPrev(LA);
    op_count++;
    op_count++;
    op_count++;

    City *DAL = new City(cityArr[3], "null");
    DEN->setNext(DAL);
    DEN->setPrev(PHX);
    op_count++;
    op_count++;
    op_count++;

    City *STL = new City(cityArr[4], "null");
    DAL->setNext(STL);
    DAL->setPrev(DEN);
    op_count++;
    op_count++;
    op_count++;

    City *CHI = new City(cityArr[5], "null");
    STL->setNext(CHI);
    STL->setPrev(DAL);
    op_count++;
    op_count++;
    op_count++;

    City *ATL = new City(cityArr[6], "null");
    CHI->setNext(ATL);
    CHI->setPrev(STL);
    op_count++;
    op_count++;
    op_count++;

    City *DC  = new City(cityArr[7], "null");
    ATL->setNext(DC);
    ATL->setPrev(CHI);
    op_count++;
    op_count++;
    op_count++;

    City *NY = new City(cityArr[8], "null");
    DC->setNext(NY);
    DC->setPrev(ATL);
    op_count++;
    op_count++;
    op_count++;

    City *BOS = new City(cityArr[9], "null");
    NY->setNext(BOS);
    NY->setPrev(DC);
    BOS->setPrev(NY);
    op_count++;
    op_count++;
    op_count++;
    op_count++;

    City *Tail;
    Tail = BOS;
    op_count++;
    op_count++;

    // pull in line from file
    string message;
    int message_count = 0;

    // send message forward across the network
    cout << "The message at Boston is:" << endl;
    while(getline(line_file, message,' ')){

        // initialize pointer of type city
        City *current;
        op_count++;
        // set current to first node
        current = Head;
        op_count++;
        // set current message
        current->setMsg(message);
        op_count++;

        // transmit the message to the next nodes
        current->transmitMsg(current, message, 0, &op_count);
        op_count++;

        if(BOS->getMsg() == message){
            output << BOS->getMsg() << " ";
            cout << BOS->getMsg() << " ";
        }
        message_count++;
    }

    cout << endl;

    line_file.close();
    ifstream back_line("messageln.txt");

    // send message back across network
    cout << "The message at sent back to LA is:" << endl;
    while(getline(back_line, message,' ')){
        op_count++;

        // initialize pointer of type city
        City *current;
        op_count++;

        // set current to first node
        current = Tail;
        op_count++;

        // set current message
        current->setMsg(message);
        op_count++;

        // transmit the message to the next nodes
        current->transmitMsg(current, message, 1, &op_count);
        op_count++;

        if(LA->getMsg() == message){
            cout << LA->getMsg() << " ";
        }
        op_count++;
    }
    cout << endl;

    // delete denver from linked list
    delete_node("Denver",Head, &op_count);

    // add city to linked list
    add_node(Head, &op_count);
    if(Tail->getNext() != NULL){
        Tail = Tail->getNext();
    }
    op_count++;

    back_line.close();
    ifstream send_again("messageln.txt");

    // send message forward again across new network
    cout << "The message at sent to the last city is:" << endl;
    while(getline(send_again, message,' ')){

        // initialize pointer of type city
        City *current;
        City *Last;
        op_count++;
        op_count++;

        // set current to first node
        current = Head;
        Last = Tail;
        op_count++;
        op_count++;

        // set current message
        current->setMsg(message);
        op_count++;

        // transmit the message to the next nodes
        current->transmitMsg(current, message, 0, &op_count);

        if(Last->getMsg() == message){
            cout << Last->getMsg() << " ";
        }
        message_count++;
        op_count++;
    }
    cout << endl;

    send_again.close();
    ifstream send_back("messageln.txt");

    // send message back again across new network
    cout << "The message at sent back to the first city is:" << endl;
    while(getline(send_back, message,' ')){

        // initialize pointer of type city
        City *current;
        City *Last;
        op_count++;
        op_count++;

        // set current to first node
        current = Head;
        Last = Tail;
        op_count++;
        op_count++;

        // set current message
        current->setMsg(message);
        op_count++;

        // transmit the message to the next nodes
        current->transmitMsg(current, message, 1, &op_count);
        op_count++;

        if(Head->getMsg() == message){
            cout << Head->getMsg() << " ";
        }
        message_count++;
        op_count++;
    }

    cout << endl;

    // garbage collection
    City *node2delete;
    City *next_node;
    op_count++;
    op_count++;

    node2delete = Head;
    next_node = node2delete->getNext();
    op_count++;
    op_count++;

    while(node2delete->getNext() != NULL){
        cout << "Deleting: " << node2delete->getPlace() << endl;
        delete node2delete;
        node2delete = next_node;
        next_node = next_node->getNext();
        op_count++;
        op_count++;
        op_count++;
        op_count++;
    }
    cout << "Deleting: " << node2delete->getPlace() << endl;
    delete node2delete;
    op_count++;

    cout << endl;
    cout << "Operations count for creating, accessing, or manipulating class City is "<<op_count << endl;

    send_back.close();
    return 0;
}

