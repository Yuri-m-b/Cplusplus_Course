#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cmath>
using namespace std;

int Factorial(int number);

void PrintHorzVector(vector<int>& theVec);

int Fib(int index);

int main(){

    int vecSize, n, i = 0;

    // PROBLEM PRINT VECTOR HORIZONTALLY

    /*
    ------------------
    |  0  |  1  |  2  |
    ------------------
    | 10  |  8  |  2  |
    ------------------
    */

    cout << "Define the size of your vector: ";
    cin >> vecSize;

    vector<int> theVec;

    while (i != vecSize)
    {
        cout << "Add a number to your vector: ";
        cin >> n;

        theVec.insert(theVec.end(),n);

        i += 1;
    }

    PrintHorzVector(theVec);

    // PROBLEM GENERATE FIBONACCI NUMBERS
    int index;
    cout << "Get Fibonacci Index : ";
    cin >> index;
    printf("fib(%d) = %d\n", index, Fib(index));

    return 0;
}

// 1. 3 * Factorial(2) (2) = 6
// 2. 2 * Factorial(1) (1)
// 3. 1 Return 1
int Factorial(int number){
    if(number == 1){
        return 1;
    } else {
        int result = number * Factorial(number - 1);
        return result;
    }
}    

// PROBLEM PRINT VECTOR HORIZONTALLY
void PrintHorzVector(vector<int>& theVec){
    int dashes = ceil(theVec.size() * 6);
    
    for(int n = 0; n < dashes; n++)
        cout << "-";
    cout << endl;
    
    for(int n = 0; n < theVec.size(); n++)
        printf("| %2d  ", n);
    cout << "|\n";
    
    for(int n = 0; n < dashes; n++)
        cout << "-";
    cout << endl;
    
    for(int n = 0; n < theVec.size(); n++)
        printf("| %2d  ", theVec[n]);
    cout << "|\n";
    
    for(int n = 0; n < dashes; n++)
        cout << "-";
    cout << endl;
 
}

// PROBLEM GENERATE FIBONACCI NUMBERS
int Fib(int index){
    if (index < 2){
        return index;
    } else {
        return Fib(index - 1) + Fib(index - 2);
    }
}

