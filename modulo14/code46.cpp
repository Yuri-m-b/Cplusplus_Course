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
#include<map>
using namespace std;

int main(){
    // ----- MAP -----
    // Stores using key value pairs and you
    // can't have duplicate keys
    map<int, string> map1;
    
    // Insert key values
    map1.insert(pair <int, string> (1, "Bart"));
    map1.insert(pair <int, string> (2, "Lisa"));
    map1.insert(pair <int, string> (3, "Marge"));
    map1.insert(pair <int, string> (4, "Homer"));
    
    // Find element by key
    auto match = map1.find(1);
    cout << match->second << endl;
    
    // Get iterator to value
    auto bart = map1.lower_bound(1);
    cout << "LB : " << bart->second << endl;
    
    // Get next iterator
    auto lisa = map1.upper_bound(1);
    cout << "UB : " << lisa->second << endl;
    
    // Print elements with an iterator
    map<int, string>::iterator it2;
    for(auto it2 = map1.begin(); it2 != map1.end(); ++it2){
        cout << "Key : " << it2->first << endl;
        cout << "Value : " << it2->second << endl;
    }
    
    // ----- END OF MAP -----
    
    // ----- MULTIMAP -----
    // Like map except you can have duplicate keys as long
    // as the values are different
    multimap<int, string> mmap1;
    mmap1.insert(pair <int, string> (1, "Bart"));
    mmap1.insert(pair <int, string> (1, "Lisa"));
    mmap1.insert(pair <int, string> (3, "Marge"));
    map<int, string>::iterator it3;
    for(auto it3 = mmap1.begin(); it3 != mmap1.end(); ++it3){
        cout << "Key : " << it3->first << endl;
        cout << "Value : " << it3->second << endl;
    }
    
    // ----- END OF MULTIMAP -----
    return 0;
}
