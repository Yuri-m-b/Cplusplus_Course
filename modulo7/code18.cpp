#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
using namespace std;

// PROBLEM : LIST OF PRIMES PROTOTYPES
vector<int> Range(int start, 
        int max, int step);
 
bool IsPrime(int num);
 
vector<int> GetPrimes(int maxNum);

// PROBLEM : GENERATE RANDOM VECTOR OF NUMBERS
vector<int> GenerateRandVec(int numOfNums,
        int min, int max);

int main(){

    // ----- LIST OF PRIMES -----

    int num = 0;
    cout << "Number to Check : ";
    cin >> num;
    
    // Shows bool values as true or false
    cout.setf(ios::boolalpha);
    cout << "Is " << num << " Prime " <<
            IsPrime(num) << endl;
    
    cout << "Generate Primes up to ";
    int maxPrime;
    cin >> maxPrime;
    
    vector<int> primeList = GetPrimes(maxPrime);
    for(auto x: primeList)
        cout << x << endl;

    // ----- END OF LIST OF PRIMES -----

    // ----- RANDOM VECTOR -----

    vector<int> vecVals = GenerateRandVec(10, 5, 50);
    for(auto x: vecVals)
        cout << x << endl;

    // ----- END OF RANDOM VECTOR -----

    return 0;
}

// FUNCTIONS FOR PROBLEM : LIST OF PRIMES PROTOTYPES
vector<int> Range(int start, int max, 
        int step){
    
    int i = start;
    vector<int> range;
    while(i <= max){
        range.push_back(i);
        i += step;
    }
    return range;
}
 
bool IsPrime(int num){
    for(auto n: Range(2, num - 1, 1)){
        if((num % n) == 0)
            return false;
    }
    return true;
}
 
vector<int> GetPrimes(int maxNum){
    
    vector<int> vecPrimes;
    
    for(auto x: Range(2, maxNum, 1)){
        if(IsPrime(x))
            vecPrimes.push_back(x);
    }
    
    return vecPrimes;
}

// FUNCTIONS FOR PROBLEM : GENERATE RANDOM VECTOR OF NUMBERS
vector<int> GenerateRandVec(int numOfNums,
        int min, int max){
    vector<int> vecValues;
    
    // Seed the random number generator
    srand(time(NULL));
    
    int i = 0, randVal = 0;
    
    while(i < numOfNums){
        // The min added on increases result based on min
        // The remainder of modulus can't be greater
        // then the divisor. We have to adjust down
        // based on the addition from min
        randVal = min + rand() % ((max + 1) - min);
        vecValues.push_back(randVal);
        i++;
    }
    return vecValues;
}

