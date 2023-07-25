#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
using namespace std;

// Algorithm : Series of steps taken to perform
// a calculation or solve a problem

// Data Structure : Defines how data is arranged
// in memory and how you can interact with it

// Data structures allow for input, deleting
// and searching

// In C++ arrays can be declared dynamically or
// statically

class Array{
    private:
        int theArray[50];
        int arraySize = 10;
    public:
        void genRandArray();
        void display();
        int at(int index);
        bool inArray(int val);
        void deleteIndex(int index);
        void append(int val);
};

// Puts random values between 10 and 50 in the array
void Array::genRandArray(){
    for(int i = 0; i < arraySize; i++){
        theArray[i] = (rand() % 50) + 10;
    }
}

// Will print the array index and value in boxes
void Array::display(){
    cout << "----------" << endl;
    for(int i = 0; i < arraySize; i++){
        cout << "| " << i << " | ";
        cout << theArray[i] << " |" << endl;
        cout << "----------" << endl;
    }
}

int Array::at(int index){
    if(index < arraySize) return theArray[index];

    // Otherwise print an error message and return 0
    cout << "That index doesn't exist" << endl;
    return -1;
}

// Return true or false if value is in array
bool Array::inArray(int val){
    bool inArr = false;
    for(int i = 0; i < arraySize; i++){
        if(val == theArray[i]) inArr = true;
    }
    return inArr;
}

void Array::deleteIndex(int index){
    if((index < arraySize) && (index >= 0)){
        // Go to the index value and delete it by assigning
        // the value to it that follows it
        // continue doing this til the array end
        for(int i = index; i < (arraySize - 1); i++){
            theArray[i] = theArray[i+1];
        }
        // Since we have 1 less array item decrement arraySize
        arraySize--;
    }
}

void Array::append(int val){
    // Check if we have more room in array
    if(arraySize < 50){
        // Add to index = to arraySize because of 0 index
        theArray[arraySize] = val;
        arraySize++;
    } else {
        cout << "Error : No more room in array" << endl;
    }
}

int main(){
    // Static arrays have a fixed size
    int arr[10]; // Not initialized
    int arr2[5] = {1,2,3,4,5}; // Initialized

    // You can alter a Dynamic arrays size at
    // runtime
    int* aPtr = new int[5];
    for(int i=0; i < 5; i++){
        aPtr[i] = i;
    }

    // Deallocate memory allocated for array
    delete [] aPtr;
    aPtr = new int[10];
    for(int i=0; i < 6; i++){
        aPtr[i] = i;
    }
    for(int i=0; i < 6; i++){
        cout << aPtr[i] << endl;
    }
    delete [] aPtr;

    // This static multidimensional array has
    // 3 rows and 4 columns
    int mArr[3][4];

    // Initializing a multidimensional array
    // If you don't assign a value it gets 0
    int mArr2[3][2] = {
        {1,2},
        {3,4},
        {5,6} 
    };
    cout << mArr2[0][1] << endl;

    // Accessing mult arrays
    for (int j = 0; j < 3; j++){
        for (int k = 0; k < 2; k++){
            cout << mArr2[j][k];
        }
    }

    // 3D Mult array
    string mArr3[2][3][2] = {
        {
            // 0 Rows
            {"000", "001"},
            {"010", "011"},
            {"020", "021"}
        },
        {
            // 1 Rows
            {"100", "101"},
            {"110", "111"},
            {"120", "121"}
        }
    };

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 2; k++){
                printf("%d %d %d = %s\n", i, j, k, mArr3[i][j][k].c_str());
            }
        }
    }

    // ----- ARRAY CLASS -----

    // Seed in main once to get random values for objects
    srand(time(NULL));
    // Set cout to print true and false
    cout << boolalpha;

    // Create array objects with random values and display
    Array myArr;
    myArr.genRandArray();
    myArr.display();
    Array myArr2;
    myArr2.genRandArray();
    myArr2.display();

    // Get value at index 3
    cout << myArr.at(3) << endl;

    // Add value at end of array
    myArr.append(99);
    myArr.display();

    // Check if value is in array
    cout << "99 In Array : " << myArr.inArray(99) << endl;

    // Delete index 2
    myArr.deleteIndex(2);
    myArr.display();

    return 0;
}