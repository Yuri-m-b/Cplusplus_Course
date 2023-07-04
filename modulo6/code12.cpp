#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm> 
using namespace std;

// Function Prototypes

// This function receives pointers
void AssignAge3(int* pAge);
 
// Double values in array passed
void DoubleArray(int *arr, int size);

int main(){

    int age = 43;

    // A Pointer stores a address in memory
    // You declare a pointer to be of the same type as the 
    // data type to which it points
    // If you are storing the address of an int then the 
    // pointer is an int
    // When you declare a pointer give it a null value
    int* pAge = NULL;
    
    // The reference operator returns the address for a 
    // variable that can be stored in a pointer
    pAge = &age;
    
    // Print the address Hexidecimal Number
    cout << "Address : " << pAge << endl;
    
    // Get the value at that address with the dereference operator
    cout << "Value at Address : " << *pAge << endl;
    
    // We can create a pointer to an array and cycle through
    // the data with ++ and --
    int intArray[] = {1,2,3,4};
    int* pIntArray = intArray;
    
    cout << "1st " << *pIntArray << " Address " << pIntArray << endl;
    pIntArray++;
    cout << "2nd " << *pIntArray << " Address " << pIntArray << endl;
    pIntArray--;
    cout << "1st " << *pIntArray << " Address " << pIntArray << endl;
    
    // You can pass a pointer to a function and then the 
    // function can change that variables value globally
    // Send the address for age to the function
    AssignAge3(&age);
    
    cout << "Pointer Age " << age << endl;
    
    // Create an array and double values
    int arr[] = {1,2,3,4};
    DoubleArray(arr, 4);
    for(int i = 0; i < 4; ++i){
        cout << "Array " << arr[i] << endl;
    }

    return 0;
}

// Function that receives a pointer
void AssignAge3(int* pAge){
    
    // Use dereference operator to change the value at the address
    *pAge = 22;
    
}
 
// Double values in array
void DoubleArray(int *arr, int size){
    for(int i = 0; i < size; ++i){
        arr[i] = arr[i] * 2;
    }
}
