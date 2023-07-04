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

// ----- FUNCTION PROTOTYPES -----
// You define the return type and data types for functions
// using a function prototype so main knows what is to be 
// expected from this function

double AddNumbers(double num1, double num2);
 
void AssignAge(int age);
 
int AssignAge2(int age);

int main(){

    // ----- FUNCTIONS -----
    // Code that gets above 8 to 10 lines should be broken off
    // into a separate function to better organize your code
    // and to promote reuse
    
    // ----- FUNCTION 1 -----

    double num1, num2;
    
    cout << "Enter Num 1 : ";
    cin >> num1;
            
    cout << "Enter Num 2 : ";
    cin >> num2;
    
    // Call the function 
    printf("%.1f + %.1f = %.1f\n", num1, num2, AddNumbers(num1, num2));

    // ----- END OF FUNCTION 1 ----- 
    
    // ----- FUNCTION 2 -----

    // Variables in a function are local to that function
    
    // Variables values changed in a function don't 
    // translate globally
    int age = 43;
    AssignAge(age);
    cout << "New Age " << age << endl;

    // ----- END OF FUNCTION 2 -----
    
    // ----- FUNCTION 3 -----

    // You could change the value by passing it back
    age = AssignAge2(age);
    cout << "New Age " << age << endl;

    // ----- END OF FUNCTION 3 -----

    return 0;
}

// FUNCTIONS

// ----- FUNCTIONS -----
// A function starts with the data type it will return or void
// if no value is returned
// You also list the data types for the parameters passed into 
// a function and you may assign them default values
 
// FUNCTION 1
double AddNumbers(double num1 = 0, double num2 = 0){
    return num1 + num2;
}

// FUNCTION 2
void AssignAge(int age){
    age = 24;
}
 
// FUNCTION 3
int AssignAge2(int age){
    age = 24;
    return age;
}
