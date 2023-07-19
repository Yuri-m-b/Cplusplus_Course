#include <iostream>
using namespace std;

int main()
{
    float num_mile, num_kil ;
    cout << "Enter the number in miles: ";
    cin >> num_mile;

    num_kil = num_mile * 1.60934;

    cout << "The number converted to Kilometers is: " << num_kil << endl;

    return 0;
}

