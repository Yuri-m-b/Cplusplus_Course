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
    
    // Show true and false in output
    cout << boolalpha;
       
    // Determines if there is a match and match 
    // results are returned in matches
    while(regex_search(str, matches, reg)){
        cout << "Checked for Results : " << 
                matches.ready() << endl;
        
        cout << "Are there no matches : " << 
                matches.empty() << endl;
        
        cout << "Number of matches : " << 
                matches.size() << endl;
        
        // Get the first match
        cout << matches.str(1) << endl;
        
        // Eliminate the previous match and create
        // a new string to search
        str = matches.suffix().str();
        
        cout << endl;
    }
}
 
// ----- END BEGINNING REGEX -----
 
// ----- ITERATOR REGEX -----
 
void PrintMatches2(string str,
        regex reg){
    
    // This holds the first match
    sregex_iterator currentMatch(str.begin(),
            str.end(), reg);
    
    // Used to determine if there are any more matches
    sregex_iterator lastMatch;
    
    // While the current match doesn't equal the last
    while(currentMatch != lastMatch){
        smatch match = *currentMatch;
        cout << match.str() << endl;
        currentMatch++;
    }
    cout << endl;
    
}
 
// ----- END ITERATOR REGEX -----
 
int main()
{
    // ----- BEGINNING REGEX -----
    
    string str = "The ape was at the apex";
      
    // Create the pattern to search for which is
    // the letters ape followed maybe by anything
    // that is not a space
    regex reg ("(ape[^ ]?)");
    
    PrintMatches(str,reg);
    
    // ----- END BEGINNING REGEX -----
    
    // ----- ITERATOR REGEX -----
    
    // Using an iterator with all matches
    
    string str2 = "I picked the pickle";
    
    // Match (+) 1 or more of anything not a space
    regex reg2 ("(pick([^ ]+)?)");
    
    PrintMatches2(str2,reg2);
    
    // ----- END ITERATOR REGEX -----
    
    // ----- MATCH 1 OF SEVERAL LETTERS -----
    
    string str3 = "Cat rat mat fat pat";
    
    // Match any character in [] plus what follows
    regex reg3 ("([crmfp]at)");
    
    PrintMatches2(str3,reg3);
    
    // We can also match characters in a range
    regex reg4("[C-Fc-f]at");
    PrintMatches2(str3,reg4);
    
    // Use ^ to denote any character except for
    // those in brackets
    regex reg5("[^Cr]at");
    PrintMatches2(str3,reg5);
    
    // ----- END MATCH 1 OF SEVERAL LETTERS -----
    
    // ----- REPLACE MATCHES -----
    
    string str6 = "Cat rat mat fat pat";
    regex reg6("[Cr]at");
    
    // Replace matches with Owl in the output
    string owlFood = regex_replace(str6,reg6,"Owl");
    cout << owlFood << endl;
    
    // ----- END REPLACE MATCHES -----
    
    // ----- MATCHING ANY CHARACTER -----
    
    // . matches any character, but if we want to
    // search for a . we escape it with \
    
    string str7 = "F.B.I. I.R.S. CIA";
    regex reg7("([^ ]\..\..\.)");
    PrintMatches2(str7,reg7);
    
    
    // ----- END MATCHING ANY CHARACTER -----
    
    // ----- MATCHING WHITESPACE -----
    
    // We can match any whitespace character
    string str8 = "This is a\n multiline string\n"
            "that has many lines";
    regex reg8("\n");
    string noLBStr = regex_replace(str8,reg8," ");
    cout << noLBStr << endl;
    
    // You can also replace
    // \b : Backspace
    // \f : Form Feed
    // \r : Carriage Return
    // \t : Tab
    // \v : Vertical Tab
    
    // ----- END MATCHING WHITESPACE -----
    
    // ----- MATCHING SINGLE NUMBERS -----
    
    // \d can be used instead of [0-9]
    // \D is the same as [^0-9]
    string str9 = "12345";
    regex reg9("\\d");
    PrintMatches2(str9, reg9);
    
    // You can also match within a range
    string str10 = "123 12345 123456 1234567";
    
    // Match values that are between 5 and 7 digits
    regex reg10("\\d{5,7}");
    PrintMatches2(str10, reg10);
    
    // ----- END MATCHING SINGLE NUMBERS -----
    
    // ----- MATCHING ANY SINGLE LETTER OR NUMBER -----
    
    // \w is the same as [a-zA-Z0-9_]
    // \W is the same as [^a-zA-Z0-9_]
    string str11 = "412-555-1212";
    
    // Check if it is a phone number
    regex reg11("\\w{3}-\\w{3}-\\w{4}");
    PrintMatches2(str11, reg11);
    
    // ----- END MATCHING ANY SINGLE LETTER OR NUMBER -----
    
    // ----- MATCHING WHITESPACE -----
    
    // \s is the same as [\f\n\r\t\v]
    // \S is the same as [^\f\n\r\t\v]
    
    string str12 = "Toshio Muramatsu";
    
    // Check if its a valid name
    regex reg12("\\w{2,20}\\s\\w{2,20}");
    PrintMatches2(str12, reg12);
    
    // ----- END MATCHING WHITESPACE -----
    
    // ----- MATCHING ONE OR MORE -----
    
    // Match a followed by 1 or more characters
    string str13 = "a as ape bug";
    
    regex reg13("a[a-z]+");
    PrintMatches2(str13, reg13);
    
    // ----- END MATCHING ONE OR MORE -----
    
    // ----- PROBLEM -----
    // Create a Regex that matches email addresses 
    // from a list
    // 1. 1 to 20 lowercase and uppercase letters, 
    // numbers, plus ._%+-
    // 2. An @ symbol
    // 3. 2 to 20 lowercase and uppercase letters, 
    // numbers, plus .-
    // 4. A period
    // 5. 2 to 3 lowercase and uppercase letters
    
    string str14 = "db@aol.com m@.com @apple.com db@.com";
    
    regex reg14("[\\w._%+-]{1,20}@[\\w.-]{2,20}.[A-Za-z]{2,3}");
    PrintMatches2(str14, reg14);
    
    // ----- END PROBLEM -----
    
    return 0;
}
