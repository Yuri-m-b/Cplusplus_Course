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
 
// [ ]   : Match what is in the brackets
// [^ ]  : Match anything not in the brackets
// ( )   : Return surrounded submatch
// .     : Match any 1 character or space
// +     : Match 1 or more of what proceeds
// ?     : Match 0 or 1
// *     : Match 0 or More
// *?    : Lazy match the smallest match
// \b    : Word boundary
// ^     : Beginning of String
// $     : End of String
// \n    : Newline
// \d    : Any 1 number
// \D    : Anything but a number
// \w    : Same as [a-zA-Z0-9_]
// \W    : Same as [^a-zA-Z0-9_]
// \s    : Same as [\f\n\r\t\v]
// \S    : Same as [^\f\n\r\t\v]
// {5}   : Match 5 of what proceeds the curly brackets
// {5,7} : Match values that are between 5 and 7 in length
 
int main()
{   
    // ---------- Back References ----------
    // A back reference allows you to to reuse the expression
    // that proceeds it
 
    // Grab a double word
    string str1 = "The cat cat fell out the window";
 
    // Match word boundary, 1 or more characters, space
    // and the same word that proceeded it
    // \\1 is used to refer to the 1st match surrounded
    // by ()
    regex reg1 ("(\\b\\w+)\\s+\\1");
    
    PrintMatches(str1,reg1);
    
    // ---------- Back Reference Substitutions ----------
    
    // Replace the bold tags in the link with no tags
    
 
    // Regex matches bold tags and grabs the text between
    // them to be used by the back reference
    regex reg2 ("<b>(.*?)</b>");
    
    // Holds the new string
    string result;
    
    // regex_replace makes a copy of the original
    // along with the replaced parts
    // back_inserter inserts the final results
    // into result
    // $1 references the subexpression surrounded
    // with () ex. (.*?)
    
    regex_replace(back_inserter(result), str1.begin(), str1.end(), reg2, "$1");
    cout << result << endl;
    
    // ---------- Another Back Reference Substitution ----------
    // Here I want to surround all phone number
    // area codes with ()
    
    string str3 = "412-555-1212";
    
    // I create 2 subexpressions
    regex reg3 ("([\\d]{3})-([\\d]{3}-[\\d]{4})");
    
    // Holds the new string
    string res3;
    
    // The output is the area code surrounded with ()
    // and then the 2nd subexpression
    regex_replace(back_inserter(res3), str3.begin(), str3.end(), reg3, "($1)$2");
    cout << res3 << endl;
    
    // ---------- PROBLEM ----------
    // Receive a string like this
 
    string str4 = "https://www.youtube.com "
            "http://www.google.com";
 
    // Grab the URL and then provide the following output
    // using a back reference substitution
    // <a href='https://www.youtube.com'>www.youtube.com</a>
    // <a href='https://www.google.com'>www.google.com</a>
    
    // Grab the whole URL and the web page name
    regex reg4 ("(https?://([\\w.]+))");
    
    // Holds the new string
    string res4;
    
    regex_replace(back_inserter(res4), 
            str4.begin(), str4.end(), reg4, 
            "<a href='$1'>$2</a>\n");
    cout << res4 << endl;
    
    // ---------- Look Ahead ----------
    // A look ahead defines a pattern to match but not 
    // return
    // You define the expression to look for but not 
    // return
    // like this (?=expression)
    
    string str5 = " one two three four ";
    
    // I don't want to return the word boundaries
    regex reg5 ("(\\w+(?=\\b))");
    
    PrintMatches(str5,reg5);
    
    // ---------- OR Conditional ----------
    // You can use | to define the matches you'll except
 
    string str6 = "1. Dog 2. Cat 3. Turtle";
    
    regex reg6 ("\\d\\.\\s(Dog|Cat)");
    
    PrintMatches(str6,reg6);
    
    // ---------- PROBLEM ----------
    // Create a regex that will match for 5 digit zip
    // codes or zip codes with 5 digits a dash and
    // then 4 digits
    
    string str7 = "12345 12345-1234 1234 12346-333";
    
    regex reg7 ("(\\d{5}-\\d{4}|\\d{5}\\s)");
    
    PrintMatches(str7,reg7);
    
    // ---------- PROBLEM ----------
    // Find all of the following phone numbers 
    // and then print them
    
    string str8 = "14125551212 4125551212 "
            "(412)5551212 412 555 1212 412-555-1212 "
            "1-412-555-1212";
    
    regex reg8 ("((1?)(-| ?)(\\()?(\\d{3})(\\)|-| |\\)-|\\) )?(\\d{3})(-| )?(\\d{4}|\\d{4}))");
    
    PrintMatches(str8,reg8);
            
    return 0;
}
