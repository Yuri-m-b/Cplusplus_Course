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
 
#include <deque>
#include <list>
#include<forward_list>
using namespace std;
 
bool isEven(const int& val){
    return (val % 2) == 0;
}
 
int main()
{
    // ---------- FORWARD_LIST ----------
    // A forward list is like a list, but each list
    // item only has a link to the next item in the 
    // list and not to the item that proceeds it.
    
    // This make them the quickest of the sequence 
    // containers
    
    forward_list<int> fl1;
    
    // Assign values
    fl1.assign({1,2,3,4});
    
    // Push and pop front
    fl1.push_front(0);
    fl1.pop_front();
    
    // Get 1st
    cout << "Front : " << fl1.front();
    
    // Get iterator for 1st element
    forward_list<int>::iterator it4 = fl1.begin();
    
    // Insert after 1st element
    it4 = fl1.insert_after(it4, 5);
    
    // Delete just entered 5
    it4 = fl1.erase_after(fl1.begin());
    
    // Place in 1st position
    fl1.emplace_front(6);
    
    // Remove a value
    fl1.remove(6);
    
    // Remove if a condition is true
    fl1.remove_if (isEven);
    
    forward_list<int> fl2;
    fl2.assign({9,8,7,6,6});
    
    // Remove duplicates
    fl2.unique();
    
    // Sort
    fl2.sort();
    
    // Reverse
    fl2.reverse();
    
    // Merge lists
    fl1.merge(fl2);
    
    // Clear
    fl1.clear();
    
    for(int i : fl1)
        cout << i << endl;
    
    cout << endl;
    
    for(int i : fl2)
        cout << i << endl;
    
    // ---------- END FORWARD_LIST ----------
    return 0;
}
