#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
using namespace std;
 
// Needed for ostringstream
#include <sstream>
 
// Create a custom Box class with overloaded operators
class Box{
public:
    double length, width, breadth;
    
    // Used to hold a string representation of a box
    string boxString;
    
    Box(){
        length = 1, width = 1, breadth = 1;
    }
    Box(double l, double w, double b){
        length = l, width = w, breadth = b;
    }
    
    // You can define customer operators just like
    // you define functions
    // This is a unary operator because it operates
    // on 1 object
    // Other Unary Operators : --, *(pointer dereference),
    // -> (Member Selection), !, & (Address of), +, -
    Box& operator ++ (){
        length++;
        width++;
        breadth++;
        return *this;
    }
    
    // Creates a C string representation which is a
    // pointer to an array that is null terminated
    operator const char*() {
        // Creates a stream that can be loaded with 
        // characters that can then be accessed as
        // a string object
        ostringstream boxStream;
        boxStream << "Box : " <<
                length << ", " <<
                width << ", " <<
                breadth;
        
        // Return a string representation of the stream
        boxString = boxStream.str();
        
        // Returns the pointer to the string array
        return boxString.c_str();
    }
    
    // Binary operators operate on 2 objects
    // +, -, *, /, %, ==, !=, >, <, >=, <=, &&, ||, 
    // !, =, +=, -=, *=, /=, ^, [], &, |
    
    // Let's add boxes
    Box operator + (const Box& box2){
        Box boxSum;
        boxSum.length = length + box2.length;
        boxSum.width = width + box2.width;
        boxSum.breadth = breadth + box2.breadth;
        return boxSum;
    }
    
    // Access items using a subscript operator
    double operator [] (int x){
        if(x == 0){
            return length;
        } else if(x == 1){
            return width;
        } else if(x == 2){
            return breadth;
        } else {
            return 0;
        }
    }
    
    // Check for box equality
    bool operator == (const Box& box2){
        return ((length == box2.length) &&
                (width == box2.width) &&
                (breadth == box2.breadth));
    }
    
    // Check for which is bigger
    bool operator < (const Box& box2){
        double thisSize = length + width + breadth;
        double box2Size = box2.length + box2.width +
        box2.breadth;
        if (thisSize < box2Size){
            return true;
        } else {
            return false;
        }
    }
    
    bool operator > (const Box& box2){
        double thisSize = length + width + breadth;
        double box2Size = box2.length + box2.width +
        box2.breadth;
        if (thisSize > box2Size){
            return true;
        } else {
            return false;
        }
    }
    
    // Overload the assignment operator
    void operator = (const Box& boxToCopy){
        length = boxToCopy.length;
        width = boxToCopy.width;
        breadth = boxToCopy.breadth;
    }
};
 
int main()
{
    Box box(10,10,10);
    
    // Will increment all values in the box by 1
    ++box;
    cout << box << endl;
    
    // Add boxes
    Box box2(5,5,5);
    cout << "Box1 + Box2 = " <<
            box + box2 << endl;
    
    // Access data with subscript operator
    cout << "Box Length : " <<
            box[0] << endl;
    
    // Displays true or false for bolleans
    cout << boolalpha;
    cout << "Are boxes equal : " <<
            (box == box2) << endl;
    
    // Is box < box2
    cout << "Is box < box2 : " <<
            (box < box2) << endl;
    
    // Is box > box2
    cout << "Is box < box2 : " <<
            (box > box2) << endl;
    
    box = box2;
    cout << box << endl;
    return 0;
}
