#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <ctime>
#include <queue> 
#include <stack> 
using namespace std;

int main(){
    // ----- CONTAINER ADAPTERS -----
    // Adapt containers to provide a defined interface
    
    // ----- STACK -----
    // Provides an interface for storing elements in a LIFO
    // format
    stack<string> custs;
    custs.push("George");
    custs.push("Louise");
    custs.push("Florence");
    
    // Get number of elements
    int size = custs.size();
    
    // Check if empty
    if(!custs.empty()){
        for(int i = 0; i < size; i++){
            
            // Get value with top
            cout << custs.top() << endl;
            
            // Delete last value entered
            custs.pop();
        }
    }
        
    // ----- END OF STACK -----
    
    // ----- QUEUE -----
    // Provides an interface for storing elements in a FIFO
    // format
    queue<string> cast;
    cast.push("Zoidberg");
    cast.push("Bender");
    cast.push("Leela");
    int size2 = cast.size();
    
    if(!cast.empty()){
        for(int i = 0; i < size2; i++){
            
            // Get value with top
            cout << cast.front() << endl;
            
            // Delete last value entered
            cast.pop();
        }
    }
    
    // ----- END OF QUEUE -----
    
    // ----- PRIORITY QUEUE -----
    // Elements are organized with the largest first
    priority_queue<int> nums;
    nums.push(4);
    nums.push(8);
    nums.push(5);
    int size3 = nums.size();
    
    if(!nums.empty()){
        for(int i = 0; i < size3; i++){
            
            // Get value with top
            cout << nums.top() << endl;
            
            // Delete last value entered
            nums.pop();
        }
    }
    
    // ----- END OF PRIORITY QUEUE -----
    
    // ----- ENUMS -----
    // Custom data type that assigns names to 
    // constant integers so that a program is
    // easier to read
    
    // You can define the starting index, or any others
    enum day{Mon=1, Tues, Wed, Thur, Fri=5};
    
    enum day tuesday = Tues;
    
    cout << "Tuesday is the " << tuesday <<
            "nd day of the week\n";
    
    // Cycle through days
    for(int i = Mon; i <= Fri; i++)
        cout << i << endl;
    
    // ----- END OF ENUMS -----
    
    return 0;
}
