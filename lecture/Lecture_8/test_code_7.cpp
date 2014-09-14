#include <iostream>

using namespace std;

void push(int arr[], int x, int *top){
    arr[*top] = x;
    (*top)++;
}
int pop(int arr[], int *top){
    (*top)--;
    return arr[(*top)++];
}

int main(){
    int *top = new int;
    *top = 0;
    int arr[10];
    int val;

    push(arr, 1, top);
    push(arr, 10, top);
    push(arr, 20, top);
    val = pop(arr, top);
    val = pop(arr, top);

    cout <<"top = " << *top << endl;
}
