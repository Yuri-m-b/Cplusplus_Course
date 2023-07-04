#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
using namespace std;

// Function Prototypes
vector< string> StringToVector(string str, 
        char separator);
 
string VectorToString(vector<string>& vec,
        char separator);
 
string TrimWhitespace(string);

int main(){

    // ----- 1. CONVERT STRING TO VECTOR -----
    // Create a function that receives a string and separator
    // and returns a string vector
    string sSentence = "This is a random string";
    
    // Create a vector
    vector<string> vec = StringToVector(sSentence, ' ');
    
    // Cycle through each index in the vector and print
    // out each word 
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i] << endl;
    }
    // ----- END PROBLEM CONVERT STRING TO VECTOR -----
    
    // ----- 2. PROBLEM CONVERT VECTOR TO STRING -----
    vector<string> vCusts(3);
    vCusts[0] = "Bob";
    vCusts[1] = "Sue";
    vCusts[2] = "Tom";
    
    string sCusts = VectorToString(vCusts, ' ');
    cout << sCusts << endl;
    
    // ----- END PROBLEM CONVERT VECTOR TO STRING -----
    
    // ----- 3. STRIP WHITESPACE -----
    // https://www.cplusplus.com/reference/string/string/

    string aStr = "   Just some random words   ";
    
    aStr = TrimWhitespace(aStr);
    
    cout << "*" << aStr << "*\n";
    
    // ----- END STRIP WHITESPACE -----

    return 0;
}

// ----- 1. CONVERT STRING TO VECTOR -----
vector<string> StringToVector(string str, 
        char separator){    
    // Create a vector
    vector<string> vecsWords;
    
    // A stringstream object receives strings separated
    // by a space and then spits them out 1 by 1
    stringstream ss(str);
    
    // Will temporarily hold each word in the string
    string sIndivStr;
    
    // While there are more words to extract keep
    // executing
    // getline takes strings from a stream of words stored
    // in the stream and each time it finds a blanks space
    // it stores the word proceeding the space in sIndivStr
    while(getline(ss, sIndivStr, separator)){
        
        // Put the string into a vector
        vecsWords.push_back(sIndivStr);
    }
    
    return vecsWords;
}
// ----- END CONVERT STRING TO VECTOR -----
 
// ----- 2. PROBLEM CONVERT VECTOR TO STRING -----
string VectorToString(vector<string>& vec,
        char separator){
    
    string theString = "";
    for(auto cust: vec)
        theString += cust + separator;
    
    return theString;
    
}
// ----- END PROBLEM CONVERT VECTOR TO STRING -----
 
// ----- 3. STRIP WHITESPACE -----
string TrimWhitespace(string theString){
    // find_last_not_of finds the last character
    // that doesn't match a list of defined characters
    string whitespaces(" \t\f\n\r");
    theString.erase(theString.find_last_not_of(whitespaces) + 1);
    
    // find_first_not_of does the same for the front of the string
    theString.erase(0, theString.find_first_not_of(whitespaces));
    
    return theString;
}
// ----- END STRIP WHITESPACE -----
