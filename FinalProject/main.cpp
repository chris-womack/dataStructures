#include "Node.h"
#include "myStruct.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    // set the seed for the random from the clock at the start of main
    seed();

    // hash table for guess checking: initialize to 0
    int hashTable[2040];
    for(int i = 0; i < 2040; i++){
        hashTable[i] = 0;
    }

    // variables needed for program
    int x;
    int y;
    int hits;
    int type;
    int xGuess;
    int yGuess;
    int shipSlot;
    int newXsize;
    int newYsize;
    int guessDup;
    int hashGuess;
    int guessTaken;
    int xBoardsize;
    int yBoardsize;
    int guessAllow;
    int orientation;
    int cruiserCount;
    int annihilation;
    int destroyerCount;
    int submarineCount;
    int battleshipCount;
    unsigned int hashSize;

    int games = 0;
    int opCounter = 0;

    Node* tmp;
    arrayStruct arr[101];

    // open all ouput streams
    ofstream boardSize ("boardSize.txt");
    ofstream opNum ("operationsCount.txt");
    ofstream guessNum ("guessNeeded.txt");
    ofstream output ("output.txt");

    while(games < 100){
        xBoardsize = rand() % 17 + 4;   // random value for number of rows on board
        yBoardsize = rand() % 17 + 4;   // random value for number of columns on board

        newXsize = 0;   // tmp storage for decremented boards
        newYsize = 0;   // tmp storage for decremented boards

        guessAllow = xBoardsize * yBoardsize;   // total number of guesses allowed
        guessTaken = 0;

/* print board size and total cells
        cout << endl;
        cout << "The Board is " << xBoardsize << " rows by " << yBoardsize << " columns." << endl;
        cout << endl;

        cout << "Total number of guesses allowed " << guessAllow << endl;
        cout << endl;
*/

        // generate board, 2D array of nodes
        Node* board[xBoardsize][yBoardsize];
        for(int i = 0; i < xBoardsize; i ++){// rows
            for(int j = 0; j < yBoardsize; j++){// columns
                board[i][j] = new Node();       // create node
                // set all node values to null
                board[i][j]->setShip("NULL");
                board[i][j]->setOccupy(0);
                board[i][j]->setHit(0);
                board[i][j]->setNext(NULL);
                board[i][j]->setPrev(NULL);
                opCounter += 6;
            }
        }

        x = 0;                  // x value for placement
        y = 0;                  // y value for placement
        type = 0;               // type of ship created
        shipSlot = 0;           // how many nodes occupied by ships
        orientation = 0;        // vertical or horizontal orientation

        // counters for different ships
        cruiserCount = 0;
        destroyerCount = 0;
        submarineCount = 0;
        battleshipCount = 0;

        // gen random ship positions and place on board
        while(shipSlot < (guessAllow * 0.1)){// only 10% of the board can be occupied by ships
            type = rand() % 4 + 1;      // determine what type of ship to place randomly: random val 1-4

            if(type == 1){// destroyer
                while(true){// if no free area found run until the x,y coords hit a free area
                    x = rand() % xBoardsize;
                    y = rand() % yBoardsize;

                    if(board[x][y]->getOccupy() == 0){// place ship if no ship is present
                        board[x][y]->setOccupy(1);              // set occupation
                        board[x][y]->setShip("DESTROYER");      // set type

                        // increment counters
                        opCounter += 3;
                        destroyerCount++;
                        shipSlot++;
/* print placement
                        cout << endl;
                        cout << "A destroyer has been placed at coordinates (" << x << "," << y << ")" << endl;
*/
                        break;
                    }
                }
            }else if(type == 2){// cruiser
                while(true){// if no free area found run until the x,y coords hit a free area
                    newXsize = xBoardsize - 1;  // remove last row for spacing
                    newYsize = yBoardsize - 1;  // remove last column for spacing

                    x = rand() % newXsize;
                    y = rand() % newYsize;

                    if(board[x][y]->getOccupy() == 0){// place ship if no ship is present
                        orientation = rand() % 2;   // set orientation: val 0-1

/* print orientation
                        cout << endl;
                        cout << "Selected Orientation is " << orientation << endl;
*/
                        if(orientation == 0){// place ship vertically
                            if(board[x+1][y]->getOccupy() == 0){// if the next row is not occupied
                                // head
                                board[x][y]->setOccupy(1);              // set occupation
                                board[x][y]->setShip("CRUISER");        // set type
                                board[x][y]->setNext(board[x+1][y]);    // set next
                                // tail
                                board[x+1][y]->setPrev(board[x][y]);    // set prev
                                board[x+1][y]->setOccupy(1);            // set occupation
                                board[x+1][y]->setShip("CRUISER");      // set type

                                // increment counters
                                opCounter += 6;
                                cruiserCount++;
                                shipSlot += 2;
/* print placement
                                cout << "A cruiser has been placed at coordinates (" << x << "," << y << ") and ("
                                    << x+1 << "," << y << ") in the vertical orientation." << endl;
*/
                                break;
                            }
                        }else{// place ship horizontally
                            if(board[x][y+1]->getOccupy() == 0){// if the next column is not occupied
                                // head
                                board[x][y]->setOccupy(1);
                                board[x][y]->setShip("CRUISER");
                                board[x][y]->setNext(board[x][y+1]);
                                // tail
                                board[x][y+1]->setPrev(board[x][y]);
                                board[x][y+1]->setOccupy(1);
                                board[x][y+1]->setShip("CRUISER");

                                // increment counters
                                opCounter += 6;
                                cruiserCount++;
                                shipSlot += 2;
/* print placement
                                //cout << "A cruiser has been placed at coordinates (" << x << "," << y << ") and ("
                                //    << x << "," << y+1 << ") in the horizontal orientation." << endl;
*/
                                break;
                            }
                        }
                    }
                }

            }else if(type == 3){// submarine
                while(true){// if no free area found run until the x,y coords hit a free area
                    newXsize = xBoardsize - 2;  // remove last row for spacing
                    newYsize = yBoardsize - 2;  // remove last columns for spacing

                    x = rand() % newXsize;
                    y = rand() % newYsize;

                    if(board[x][y]->getOccupy() == 0){// place ship is no ship present
                        orientation = rand() % 2;   // set orientation
/* print orientation
                        cout << endl;
                        //cout << "Selected Orientation is " << orientation << endl;
*/
                        if(orientation == 0){// place vertically
                            if(board[x+1][y]->getOccupy() == 0 and board[x+2][y]->getOccupy() == 0){// if the next two rows are free
                                // head
                                board[x][y]->setOccupy(1);              // set occupation
                                board[x][y]->setShip("SUBMARINE");      // set type
                                board[x][y]->setNext(board[x+1][y]);    // set next
                                // mid section
                                board[x+1][y]->setOccupy(1);            // set occupation
                                board[x+1][y]->setShip("SUBMARINE");    // set type
                                board[x+1][y]->setPrev(board[x][y]);    // set prev
                                board[x+1][y]->setNext(board[x+2][y]);  // set next
                                // tail
                                board[x+2][y]->setPrev(board[x+1][y]);  // set prev
                                board[x+2][y]->setOccupy(1);            // set occupation
                                board[x+2][y]->setShip("SUBMARINE");    // set type

                                // increment counters
                                opCounter += 10;
                                submarineCount++;
                                shipSlot += 3;
/* print placement
                                cout << "A submarine has been placed at coordinates (" << x << "," << y << "), ("
                                   << x+1 << "," << y << "), and (" << x+2 << "," << y << ") in the horizontal orientation." << endl;
*/
                                break;
                            }
                        }else{// place horizontally
                            if(~board[x][y+1]->getOccupy() == 0 and ~board[x][y+2]->getOccupy() == 0){// if the next two columns are free
                                // head
                                board[x][y]->setOccupy(1);              // set occupation
                                board[x][y]->setShip("SUBMARINE");      // set type
                                board[x][y]->setNext(board[x][y+1]);    // set next
                                // mid section
                                board[x][y+1]->setOccupy(1);            // set occupation
                                board[x][y+1]->setShip("SUBMARINE");    // set type
                                board[x][y+1]->setPrev(board[x][y]);    // set prev
                                board[x][y+1]->setNext(board[x][y+2]);  // set next
                                // tail
                                board[x][y+2]->setPrev(board[x][y+1]);  // set prev
                                board[x][y+2]->setOccupy(1);            // set occupation
                                board[x][y+2]->setShip("SUBMARINE");    // set type

                                // increment counters
                                opCounter += 10;
                                submarineCount++;
                                shipSlot += 3;
/* print placement
                                cout << "A submarine has been placed at coordinates (" << x << "," << y << "), ("
                                    << x << "," << y+1 << "), and (" << x << "," << y+2 << ") in the horizontal orientation." << endl;
*/
                                break;
                            }
                        }
                    }
                }
            }else{// battleship
                while(true){// if no free area found run until the x,y coords hit a free area
                    newXsize = xBoardsize - 3;  // remove last row for spacing
                    newYsize = yBoardsize - 3;  // remove last columns for spacing

                    x = rand() % newXsize;
                    y = rand() % newYsize;

                    if(board[x][y]->getOccupy() == 0){// place ship is no ship present
                        orientation = rand() % 2;   // set orientation
/* print orientation
                        cout << endl;
                        cout << "Selected Orientation is " << orientation << endl;
*/
                        if(orientation == 0){// place vertically
                            if(board[x+1][y]->getOccupy() == 0 and board[x+2][y]->getOccupy() == 0 and board[x+3][y]->getOccupy() == 0){// if the next three rows are free
                                // head
                                board[x][y]->setOccupy(1);              // set occupation
                                board[x][y]->setShip("BATTLESHIP");     // set type
                                board[x][y]->setNext(board[x+1][y]);    // set next
                                // mid section one
                                board[x+1][y]->setOccupy(1);            // set occupation
                                board[x+1][y]->setShip("BATTLESHIP");   // set type
                                board[x+1][y]->setPrev(board[x][y]);    // set prev
                                board[x+1][y]->setNext(board[x+2][y]);  // set next
                                // mid section two
                                board[x+2][y]->setPrev(board[x+1][y]);  // set prev
                                board[x+2][y]->setNext(board[x+3][y]);  // set next
                                board[x+2][y]->setOccupy(1);            // set occupation
                                board[x+2][y]->setShip("BATTLESHIP");   // set type
                                // tail
                                board[x+3][y]->setPrev(board[x+2][y]);  // set prev
                                board[x+3][y]->setOccupy(1);            // set occupation
                                board[x+3][y]->setShip("BATTLESHIP");   // set type

                                // increment counters
                                opCounter += 14;
                                battleshipCount++;
                                shipSlot += 4;
/* print placement
                                cout << "A battleship has been placed at coordinates (" << x << "," << y << "), ("
                                    << x+1 << "," << y << "), (" << x+2 << "," << y << "), and (" << x+3 << ","
                                        << y << ") in the vertical orientation." << endl;
*/
                                break;
                            }
                        }else{// place horizontally
                            if(board[x][y+1]->getOccupy() == 0 and board[x][y+2]->getOccupy() == 0 and board[x][y+3]->getOccupy() == 0){// if the next three columns are free
                                // head
                                board[x][y]->setOccupy(1);              // set occupation
                                board[x][y]->setShip("BATTLESHIP");     // set type
                                board[x][y]->setNext(board[x][y+1]);    // set next
                                // mid section one
                                // mid section
                                board[x][y+1]->setOccupy(1);            // set occupation
                                board[x][y+1]->setShip("BATTLESHIP");   // set type
                                board[x][y+1]->setPrev(board[x][y]);    // Set prev
                                board[x][y+1]->setNext(board[x][y+2]);  // set next
                                // mid section two
                                board[x][y+2]->setPrev(board[x][y+1]);  // set prev
                                board[x][y+2]->setNext(board[x][y+3]);  // set next
                                board[x][y+2]->setOccupy(1);            // set occupation
                                board[x][y+2]->setShip("BATTLESHIP");   // set type
                                // tail
                                board[x][y+3]->setPrev(board[x][y+2]);  // set prev
                                board[x][y+3]->setOccupy(1);            // set occupation
                                board[x][y+3]->setShip("BATTLESHIP");   // set type

                                // increment counters
                                opCounter += 14;
                                battleshipCount++;
                                shipSlot += 4;
/* print placement
                                cout << "A battleship has been placed at coordinates (" << x << "," << y << "), ("
                                    << x << "," << y+1 << "), (" << x << "," << y+2 << "), and (" << x << ","
                                        << y+3 << ") in the horizontal orientation." << endl;
*/
                                break;
                            }
                        }
                    }
                }
            }
        }

/* print board
        cout << "Number of ship slots placed are " << shipSlot << " which is 10% of " << guessAllow << endl;
        cout << endl;
        cout << "The board as it stands before guesses" << endl;

        cout << endl;
        cout << "D = Destroyer :: C = Cruiser :: S = Submarine :: B = Battleship" << endl;
        cout << endl;
        // print the board before guesses are taken
        for(int i = 0; i < xBoardsize; i++){
            cout << "                   ";
            for(int j = 0; j < yBoardsize; j++){
                if(board[i][j]->getShip() == "BATTLESHIP"){
                    cout << "B";
                }else if(board[i][j]->getShip() == "SUBMARINE"){
                    cout << "S";
                }else if(board[i][j]->getShip() == "CRUISER"){
                    cout << "C";
                }else if(board[i][j]->getShip() == "DESTROYER"){
                    cout << "D";
                }else{
                    cout << "-";
                }
            }
            cout << endl;
        }

        cout << "There are " << destroyerCount << " destroyers, " << cruiserCount << " cruisers, " << submarineCount << " subs, and "
            << battleshipCount << " battleships." << endl;

        cout << endl;
        //cout << "Hash table size is " << hashSize << endl;
        //cout << "Row by column is " << xBoardsize << yBoardsize << endl;
*/

        // concat integers for hashTable i.e. 20 X 20 becomes 2020 then add 20 for collisions
        hashSize = concatenate(xBoardsize, yBoardsize, 0) + 20;

        // zero hashtable for the size of table
        for(unsigned int i = 0; i < hashSize; i++){
            hashTable[i] = 0;
            opCounter++;
        }

        hits = 0;               // total hits
        xGuess = 0;             // x guess
        yGuess = 0;             // y guess
        guessDup = 0;           // duplicate guesses
        hashGuess = 0;          // concatenated guess
        guessTaken = 0;         // how many guess attempts
        annihilation = 0;       // all ships have been destroyed

        // start guessing
        while(guessTaken < guessAllow and annihilation == 0){// while ships exist and all guesses have not been taken
            xGuess = rand() % xBoardsize;
            yGuess = rand() % yBoardsize;

            // concat guesses for table value
            hashGuess = concatenate(xGuess, yGuess, hashSize);
            if(hashTable[hashGuess] == 0){// check if the guess has been taken
                if(board[xGuess][yGuess]->getShip() == "NULL"){// nothing in the spot
                    hashTable[hashGuess] = 1;   // set table to guessed
                    opCounter++;
                    guessTaken++;
                }else{// hit a ship
                    board[xGuess][yGuess]->setHit(1);   // set the hit
                    hashTable[hashGuess] = 1;           // set hashTable to 1 for guess checker
                    opCounter++;
                    guessTaken++;
                    hits = 0;   // zero hits for death check

                    if(board[xGuess][yGuess]->getShip() == "DESTROYER"){// destroyer
                        destroyerCount--;   // kill the destroyer

                    }else if(board[xGuess][yGuess]->getShip() == "CRUISER"){// cruiser
                        tmp = board[xGuess][yGuess];
                        while(tmp->getPrev() != NULL){// find head node
                            tmp = tmp->getPrev();
                            opCounter++;
                        }

                        // check if all nodes have been hit
                        hits = deathCheck(tmp, &opCounter);
                        opCounter++;
                        if(hits == 2){// confirm 2 hits
                            cruiserCount--; // kill cruiser
                        }

                    }else if(board[xGuess][yGuess]->getShip() == "SUBMARINE"){// submarine
                        tmp = board[xGuess][yGuess];
                        while(tmp->getPrev() != NULL){// find head node
                            tmp = tmp->getPrev();
                            opCounter++;
                        }

                        // check if all nodes have been hit
                        hits = deathCheck(tmp, &opCounter);
                        opCounter++;
                        if(hits == 3){// confirm 3 hits
                            submarineCount--;// kill sub
                        }

                    }else if(board[xGuess][yGuess]->getShip() == "BATTLESHIP"){// battleship
                        tmp = board[xGuess][yGuess];
                        while(tmp->getPrev() != NULL){// find head node
                            tmp = tmp->getPrev();
                            opCounter++;
                        }

                        // check if all nodes have been hit
                        hits = deathCheck(tmp, &opCounter);
                        opCounter++;
                        if(hits == 4){// confirm 4 hits
                            battleshipCount--;// kill battleship
                        }
                    }
                }
            }else{// guess has already been taken, do nothing
                guessDup++;
            }

            if(destroyerCount <= 0 and cruiserCount <= 0 and submarineCount <= 0 and battleshipCount <= 0){// no ships are left
                annihilation = 1;// break while
            }
/* print ship count, ect..
            cout << "D::" << destroyerCount << " ::C::" << cruiserCount << " ::S::" << submarineCount
                << " ::B::" << battleshipCount << " ::GT::" << guessTaken << " ::GD::" << guessDup << " ::XY::"
                    << xGuess << yGuess << " ::CON:: " << concatenate(xGuess,yGuess, hashSize) << " ::HT::" << hashTable[hashGuess]
                        << " ::HG::" << hashGuess << endl;
                        */
        }
/* print boards side by side
        cout << endl;
        cout << "D = Destroyer :: C = Cruiser :: S = Submarine :: B = Battleship" << endl;
        cout << endl;
            // print the board before guesses are taken
        for(int i = 0; i < xBoardsize; i++){
            cout << "                   ";
            for(int j = 0; j < yBoardsize; j++){
                if(board[i][j]->getShip() == "BATTLESHIP"){
                    cout << "B";
                }else if(board[i][j]->getShip() == "SUBMARINE"){
                    cout << "S";
                }else if(board[i][j]->getShip() == "CRUISER"){
                    cout << "C";
                }else if(board[i][j]->getShip() == "DESTROYER"){
                    cout << "D";
                }else{
                    cout << "-";
                }
            }
            cout << endl;
        }
        cout << endl << endl;

        // print the board before guesses are taken
        for(int i = 0; i < xBoardsize; i++){
            cout << "                   ";
            for(int j = 0; j < yBoardsize; j++){
                if(board[i][j]->getShip() == "BATTLESHIP" and board[i][j]->getHit() == 0){
                    cout << "B";
                }else if(board[i][j]->getShip() == "SUBMARINE" and board[i][j]->getHit() == 0){
                    cout << "S";
                }else if(board[i][j]->getShip() == "CRUISER" and board[i][j]->getHit() == 0){
                    cout << "C";
                }else if(board[i][j]->getShip() == "DESTROYER" and board[i][j]->getHit() == 0){
                    cout << "D";
                }else if(board[i][j]->getHit() == 1){
                    cout << "X";
                }else{
                    cout << "-";
                }
            }
            cout << endl;
        }
*/

        arr[games].numGuess = guessTaken;       // set the number of guesses
        arr[games].xSize = xBoardsize;          // set the number of rows
        arr[games].ySize = yBoardsize;          // set the number of columns
        arr[games].opCount = opCounter;         // set the number of operations
        opCounter += 4;

        // delete board
        for(int i = 0; i < xBoardsize; i ++){
            for(int j = 0; j < yBoardsize; j++){
                delete board[i][j];
                opCounter++;
            }
        }
        games++;        // games played
        opCounter = 0;  // reset op count
    }

    quickSort(arr, 0, 100);
    for(int i = 0; i < 101; i++){// print all struct nodes to file
/* visual print
        output << "GUESS :: " << arr[i].numGuess << endl;
        output << "xSize :: " << arr[i].xSize << endl;
        output << "ySize :: " << arr[i].ySize << endl;
        output << "ops   :: " << arr[i].opCount << endl;
        output << endl;
*/
        // print values to seperate files
        boardSize << arr[i].xSize * arr[i].ySize << endl;
        opNum << arr[i].opCount << endl;
        guessNum << arr[i].numGuess <<endl;
    }
    // close streams
    opNum.close();
    boardSize.close();
    guessNum.close();
    output.close();
    return 0;
}
