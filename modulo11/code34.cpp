#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <deque>
#include <iterator>
using namespace std;

// ----- PREPROCESSOR DIRECTIVES -----
 
// Anything that starts with a # is a preprocessor
// directive and they run before the program compiles
 
// Right click Header Files -> New -> C++ Header File
// and then include it here
#include "Animal.h"
 
// This is a macro constant that will replace 
// PI with 3.14159 in the code before execution
#define PI 3.14159
 
// This is a macro function that will do the same with
// a function
#define AREA_CIRCLE(radius) (PI * (pow(radius, 2)))

int main()
{
    Animal spot = Animal();
    spot.name = "Spot";
    cout << "The Animal is named " << 
            spot.name << endl;
    
    cout << "Circle Area : " <<
            AREA_CIRCLE(5) << endl;

    return 0;
}

// COMPILE WITH g++ tut33.cpp Animal.cpp
// Execute ./a.out
