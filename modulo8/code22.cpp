#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cmath>
using namespace std;
 
vector<int> GenerateRandVec(int numOfNums, int min, int max);
 
int main()
 {
    
    // ----- LAMBDA EXPRESSIONS -----
    
    vector<int> vecVals = GenerateRandVec(10, 1, 50);
    
    // Lambda Expressions make it easy to perform list
    // operations in one line of code. You designate
    // them with []
    // Here we sort a vector
    sort(vecVals.begin(), vecVals.end(), [](int x, int y){ return x < y; });
            
    for(auto val: vecVals)
        cout << val << endl;
            
    cout << endl;
    
    // copy_if works like filter does in other languages
    // Here we keep only even values in a new vector
    vector<int> evenVecVals;
    
    copy_if(vecVals.begin(), vecVals.end(), back_inserter(evenVecVals), 
            [](int x){ return (x % 2) == 0; });
            
    for(auto val: evenVecVals)
        cout << val << endl;
            
    // ----- SUM A LIST -----
    int sum = 0;
    
    // for_each cycles through all values
    // [&] captures all variables used
    // in the body of the lambda by reference
    for_each(vecVals.begin(), vecVals.end(), [&] (int x) {sum += x; });
            
            cout << "SUM : " << sum << endl;
            
    // ----- END SUM A LIST -----
    
    return 0;
}
 
vector<int> GenerateRandVec(int numOfNums, int min, int max)
{
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
