#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>
using namespace std;

void FindPrimes(unsigned int start, 
        unsigned int end,
        vector<unsigned int>& vect){
    
    // Cycle through numbers while ignoring evens
    for(unsigned int x = start; x <= end; x += 2){
        for(unsigned int y = 2; y < x; y++){
            if((x % y) == 0){
                break;
            } else if((y + 1) == x){
                vect.push_back(x);
            }
        }
    }
}
 
int main()
{
    vector<unsigned int> primeVect;
    
    // Get time before code starts executing
    int startTime = clock();
    
    FindPrimes(1, 100000, primeVect);
    for(auto i: primeVect)
        cout << i << endl;
  
    // Get time after execution
    int endTime = clock();
    
    // Print out the number of seconds by taking the difference
    // and dividing by the clock ticks per second
    cout << "Execution Time : " << 
            (endTime - startTime)/double(CLOCKS_PER_SEC) 
            << endl;
    
    return 0;
}
