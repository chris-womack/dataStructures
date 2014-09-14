#include <cstdlib>
#include <iostream>

using namespace std;

/*Declaring functions. We have a function declaration
here for insertionSort and printArray, and then we can
have the implementations of these functions after main.
The code wouldn't compile without the declarations. It's
personal preference whether implementations defined before
main or functions declared before main and implementations
done after main.
*/

void insertionSort(int arr[], int length);
void printArray(int array[],int size);

int main() {

    //worse case array, completely unsorted
    int array[5]= {5,4,3,2,1};
    //print the array to see it's contents
    printArray(array, 5);
    //do the insertion sort.
    /*printArray is also called inside
    insertionSort, so you can see it working.
    */
    insertionSort(array,5);

 return 0;
}//end of main

void insertionSort(int arr[], int length) {
    int i;
    int key;
    for (int j = 1; j < length; j++) {
        key = arr[j];
        i = j-1;
        while (i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i--;
        }//end of while loop
        arr[i+1] = key;

        printArray(arr,5);
    }//end of for loop
 }//end of insertionSort.

void printArray(int array[], int size){

 cout<< "sorting: ";
 int j;
 for (j=0; j<size;j++)
    for (j=0; j<size;j++)
        cout <<" "<< array[j];
    cout << endl;
}//end of printArray
