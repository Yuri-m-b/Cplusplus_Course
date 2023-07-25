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
#include <regex>
using namespace std;
 
void PrintMatches(string str,
        regex reg){
    
    // Used when your searching a string
    smatch matches;
       
    // Determines if there is a match and match 
    // results are returned in matches
    while(regex_search(str, matches, reg)){
        
        // Get the first match
        cout << matches.str(1) << endl;
        
        // Eliminate the previous match and create
        // a new string to search
        str = matches.suffix().str();
    }
    cout << endl;
}
 
int main()
{   
    // Everything covered previously
    // [ ]   : Match what is in the brackets
    // [^ ]  : Match anything not in the brackets
    // .     : Match any 1 character or space
    // +     : Match 1 or more of what proceeds
    // \n    : Newline
    // \d    : Any 1 number
    // \D    : Anything but a number
    // \w    : Same as [a-zA-Z0-9_]
    // \W    : Same as [^a-zA-Z0-9_]
    // \s    : Same as [\f\n\r\t\v]
    // \S    : Same as [^\f\n\r\t\v]
    // {5}   : Match 5 of what proceeds the curly brackets
    // {5,7} : Match values that are between 5 and 7 in length
    // ()    : Return only what is between ()
    
    // ---------- MATCHING ZERO OR ONE ----------
    string str1 = "cat cats";
    regex reg1 ("([cat]+s?)");
    PrintMatches(str1, reg1);
    
    // ---------- MATCHING ZERO OR MORE ----------
    // * matches zero or more of what proceeds it
    
    string str2 = "doctor doctors doctor's";
    regex reg2 ("([doctor]+['s]{0,2})");
    PrintMatches(str2, reg2);
    
    // ---------- PROBLEM ----------
    //  On Windows newlines are some times \n and other times \r\n
    // Create a regex that will grab each of the lines in this
    // string and replace newlines with spaces
    
    string str3 = "Just some words\n"
            "and some more\r\n"
            "and more\n";
    regex reg3 ("[\r]?\n");
    string line = regex_replace(str3, reg3, " ");
    cout << line << endl;
    
    // ---------- GREEDY & LAZY MATCHING ----------
    
    // Let's try to grab everything between <name> tags
    // Because * is greedy (It grabs the biggest match possible)
    // we can't get what we want, which is each individual tag
    // match
    
    string str4 = "<name>Life On Mars</name>"
            "<name>Freaks and Geeks</name>";
    regex reg4 ("<name>(.*)</name>");
    PrintMatches(str4, reg4);
 
    // When we want to grab the smallest match we use *?, +?, or
    // {n,}? instead
    
    regex reg5 ("<name>(.*?)</name>");
    PrintMatches(str4, reg5);
    
    // ---------- WORD BOUNDARIES ----------
    
    // We use word boundaries to define where our matches start
    // and end
 
    // \\b matches the start or end of a word
 
    // If we want ape it will match ape and the beginning of apex
    string str6 = "ape at the apex";
    regex reg6 ("(ape)");
    PrintMatches(str6, reg6);
    
    // If we use a word boundary
    regex reg7 ("(\\bape\\b)");
    PrintMatches(str6, reg7);
    
    // ---------- STRING BOUNDARIES ----------
    
    // ^ : Matches the beginning of a string if outside of
    //     a [ ]
    // $ : Matches the end of a string
    
    // Grab everything from the start to the @
    string str8 = "Match everything up to @";
    regex reg8 ("(^.*[^@])");
    PrintMatches(str8, reg8);
    
    // Grab everything from @ to the end of the line
    string str9 = "@ Get this string";
    regex reg9 ("([^@\\s].*$)");
    PrintMatches(str9, reg9);
    
    // ---------- PROBLEM ----------
    
    // Get just the numbers minus the area codes from
    // this string
    
    string str10 = "206-709-3100 202-456-1111 212-832-2000";
    regex reg10 (".{3}-(.{8})");
    PrintMatches(str10, reg10);
    
    // ---------- MULTIPLE SUBEXPRESSIONS ----------
    // You can have multiple subexpressions as well
    // Get both numbers that follow 412 separately
    string str11 = "My number is 904-285-3700";
    regex reg11 ("(.{3})-(.*)-(.*)");
    smatch matches;
    if(regex_search(str11,matches,reg11)){
        for(int i = 1; i < matches.size(); i++){
            cout << matches[i] << endl;
        }
    }
    
    return 0; }
