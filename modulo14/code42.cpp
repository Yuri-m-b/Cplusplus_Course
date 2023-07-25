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
 
bool isEven(const int& val)
{
    return (val % 2) == 0;
}
 
int main()
{
    // ---------- SEQUENCE CONTAINERS ----------
    // Contains data stored in order
    
    // ---------- DEQUES ----------
    
    // A deque (Deck) is a dynamic array like vectors
    // except it also allows for insertion or deletion
    // from the front
    deque<int> deq1; 
    
    // Add to the end and front
    deq1.push_back(5);
    deq1.push_front(1);
    
    // Add values with assign
    deq1.assign({11,12});
    
    // Get the size
    cout << "Size : " << deq1.size() << endl;
    
    // Access by index
    cout << deq1[0] << endl;
    cout << deq1.at(1) << endl;
    
    // Add at an index using an iterator
    deque<int>::iterator it = deq1.begin() + 1;
    deq1.insert(it, 3);
    
    // Add multiple values
    int tempArr[5] = {6,7,8,9,10};
    deq1.insert(deq1.end(), tempArr, tempArr+5);
    cout << deq1[4] << endl;
    
    // Erase at an index 
    deq1.erase(deq1.end());
    
    // Erase 1st 2 elements
    deq1.erase(deq1.begin(), deq1.begin()+2);
    
    // Pop first value
    deq1.pop_front();
    
    // Pop last
    deq1.pop_back();
    
    // Create a deque with 2 50s
    deque<int> deq2(2,50);
    
    // Swap values in deques
    deq1.swap(deq2);
    
    // Delete all values
    deq1.clear();
    
    // Cycle through the deque
    for(int i : deq1)
        cout << i << endl;
}

