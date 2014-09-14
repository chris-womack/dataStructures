// Chris Womack
// Dr. Hoenigman
// Lab_7

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Lab_6_header.h"

using namespace std;

int main()
{
    int command_1;
    char command_2;

    while(true){
        cout << endl << "1. Create Stack" << endl << "2. Create Queue"
         << endl << "3. Exit Program" << endl << "::: ";
        cin >> command_1;

        if(command_1 == 1 || command_1  == 2){
            cout << endl << "a) arrays" << endl << "b) single linked list"
             << endl << "c) double linked lists" << endl << "::: ";
            cin >> command_2;
        }

        if(command_1 == 1 && command_2 == 'a'){
            stackArray();
        }else if(command_1 == 1 && command_2 == 'b'){
            stackLinked();
        }else if(command_1 == 1 && command_2 == 'c'){
            stackDblinked();
        }else if(command_1 == 2 && command_2 == 'a'){
            queueArray();
        }else if(command_1 == 2 && command_2 == 'b'){
            queueLinked();
        }else if(command_1 == 2 && command_2 == 'c'){
            queueDblinked();
        }else if(command_1 = 3){
            break;
        }
    }
}

