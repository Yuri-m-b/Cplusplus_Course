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
    // ---------- LIST ----------
    // Lists are the most efficient at inserting,
    // moving and extracting elements, but lack
    // direct access to elements
    
    // Add values
    int arr[5] = {1,2,3,4,5};
    list<int> list1;
    list1.insert(list1.begin(), arr, arr+5);
    
    // Adding values with assign
    list1.assign({10,20,30});
    
    // Add to end and front
    list1.push_back(5);
    list1.push_front(1);
    
    // Get the size
    cout << "Size : " << list1.size()
            << endl;
    
    // Can't access index
    // cout << list1[0] << endl;
    
    // You can access the index with an iterator
    list<int>::iterator it2 = list1.begin();
    advance(it2, 1);
    cout << "2nd Index : " << 
            *it2 << endl;
    
    // Insert at an index
    it2 = list1.begin();
    list1.insert(it2, 8);
    
    // Erase at an index
    list1.erase(list1.begin());
    
    // Erase 1st 2 elements
    it2 = list1.begin();
    list<int>::iterator it3 = list1.begin();
    advance(it3, 2);
    list1.erase(it2, it3);
    
    // Pop first value
    list1.pop_front();
    
    // Pop last
    list1.pop_back();
    
    // Create another list
    int arr2[6] = {10,9,8,7,6,6};
    list<int> list2;
    list2.insert(list2.begin(), arr2, arr2+5);
    
    // Sort the list
    list2.sort();
    
    // Reverse the list
    list2.reverse();
    
    // Remove duplicates
    list2.unique();
    
    // Remove a value
    list2.remove(6);
    
    // Remove if a condition is true
    list2.remove_if (isEven);
 
    // Merge lists
    list1.merge(list2);
    
    for(int i : list2)
        cout << i << endl;
    
    cout << endl;
    
    // Cycle through the list
    for(int i : list1)
        cout << i << endl;
    
    cout << endl;

    return 0;
}
