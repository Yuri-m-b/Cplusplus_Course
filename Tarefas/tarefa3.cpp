#include <iostream>
#include <cmath>
using namespace std;

void printOdd()
{
    int n;
    for (n = 0; n < 21; n++)
    {
        if (n % 2 == 1)
        {
            cout << "Number: " << n << " is an odd number." << endl;
        }
    }
}

/*
Equation used:
A = P * (1 + r/n)^(n*t)

Where:
A = the final amount (including principal and interest)
P = the principal amount (initial investment)
r = the annual interest rate (expressed as a decimal)
n = the number of times the interest is compounded per year
t = the number of years
*/
void interestCompound()
{
    float A;
    static int P,r,n,t;

    r = 10;
    n = 1;
    P = 1000;

    cout << "How many years would you like to calculate?: ";
    cin >> t;

    A = P * (1 + r/n)^(n*t);

    cout << "The total amout of money you will have is: $" <<A << endl;

}

int main()
{
    printOdd();
    interestCompound();
    return 0;
}
