#include <iostream>

using namespace std;

void myFunction(int counter){

    if(counter == 0){
        return;
    }else{
        // cout << counter << endl;        // prints before enter call
        myFunction(--counter);
        //cout << counter << endl;     // prints upon returning from the call
        return;
    }
}

int Fibonacci(int x){
    if(x == 0) return 0;
    if(x == 1) return 1;
    return Fibonacci(x - 1) + Fibonacci(x - 2);
}

int factorial(int n){
    if(n <= 1){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}

int main(){
    int i;
    int num;
    i = 5;
    myFunction(i);

    cout << "What element of Fibonacci do you want to know"
    cin >> num;

    cout < "The Fibonacci number is " << Fibonacci(num) << endl;

    cout << "Input factorial";
    cin >> num;

    cout << factorial(num) << endl;
    return 0;
}
