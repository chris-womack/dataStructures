#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Lab_4_header.h"
#include "Lab_4_header.cpp"

using namespace std;

int main()
{
    // input file
    ifstream line_file("messageln.txt");

    // Names array
    string cityArr[] = {"Los Angeles", "Phoenix", "Denver",
    "Dallas", "St. Louis", "Chicago", "Atlanta",
    "Washington,D.C", "New York", "Boston"};

    // initialize reference node
    City *Head  = new City("null", "null");

    // Create the linked list
    City *LA  = new City(cityArr[0], "null");
    Head->setNext(LA);

    City *PHX = new City(cityArr[1], "null");
    LA->setNext(PHX);

    City *DEN = new City(cityArr[2], "null");
    PHX->setNext(DEN);

    City *DAL = new City(cityArr[3], "null");
    DEN->setNext(DAL);

    City *STL = new City(cityArr[4], "null");
    DAL->setNext(STL);

    City *CHI = new City(cityArr[5], "null");
    STL->setNext(CHI);

    City *ATL = new City(cityArr[6], "null");
    CHI->setNext(ATL);

    City *DC  = new City(cityArr[7], "null");
    ATL->setNext(DC);

    City *NY = new City(cityArr[8], "null");
    DC->setNext(NY);

    City *BOS = new City(cityArr[9], "null");
    NY->setNext(BOS);

    // pull in line from file
    string message;
    while(getline(line_file, message,' ')){

        // initialize pointer of type city
        City *current;

        // set current to first node
        current = Head;

        // set current message
        current->setMsg(message);

        // transmit the message to the next nodes
        current->transmitMsg(current, message);

        cout <<" The message at Boston      " <<
            BOS->getMsg() << endl;
    }

    line_file.close();
    return 0;
}
