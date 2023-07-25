#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
using namespace std;

int main()
{
    string userString = {};

    cout << "Enter your string: ";
    cin >> userString;

    int stringChar[userString.size()] = {};

    cout << "Secret: ";

    for(int i = 0; i < userString.size(); i++)
    {
        stringChar[i] = (int)userString[i];
        cout << stringChar[i];
    }
    cout << endl;

    string newString(stringChar, stringChar + userString.size());

    cout << "Original: " << newString << endl;

    return 0;
}

