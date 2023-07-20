#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <iterator>
#include <memory>
#include <stdio.h>
using namespace std;
 
// A Smart pointer is a class that provides the 
// power of pointers, but also handles the reallocation
// of memory when it is no longer required (The pointer
// is automatically destroyed)
 
// typedef creates an alias for a more complex type name
typedef vector<int32_t> intVec;
 
int main()
{
    /* MALLOC EXAMPLE
    // When you define a primitive type like int or
    // float you define exactly the amount of space
    // to set aside
    
    // If you need to define how much space to set aside
    // you could call malloc() and tell it how much
    // space to set aside and it returns the address to
    // that memory address
    
    int amtToStore;
    cout << "How many numbers do you want to store : ";
    cin >> amtToStore;
    
    // Create an int pointer and set aside enough space
    int * pNums;
    
    // Cast the pointer and define how much space to set aside
    pNums = (int *) malloc(amtToStore * sizeof(int));
    
    // Check if memory was allocated
    if(pNums != NULL){
        int i = 0;
        
        // Store values
        while(i < amtToStore){
            cout << "Enter a Number : ";
            cin >> pNums[i];
            i++;
        }
    }
    
    cout << "You entered these numbers\n";
    for(int i = 0; i < amtToStore; i++){
        cout << pNums[i] << endl;
    }
    
    // Delete the pointer
    delete pNums;
    */
    
    // Smart Pointer Solution
    int amtToStore;
    cout << "How many numbers do you want to store : ";
    cin >> amtToStore;
    
    // This memory will be automatically reallocated
    unique_ptr<int[]> pNums(new int[amtToStore]);
    
    // unique_ptr can only have one owner
    // so this throws an error
    // unique_ptr<int[]> pNums2 = pNums;
    // I'll cover how to do this with shared_ptr
    // in a later tutorial
    
    if(pNums != NULL){
        int i = 0;
        
        // Store values
        while(i < amtToStore){
            cout << "Enter a Number : ";
            cin >> pNums[i];
            i++;
        }
    }
    
    cout << "You entered these numbers\n";
    for(int i = 0; i < amtToStore; i++){
        cout << pNums[i] << endl;
    }
    
    return 0;
}
