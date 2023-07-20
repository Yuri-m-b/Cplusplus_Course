#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
using namespace std;

// ---------- ABSTRACT CLASS / OVERRIDE EXAMPLE ----------
 
// Shape here has no purpose except for
// being able to to group similar objects
// so it should be instead an Abstract
// Class
 
class Shape{
public:
    virtual double Area() = 0;
};
 
class Circle : public Shape{
protected:
    double width;
public:
    Circle(double w){
        width = w;
    }
    
    // Override Area()
    // You should use override to force the
    // compiler to check if the base class
    // virtual fucntion is the same as
    // the subclass
    double Area() override{
        return 3.14159 * pow((width / 2), 2);
    }
};
 
class Rectangle : public Shape{
protected:
    double height, width;
public:
    Rectangle(double h, double w){
        height = h;
        width = w;
    }
    // Override Area()
    // Marking a method as final means
    // that subclasses that inherit from
    // Rectangle can't override Area()
    double Area() override final{
        return height * width;
    }
};
 
class Square : public Rectangle{
public:
    Square(double h, double w) :
    Rectangle(h,w){
        
    }
    
    /* This would trigger an error
    double Area() override{
        return height * 2;
    }
    */
};
 
// This function receives Shapes but uses the 
// correct Area() automatically
void ShowArea(Shape& shape){
    cout << "Area : " << shape.Area() << endl;
}
 
int main()
{
    Rectangle rectangle(10,5);
    Circle circle(10);
    ShowArea(rectangle);
    ShowArea(circle);
    
    Square square(10,10);
    ShowArea(square);
    
    return 0;
}
