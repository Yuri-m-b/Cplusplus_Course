#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std; 

const int ARRSIZE = 5;

// With the Shell Sort you compare elements
// that are apart rather than adjacent. 

// Puts random values between 10 and 50 
// in the array
int* genRandArray(){
    // Initialize Random Seed
    srand (time(NULL));
    static int arr[ARRSIZE];
    for(int i = 0; i < ARRSIZE; i++){
        arr[i] = (rand() % 50) + 10;
    }
    return arr;
}

void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << "------";
    }
    cout << endl;
    for(int i = 0; i < size; i++){
        cout << "|  " << i << "  ";
    }
    cout << endl;
    for(int i = 0; i < size; i++){
        cout << "------";
    }
    cout << endl;
    for(int i = 0; i < size; i++){
        cout << "| " << arr[i] << "  ";
    }
    cout << endl;
    for(int i = 0; i < size; i++){
        cout << "------";
    }
    cout << endl;
}

void shellSort(int arr[], int size){
    // This defines the center and we use integer division
    // to reduce the size by 2 each time
    for(int i = size/2; i > 0; i /= 2){
        // We check if values to the right are in correct
        // position
        cout << "Gap : " << i << endl;
        for(int j = i; j < size; j += 1){
            // temp stores the value we will compare to
            // others 
            int temp = arr[j];
            int k;
            // We will work from right to left and switch
            // values if temp is less than the value we
            // compare it to 
            cout << "j: " << j << endl;
            for(k = j; k >= i && arr[k - i] > temp; k -= i){
                printf("Switch %d > %d\n", arr[k - i], temp); 
                arr[k] = arr[k - i];
            }
            arr[k] = temp;
            display(arr, size);
        }
    }
}

int main(){
    // Pointer to the randomly generated array
    // int *myArr = genRandArray();

    int myArr[] = {50,40,30,20,10};

    display(myArr, ARRSIZE);

    shellSort(myArr, ARRSIZE);

    display(myArr, ARRSIZE);

    return 0;
}