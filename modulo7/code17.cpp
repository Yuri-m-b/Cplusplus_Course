#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
using namespace std;

string CaesarCipher(string theString, int key, 
        bool encrypt);

// PROBLEM FUNCTION PROTOTYPES
vector< string> StringToVector(string theString, 
        char separator);
        
void SolveForX(string equation);

int main(){

    string theString = "Make me secret";
    
    string encryptedStr = CaesarCipher(theString, 
            5, true);
    
    string decryptedString = CaesarCipher(encryptedStr, 
            5, false);
    
    cout << "Encrypted " << encryptedStr << endl;
    cout << "Decrypted " << decryptedString << endl;

    // PROBLEM : Solve For X
    // // Make a function that receives an algebraic 
    // equation like x + 4 = 9 and solve for x
    // x will always be the 1st value received 
    // and you only will deal with addition
    cout << "Enter an equation to solve ";
    string equation = "";
    getline(cin, equation);
    SolveForX(equation);

    return 0;
}

string CaesarCipher(string theString, int key, 
        bool encrypt){
    string returnString = "";
    int charCode = 0;
    char letter;
    
    // The key will shift and unshift character codes
    if(encrypt) key = key * -1;
    
    // Cycle through each character
    for(char& c : theString) {
        
        // Check if it's a letter and if not don't chage it
        if(isalpha(c)){
            
            // Convert from char to int and shift the char code
            charCode = (int)c;
            charCode += key;
            
            // If uppercase check if the new character code >
            // char code for Z, or < char code for A
            // If so shift the character code so that its value
            // wraps back into the letter character codes
            if(isupper(c)){
                
                if(charCode > (int)'Z'){
                    charCode -= 26;
                } else if(charCode < (int)'A'){
                    charCode += 26;
                }
                
            } else {
                
                // Do the same for lowercase letters
                if(charCode > (int)'z'){
                    charCode -= 26;
                } else if(charCode < (int)'a'){
                    charCode += 26;
                }
                
            }
            
            // Convert from int to char and add the returning string
            letter = charCode;
            returnString += letter;
            
        } else {
            letter = c;
            returnString += c;
            cout << c << endl;
        }
        
    }
    
    return returnString;
}

// PROBLEM FUNCTIONS
vector< string> StringToVector(string theString, 
        char separator){
    
    vector< string> vecsWords;
    stringstream ss(theString);
    string sIndivStr;
    while(getline(ss, sIndivStr, separator)){
        vecsWords.push_back(sIndivStr);
    }
    return vecsWords;
}
 
void SolveForX(string equation){
    vector<string> vecEquation = 
            StringToVector(equation, ' ');
    
    // Convert strings to int
    int num1 = stoi(vecEquation[2]);
    int num2 = stoi(vecEquation[4]);
    int xVal = num2 - num1;
    
    cout << "x = " << xVal << endl;
}
