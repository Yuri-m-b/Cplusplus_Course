#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cmath>
using namespace std;
 
vector<int> GenerateRandVec(int numOfNums,
        int min, int max);
 
vector<int> GenerateFibList(int maxNums);

int main(){
    vector<int> vecVals = GenerateRandVec(10, 1, 50);

    // ----- PROBLEM DYNAMIC LIST DIVISABLE BY A VALUE -----
            
    // You can define what value is checked for divisability
    // by passing the value to check in the capture list
    // which lies between [] 
    // Send a value entered by the user through the capture
    // list and create a list based on it
    int divisor;
    vector<int> vecVals2;
    cout << "List of values divisable by : ";
    cin >> divisor;
    copy_if(vecVals.begin(), vecVals.end(),
            back_inserter(vecVals2), 
            [divisor](int x){ return (x % divisor) == 0; });
    for(auto val: vecVals2)
        cout << val << endl;
            
    // ----- END PROBLEM DYNAMIC LIST DIVISABLE BY A VALUE -----  
            
    // ----- MULTIPLY ALL VALUES BY 2 -----
    vector<int> doubleVec;
    
    // For_each cycles through all values in the vector
    // and doubles them. 
    for_each(vecVals.begin(), vecVals.end(),
            [&](int x){doubleVec.push_back(x * 2);});
            
    for(auto val: doubleVec)
        cout << "DBL : " << val << endl;
            
    // ----- END MULTIPLY ALL VALUES BY 2 -----  
    
    // ----- RECURSIVE LAMBDA FUNCTIONS -----
    
    // Recursive Lambda to calculate Fibonacci Numbers
    function<int(int)> Fib = 
    [&Fib](int n) {return n < 2 ? n : Fib(n-1) + Fib(n-2);};
    
    // Fib(0) = 0
    // Fib(1) = 1
    // Fib(2) = 1
    // Fib(3) = 2
    // Fib(4) = 3
    cout << "Fib 4 : " << Fib(4) << endl;
    
    // ----- END RECURSIVE LAMBDA FUNCTIONS -----
    
    // ----- PROBLEM GENERATE DYNAMIC VECTOR OF FIBS -----
    vector<int> listOfFibs = GenerateFibList(10);
    for(auto val: listOfFibs)
        cout << val << endl;
    // ----- END PROBLEM GENERATE DYNAMIC VECTOR OF FIBS -----

    return 0;
}

vector<int> GenerateRandVec(int numOfNums,
        int min, int max){
    vector<int> vecValues;
    srand(time(NULL));
    int i = 0, randVal = 0;
    while(i < numOfNums){
        randVal = min + rand() % ((max + 1) - min);
        vecValues.push_back(randVal);
        i++;
    }
    return vecValues;
}
 
// ----- PROBLEM GENERATE DYNAMIC VECTOR OF FIBS -----
vector<int> GenerateFibList(int maxNums){
    vector<int> listOfFibs;
    int i = 0;
    function<int(int)> Fib = [&Fib](int n) {return n < 2 ? n : Fib(n-1) + Fib(n-2);};
    while(i < maxNums){
        listOfFibs.push_back(Fib(i));
        i++;
    }
    return listOfFibs;
}
// ----- END PROBLEM GENERATE DYNAMIC VECTOR OF FIBS -----
