#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
using namespace std;
 
// Private members of a class are not accessable
// to outside code unless a class is marked as
// a friend
class Customer{
private:
    friend class GetCustomerData;
    string name; 
public:
    Customer(string name){
        this->name = name;
    }
};
 
class GetCustomerData{
public:
    static string GetName(Customer& customer){
        return customer.name;
    }
};
 
 
int main()
{
    Customer tom("Tom");
    GetCustomerData getName;
    cout << "Name : " << 
            getName.GetName(tom) << endl;
    
    return 0;
}
