#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal{
    
    // Private variables are only available to methods 
    // in the class
private:
    string name;
    double height;
    double weight;
    
    // Static variables share the same value for all
    // objects of the Animal class
    static int numOfAnimals;
 
    // Public fields and methods can be accessed by
    // anything with access to the object
public:
    string GetName(){return name;}
    
    // Because we don't know what an objects name is
    // because the class is created before the object
    // we can refer to all objects using this
    // The pointer operator is used to access an 
    // objects fields and methods
    void SetName(string name){this->name = name;}
    double GetHeight(){return height;}
    void SetHeight(double height){this->height = height;}
    double GetWeight(){return weight;}
    void SetWeight(double weight){this->weight = weight;}
    
    // You can declare function prototypes
    void SetAll(string, double, double);
    
    // A constructor is called each time an object is created
    Animal(string, double, double);
    
    // Create an overloaded constructor for when no data is passed
    Animal();
    
    // A deconstructor is called automatically when an object
    // is deleted or is no longer used
    // The default is fine, but you should create custom ones
    // when you must release memory, or resources
    ~Animal();
    
    // Static methods can only access static fields
    static int GetNumOfAnimals(){return numOfAnimals;}
    
    // Created to be overwritten
    void ToString();
    
};
 
// Refer to class fields and methods with ::
int Animal::numOfAnimals = 0;
 
// Define the prototype method
void Animal::SetAll(string name, double height,
        double weight){
    this->name = name;
    this->weight = weight;
    this->height = height;
    Animal::numOfAnimals++;
}
 
// Define the constructor
Animal::Animal(string name, double height,
        double weight){
    this->name = name;
    this->weight = weight;
    this->height = height;
    Animal::numOfAnimals++;
}
 
Animal::Animal(){
    this->name = "";
    this->weight = 0;
    this->height = 0;
    Animal::numOfAnimals++;
}
 
Animal::~Animal(){
    cout << "Animal " << this -> name << 
            " destroyed\n";
}
 
void Animal::ToString(){
    cout << this -> name << " is " << 
            this -> height <<
            " cms tall and " << this -> weight <<
            " kgs in weight\n";
}
 
int main()
{
    // Create object without setting values in constructor
    Animal fred;
    fred.SetHeight(33);
    fred.SetWeight(10);
    fred.SetName("Fred");
    // Get the values for the Animal
    fred.ToString();
    
    fred.SetAll("Fred", 34, 12);
    
    fred.ToString();
    
    // Setting values with constructor
    Animal tom("Tom", 36, 15);
    tom.ToString();
    
    // Call static methods by using the class name to
    // show the total Animals created
    cout << "Number of Animals " << 
            Animal::GetNumOfAnimals() << endl;
    
    return 0;
}
