#include "Node.h"
#include "myStruct.h"
#include "functions.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

// Reset the random number generator with the system clock.
void seed(){
    srand(time(NULL));
}

// concatenates x and y values for hash table
unsigned int concatenate(unsigned int x, unsigned int y, unsigned int hashSize) {
    unsigned int pow = 10;  // start at power of 10 for single digits
    while(y >= pow){// increase power for double and triple and so on...
        pow *= 10;
    }
    if(x > 9 and y < 10){// if x = 1 and y = 13 => 113 and if x = 11 and y = 3 => 113, now x = 11 and y = 3 => 1103
        return x * pow*10 + y;
    }else if(x == 0 and y > 9){// if 0 and 13 guess would duplicate to 13 so subtract from end
        return hashSize - y;
    }else{// concat values: 20 X 20 becomes 2000 + 20 = 2020
        return x * pow + y;
    }
}

// check if ship has been destroyed
int deathCheck(Node* root, int* opCounter){

    // base case
    if(root->getNext() == NULL and root->getHit() == 1){// if at end node and hit
        return 1;
    }else if(root->getNext() == NULL and root->getHit() == 0){// if at end node and no hit
        return 0;
    }

    //
    if(root->getNext() != NULL and root->getHit() == 1){// if hit and can still proceed
        (*opCounter)++;
        return (deathCheck(root->getNext(), opCounter) + 1);    // move to next
    }else if(root->getNext() != NULL and root->getHit() == 0){  // if no hit and can still proceed
        (*opCounter)++;
        return (deathCheck(root->getNext(), opCounter) + 0);    // move to next
    }
}

// sorts values of array from least to greatest
void quickSort(arrayStruct arr[], int head, int tail){
    int i = head;   // start at begining
    int j = tail;   // start at end
    arrayStruct tmp;    // storage
    int pivot = arr[(head + tail) / 2].numGuess; // chose a pivot from arr or arr subset


    while (i <= j) {// end if i crosses j
        while(arr[i].numGuess < pivot){// find firse element that is greater than pivot
            i++;
        }
        while(arr[j].numGuess > pivot){// find element from end that is less than pivot
            j--;
        }

        // swap values
        if (i <= j) {// i and j have not crossed
            tmp = arr[i];       // store i
            arr[i] = arr[j];    // set arr i to arr j
            arr[j] = tmp;       // set j to stored val
            i++;
            j--;
        }
    }

    // sort all subsets of arr
    if (head < j){
        quickSort(arr, head, j);
    }
    if (i < tail){
        quickSort(arr, i, tail);
    }
}
