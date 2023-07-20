#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
using namespace std;
 
// iostream allows use to read from the standard 
// input (keyboard) and write to the standard output
// (console)
// fstream is needed for working with files
#include <fstream>
 
// ----- PROBLEM FUNCTION PROTOTYPE -----
 
vector<string> StringToVector(string theString, char separator);
 
// ----- END OF PROBLEM FUNCTION PROTOTYPE -----
 
int main()
{
    ofstream writeToFile;
    ifstream readFromFile;
    string txtToWrite = "";
    string txtFromFile = "";
    
    // We open the file by providing a name and then either
    // ios::app : Append to the end of the file
    // ios::trunc : If the exists delete content
    // ios::in : Open file for reading
    // ios::out : Open file for writing
    // ios::ate : Open writing and move to the end of the file
    writeToFile.open("test.txt", ios_base::out | 
            ios_base::trunc);
    
    if(writeToFile.is_open()){
        // You can write with the stream insertion operator
        writeToFile << "Beginning of File\n";
 
        // You can write data in a string
        cout << "Enter data to write : ";
        getline(cin, txtToWrite);
        writeToFile << txtToWrite;
        
        // Close the file 
        writeToFile.close();
    }
    
    // Open the file for reading
    readFromFile.open("test.txt", ios_base::in);
    
    if(readFromFile.is_open()){
        
        // Read text from file
        while(readFromFile.good()){
            getline(readFromFile, txtFromFile);
        
            // Print text from file
            cout << txtFromFile << endl;
            
            // ----- PROBLEM -----
            // After each line print both the number of 
            // words in each line and the average word length
            
            vector<string> vect = 
                    StringToVector(txtFromFile, ' ');
            
            int wordsInLine = vect.size();
            
            cout << "Words in Line : " << 
                     wordsInLine << endl;
            
            int charCount = 0;
            
            for(auto word: vect){
                for(auto letter: word){
                    charCount++;
                }
            }
            
            int avgNumChars = charCount/wordsInLine;
            
            cout << "Avg Word Length : " <<
            avgNumChars << endl;
            
            // ----- END OF PROBLEM -----
        }   
        readFromFile.close();
    }
    
    return 0;
}
 
// ----- PROBLEM FUNCTION -----
 
vector<string> StringToVector(string theString, 
        char separator){
 
    // Create a vector
    vector<string> vecsWords;
    
    // A stringstream object receives strings separated
    // by a space and then spits them out 1 by 1
    stringstream ss(theString);
    
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
