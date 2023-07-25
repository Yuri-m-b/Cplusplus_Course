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
#include <set>
using namespace std;

int main(){
    // ----- SET -----
    // Sets store unique sorted values using a key
    set<int> set1 {5,4,3,2,1,1};
    cout << "Size : " << set1.size() <<
            endl;
    
    // Insert value
    set1.insert(0);
    
    // Subscript operator doesn't work
    // cout << set1[0] << endl;
    
    // Get values with an iterator
    set<int>::iterator it = set1.begin();
    it++;
    
    cout << "2nd : " << *it << endl;
    
    // Erase value
    set1.erase(5);
    
    // Erase last 2
    it = set1.end();
    advance(it, -2);
    set1.erase(it, set1.end());
    
    // Add multiple values
    int arr[] = {6,7,8,9};
    set1.insert(arr,arr+4);
    
    // Find value, get iterator and then value
    auto val = set1.find(6);
    cout << "Found : " << *val << endl;
    
    // Get iterator to value
    auto eight = set1.lower_bound(8);
    cout << "8 : " << *eight << endl;
    
    // Get iterator to value after
    auto nine = set1.upper_bound(8);
    cout << "9 : " << *nine << endl;
    
    // Swap values in sets
    set<int> set2 {10,11};
    set1.swap(set2);
    
    // Check if empty and if not print values
    if(!set1.empty()){
        for(int i : set1)
        cout << i << endl;
    }

    // ----- MULTISET -----
    // Stores duplicate values in sorted order
    // Other than that it is the same as set
    multiset<int> mset1 {1,1,2,3,4};
    
    // Insert value
    mset1.insert(4);
    mset1.insert(0);
    
    if(!mset1.empty()){
        for(int i : mset1)
        cout << i << endl;
    }
    
    // ----- END MULTISET -----

    return 0;
}
