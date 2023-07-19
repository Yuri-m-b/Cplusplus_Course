#include <iostream>
#include <cmath>
#include <random>
using namespace std;

int numberGenerator ()
{
    int number;

    number = rand() % 101;
    //cout << number << endl;
    return number;
}

int main()
{
    int guess = -1, randomNumber;
    randomNumber = numberGenerator();

    while (guess != randomNumber)
    {
        cout << "Guess the Number: ";
        cin >> guess;
        if (guess > randomNumber)
        {
            cout << "Too big." << endl;
        }
        else if (guess < randomNumber)
        {
            cout << "Too small." << endl;
        }
        else
        {
            cout << "You guess the right number." << endl;
            break;
        }
    }

    return 0;
}
