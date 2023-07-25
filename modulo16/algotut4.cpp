#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
using namespace std;

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

        // Handles creating array without and
        // with a passed array of values
        Array();
        Array(int *arr, int size);
        string linearSearch(int value);

        void horzDisplay(int i, int j);
        void swapValues(int i1, int i2);
        void bubbleSort();
        void binarySearch(int value);

        void selectionSort();
        void insertionSort();
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

Array::Array(){}
Array::Array(int arr[], int size){
    arraySize = size;
    for (int i = 0; i < arraySize; i++){
        theArray[i] = arr[i];
    }
}

// Linear Search : We look at every value in the array
// because we want to find duplicate matches
// This returns a string with all index matches
string Array::linearSearch(int value){
    string matches;
    bool valueFound = false;
    for(int i = 0; i < arraySize; i++){
        if(theArray[i] == value){
            matches += " " + to_string(i);
        }
    }
    // Delete the 1st space
    matches.erase(0,1);
    return matches;
}

void Array::horzDisplay(int i, int j){
    int horzDashes = (arraySize * 6) + 1;
    for(int n = 0; n < horzDashes; n++) cout << "-";
    cout << endl;
    for(int n = 0; n < arraySize; n++) cout << "|  " << n << "  ";
    cout << "|" << endl;
    for(int n = 0; n < horzDashes; n++) cout << "-";
    cout << endl;
    for(int n = 0; n < arraySize; n++) cout << "| " << theArray[n] << "  ";
    cout << "|" << endl;
    for(int n = 0; n < horzDashes; n++) cout << "-";
    cout << endl;

    if(j != -1){
        for(int k = 0; k < ((j*6)+1); k++) cout << " ";
        cout << j;
    }

    if(i != -1){
        for(int l = 0; l < (6*(i - j)-1); l++) cout << " ";
        cout << i;
    }
    cout << endl;
}

void Array::swapValues(int i1, int i2){
    int temp = theArray[i1];
    theArray[i1] = theArray[i2];
    theArray[i2] = temp;
}

// Sorts everything from smallest to largest
// by moving the largest values right
void Array::bubbleSort(){
    // i starts at the end of the array
    // As it is decremented all indexes
    // greater then it are sorted
    for(int i = arraySize - 1; i > 1; i--){
        // The inner loop starts at the beginning
        // of the array and compares each value
        // next to each other. If the value is 
        // greater then they are swapped
        for(int j = 0; j < i; j++){
            // You can change sorting to descending
            // by using <
            if(theArray[j] > theArray[j+1]){
                swapValues(j, j+1);
                horzDisplay(i, j);
            }
        }
    }
}

// Binary search is faster than linear because the 
// array is sorted. If you find a value larger
// than the value you are searching for the
// search ends.
void Array::binarySearch(int value){
    int lowIndex = 0;
    // We start searching in the middle
    int highIndex = arraySize - 1;

    while(lowIndex <= highIndex){
        int midIndex = (highIndex + lowIndex) / 2;

        if(theArray[midIndex] < value){
            lowIndex = midIndex + 1;
        } else if(theArray[midIndex] > value){
            highIndex = midIndex + 1;
        } else {
            cout << "Match at Index : " << midIndex << endl;
            lowIndex = highIndex + 1;
        }
    }
}

// ----- NEW -----

// The Selection sort searches for the smallest number 
// in the array and saves it in the minimum
// spot. It continues searching through the entire
// array each time.
void Array::selectionSort(){
    for(int i = 0; i < arraySize; i++){
        int min = i;
        for(int j=i; j < arraySize; j++){
            if(theArray[min] > theArray[j]){
                min = j;
            }
        }
        swapValues(i, min);
        horzDisplay(i, -1);
    }
}

// The Insertion Sort is normally the best of the 
// elementary sorting algorithms. 
// The array is split into a sorted and 
// unsorted parts.

// 1. Iterate through the whole array
// 2. Compare value to all values before it
// 3. Move all values greater forward to make space
// 4. Insert the smallest value in the space created
void Array::insertionSort(){
    for(int i = 1; i < arraySize; i++){
        int j = i;
        int toInsert = theArray[i];
        while((j > 0) && (theArray[j-1] > toInsert)){
            theArray[j] = theArray[j-1];
            j--;
            horzDisplay(i, j);
        }
        theArray[j] = toInsert;
        horzDisplay(i,j);
        printf("Array[i] = %d Array[j] = %d toInsert = %d\n", theArray[i], theArray[j], toInsert);
    }
} 

int main(){
    srand(time(NULL));
    cout << boolalpha;

    // Create array object with random values
    Array myArr;
    myArr.genRandArray();

    // Run Selection Sort and Display the Sorted array
    // myArr.selectionSort();

    // Run Insertion Sort
    myArr.horzDisplay(-1, -1);
    myArr.insertionSort();
    myArr.display();

    

    return 0;
}