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
using namespace std;
 
// Here I demonstrate how to use templates 
// polymorphically 
 
// Base class all pizzas inherit along with MakePizza
// which will be overridden
class Pizza
{
public:
    virtual void MakePizza() = 0;
};
 
// The last templates that will be called
class NYStyleCrust 
{
public:
  string AddIngredient() 
  {
    return "Crust so Thin You can See through it\n\n";
  }
};
 
class DeepDishCrust 
{
public:
  string AddIngredient() 
  {
    return "Super Awesome Chicago Deep Dish Crust\n\n";
  }
};
 
// End of last templates called
 
// The middle templates called
template <typename T>
class LotsOfMeat: public T 
{
public:
  string AddIngredient() 
  {
    return "Lots of Random Meat, " + T::AddIngredient();
  }
};
 
template <typename T>
class Vegan: public T 
{
public:
  string AddIngredient() 
  {
    return "Vegan Cheese, Veggies, " + T::AddIngredient();
  }
};
 
// End of middle templates called
 
// We inherit from Pizza as well as the initial next template
template <typename T>
class MeatNYStyle: public T, public Pizza 
{
public:
  void MakePizza() { cout << "Meat NY Style Pizza : " << 
          T::AddIngredient(); }
};
 
template <typename T>
class VeganDeepDish: public T, public Pizza 
{
public:
  void MakePizza() { cout << "Vegan Deep Dish : " << 
          T::AddIngredient(); }
};
 
int main()
{
    // unique_ptr is a smart pointer that disposes of
    // a pointer when it is no longer in use
    vector<unique_ptr<Pizza>> pizzaOrders;
    
    // Generate Pizza types and place them at the end of the vector
    pizzaOrders.emplace_back(new MeatNYStyle<LotsOfMeat<NYStyleCrust>>());
    pizzaOrders.emplace_back(new VeganDeepDish<Vegan<DeepDishCrust>>());
    
    // Call the pizzas and execute the directions 
    // for making them
    for(auto &pizza: pizzaOrders)
    {
        pizza->MakePizza();
    }
    
    return 0;
}
