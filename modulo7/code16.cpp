#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
using namespace std;

// Function Prototypes
vector<int> FindSubstringMatches(string theString,
        string substring);
 
string ReplaceAllSubstrings(string theString,
        string substring, string newString);

int main(){

    // 1. PROBLEM FIND ALL INDEX MATCHES RETURN VECTOR
    string phrase = "To be or not to be";
    
    vector<int> matches = FindSubstringMatches(phrase, "be");
    
    for(int i = 0; i < matches.size(); ++i){
        cout << matches[i] << endl;
    }
    // END PROBLEM
    
    // 2. PROBLEM REPLACE ALL SUBSTRINGS
    cout << ReplaceAllSubstrings("to know or not to know",
            "know", "be") << endl;
            
    // END PROBLEM REPLACE ALL SUBSTRINGS
    
    // CHARACTER FUNCTIONS
    char letterZ = 'z';
    char num3 = '3';
    char aSpace = ' ';
    
    cout << "Is z a letter or number " << 
            isalnum(letterZ) << endl;
    cout << "Is z a letter " << 
            isalpha(letterZ) << endl;
    cout << "Is z uppercase " << 
            isupper(letterZ) << endl;
    cout << "Is z lowercase " << 
            islower(letterZ) << endl;
    cout << "Is 3 a number " << 
            isdigit(num3) << endl;
    cout << "Is space a space " << 
            isspace(aSpace) << endl;
    
    // END CHARACTER FUNCTIONS

    return 0;
}

// 1. FIND ALL INDEX MATCHES RETURN VECTOR
vector<int> FindSubstringMatches(string theString,
        string substring){
    vector<int> matchingIndexes;
    
    // Check for matching substring
    int index = theString.find(substring, 0);
    
    // Keep adding indexes until none are left
    while(index != string::npos){
        matchingIndexes.push_back(index);
        index = theString.find(substring, index + 1);
    }
    
    return matchingIndexes;
}
 
// END PROBLEM
 
// 2. PROBLEM REPLACE ALL SUBSTRINGS
string ReplaceAllSubstrings(string theString,
        string substring, string newString){
    
    // Get a vector that contains all matching indexes
    vector<int> matches = FindSubstringMatches(theString, 
            substring);
    
    if(matches.size() != 0){
        // Get size difference between substring and newString
        int lengthDifference = newString.size() - substring.size();
        
        // Times through loop
        int timesLooped = 0;
         
        for(auto index: matches){
            theString.replace(index + (timesLooped * lengthDifference),
                    substring.size(),
                    newString);
            timesLooped++;
        }
    }
    
    return theString;
    
}
