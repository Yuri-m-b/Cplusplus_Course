#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
using namespace std;
 
// Classes have default private fields and methods
// while structs have public
// Structs are used to model new data types, while
// classes model more complex real world objects
struct Shape{
    // Variables are public by default
    double length, width;
    
    // Constructors are public by default
    Shape(double l = 1, double w = 1){
        length = l;
        width = w;
    }
    
    // Structs can contain functions
    double Area(){
        return length * width;
    }
    
    // Structs can contain private members
private:
    int id;
};
 
// You can inherit from a struct
struct Circle : Shape{
    // Override the constructor
    // You also use this with structs
    Circle(double width){
        this->width = width;
    }
    
    // Override Area()
    double Area(){
        return 3.14159 * pow((width / 2), 2);
    }
};
 
int main()
{
    // Create a struct
    Shape shape(10, 10);
    
    // Call a Struct function
    cout << "Square Area : " << shape.Area() 
            << endl;
    
    // Create a struct
    Circle circle(10);
    
    // Call a Struct function
    cout << "Circle Area : " << circle.Area() 
            << endl;
    
    // You can initialize a struct or class using
    // an aggregate
    Shape rectangle{10,15};
    cout << "Rectangle Area : " << 
            rectangle.Area() << endl;
    
    return 0;
}
