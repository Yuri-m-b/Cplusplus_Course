#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cmath>
using namespace std;
 
vector<int> GenerateRandVec(int numOfNums,
        int min, int max);
 
void BubbleSort(vector<int>& theVec);
 
int main() {

    // ----- BUBBLE SORT -----

    // Generate a random vector of 10 values between 1 and 50
    vector<int> vecVals = GenerateRandVec(10, 1, 50);
    
    BubbleSort(vecVals);
    
    // Output the sorted vector
    for(auto x: vecVals)
        cout << x << endl;

    // ----- END OF BUBBLE SORT -----

    return 0;
}

vector<int> GenerateRandVec(int numOfNums,
        int min, int max){
    vector<int> vecValues;
    
    // Seed the random number generator
    srand(time(NULL));
    
    int i = 0, randVal = 0;
    
    while(i < numOfNums){
        // The min added on increases result based on min
        // The remainder of modulus can't be greater
        // then the divisor. We have to adjust down
        // based on the addition from min
        randVal = min + rand() % ((max + 1) - min);
        vecValues.push_back(randVal);
        i++;
    }
    return vecValues;
}

void BubbleSort(vector<int>& theVec){
    
// ----- SORT A LIST : BUBBLE SORT -----
// The Bubble sort is a way to sort a list
// It works this way
// 1. An outer loop decreases in size each time
// 2. The goal is to have the largest number at 
// the end of the list when the outer loop 
// completes 1 cycle
// 3. The inner loop starts comparing indexes 
// at the beginning of the loop
// 4. Check if list[Index] > list[Index + 1]
// 5. If so swap the index values
// 6. When the inner loop completes the largest number is at
// the end of the list
// 7. Decrement the outer loop by 1
 
// Create the value that will decrement for the outer loop
// Its value is the last index in the list
    int i = theVec.size() - 1;
    
    while(i >= 1){
        int j = 0;
        
        while(j < i){
            printf("\nIs %d > %d\n", theVec[j], theVec[j + 1]);
            
            if(theVec[j] >= theVec[j+1]){
                cout << "Switch\n";
                
                int temp = theVec[j];
                theVec[j] = theVec[j+1];
                theVec[j+1] = temp;
            } else {
                cout << "Don't Switch\n";
            }
            j += 1;
            
            for(auto k: theVec){
                cout << k << ", ";
            }
        }
        cout << "\nEnd of Round\n";
        i -= 1;
    }
}

