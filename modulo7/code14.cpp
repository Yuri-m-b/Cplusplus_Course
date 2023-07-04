#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
using namespace std;
 
int main() {
 
    // A C character string is an array of characters
    // with a null character at the end \0
    char cString[] = {'A', ' ', 'S', 't', 'r', 'i', 'n', 'g', '\0'};
    cout << cString << endl;
    
    // Get array size (null is included)
    cout << "Array Size " << sizeof(cString) << endl;
    
    // C strings are troublesome because if you forget \0, or
    // add to much information it can lead your program to crash,
    // or for your system to crash
    
    // You can create a vector of strings
    vector<string> strVec(10);
    
    // C++ string can grow in size and is much safer
    string str("I'm a string");
    strVec[0] = str;
    
    // You can access characters with an index
    cout << str[0] << endl;
    
    // You can also use at()
    cout << str.at(0) << endl;
    
    // Front returns first char and back returns last
    cout << str.front() << " " << str.back() << endl;
    
    // Get the string length
    cout << "Length : " << str.length() << endl;
    
    // You can copy a string to another
    string str2(str);
    strVec[1] = str2;
    
    // You can copy after the 1st 4 characters
    string str3(str, 4);
    strVec[2] = str3;
    
    // Repeat a value to make a string
    string str4(5, 'x');
    strVec[3] = str4;
    
    // Combine strings with append or +
    strVec[4] = str.append(" and your not");
    str += " and your not";
    
    // Append part of a string
    str.append(str, 34, 37);
    strVec[5] = str;
    
    // Erase characters from a string from an index to another
    // or the last
    str.erase(13, str.length() - 1);
    strVec[6] = str;
    
    for(auto y: strVec)
        cout << y << endl;
    
    // find() returns index where pattern is found
    // or npos
    if(str.find("string") != string::npos)
        cout << "1st not " << str.find("string") << endl;
    
    // substr(x, y) returns a substring starting at
    // index x with a length of y
    cout << "Substr " << str.substr(6,6) << endl;
    
    // Reverse a string by passing the beginning and end
    // of a string
    reverse (str.begin(), str.end());
    cout << "Reverse " << str << endl;
    
    // Case conversion
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    cout << "Upper " << str2 << endl;
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    cout << "Lower " << str2 << endl;
    
    // You can get the ascii code for a char by saving
    // the char as an int or with (int)
    // a - z : 97 - 122
    // A - Z : 65 - 90
    char aChar = 'Z';
    int aInt = aChar;
    cout << "A Code " << (int)'a' << endl;
    
    // Convert int to string
    string strNum = to_string(1+2);
    cout << "String " << strNum << endl;
    
    // ----- PROBLEM : SECRET STRING -----
    // Receive an uppercase string and hide its meaning
    // by turning it into ascii codes
    // Translate it back to the original letters
    
    string normalStr, secretStr = "";
    cout << "Enter your string in uppercase : ";
    cin >> normalStr;
    
    // Cycle through each character converting 
    // them into ascii codes which are stored in
    // a string
    for(char c: normalStr)
        secretStr += to_string((int)c);
        // SOLVES SECOND PROBLEM
        // secretStr += to_string((int)c - 23);
    
    cout << "Secret : " << secretStr << endl;
    
    normalStr = "";
    
    // Cycle through numbers in string 2 at a time
    for(int i = 0; i < secretStr.length(); i += 2){
        
        // Get the 2 digit ascii code
        string sCharCode = "";
        sCharCode += secretStr[i];
        sCharCode += secretStr[i+1];
        
        // Convert the string into int
        int nCharCode = stoi(sCharCode);
        
        // Convert the int into a char
        char chCharCode = nCharCode;
        // SOLVES SECOND PROBLEM
        // char chCharCode = nCharCode + 23;
        
        // Store the char in normalStr
        normalStr += chCharCode;
    }
    
    cout << "Original : " << normalStr << endl;
    
    // ----- END OF PROBLEM : SECRET STRING -----
    
    // ----- BONUS PROBLEM -----
    // Allow the user to enter upper and lowercase
    // letters by subtracting and adding 1 value
    // ----- END OF BONUS PROBLEM -----
    
    return 0;
    
}
