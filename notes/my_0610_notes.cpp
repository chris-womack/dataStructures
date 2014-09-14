#include <iostream>

using namespace std;

void insertionsort(int arr[], int length){
	int i;
	int key;
	for(int j = 1; j < length; j++){
		key = arr[j];
		i = j - 1;
		while(i >= 0 && arr[i] > key){
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = key;
		for(int j = 0; j < length; j++)
			cout << arr[j] << " ";
		cout << endl;
	}
}

int main()
{
	int array[5] = {5, 4, 3, 2, 1};
	insertionsort(array,5);
	return 0;
}
