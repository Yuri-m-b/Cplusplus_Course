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

// I love the range function in Python so I'll show how to 
// make it in C++
vector<int> Range(int start, int max, int step);

int main(){

    // Create a function that receives a starting value,
    // max value and an increment amount between
    // values and receive a vector in return
    
    vector<int> range = Range(1, 10, 2);
    
    // Cycle through the vector
    for(auto y: range){
        cout << y << endl;
    }

    // ----- EXCEPTION HANDLING EX 1 -----
    // Exceptions are errors that occur when things don't 
    // go as expected. 
    // 1. You expect and int and get a string
    // 2. You expect a file to be available and it isn't
    // 3. You expect the user to not enter 0 and they do
    
    // You try to execute code that could be troublesome
    // and if an error occurs you catch it and throw
    // it to another block of code for handling
    
    double num1 = 0, num2 = 0;
    
    cout << "Enter number 1 : ";
    cin >> num1;
    cout << "Enter number 2 : ";
    cin >> num2;
    
    try{
        if(num2 == 0){
            throw "Division by zero is not possible";
        } else {
        
            printf("%.1f / %.1f = %.2f\n", num1, num2, 
            (num1 / num2));
        }
    }
    
    catch(const char* exp){
        cout << "Error : " << exp << endl;
    }
    
    
// ----- END OF EXCEPTION HANDLING EX 1 -----
    
// ----- EXCEPTION HANDLING EX 2 -----
    try {
        cout << "Throwing exception\n";
        
        // Another way to throw an exception
        throw runtime_error("Error Occurred");
        
        // This point is never reached
        cout << "Can you print me?\n";
    }
    
    // All exceptions are based on exception
    catch(exception &exp){
        
        // what() Prints an explanatory string
        cout << "Handled Exception : " << 
                exp.what() << endl;
    }
    
    // If exceptions aren't caught any place else 
    // this will catch it
    catch(...){
        cout << "Default exception catch\n";
    }
 
    
// ----- END OF EXCEPTION HANDLING EX 2 -----

    return 0;
}

vector<int> Range(int start, int max, int step){
    
    // Every while statement needs an index to start with
    int i = start;
    
    // Will hold returning vector
    vector<int> range;
    
    // Make sure we don't go past max value
    while(i <= max){
        
        // Add value to the vector
        range.push_back(i);
        
        // Increment the required amount
        i += step;
    }
    
    return range;
    
}
