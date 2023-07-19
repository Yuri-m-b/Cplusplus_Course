#include <iostream>
using namespace std;

int main()
{
    static int age;
    cout << "Enter your age: ";
    cin >> age;

    if (age < 6)
    {
        cout << "You are too young.";
    }

    else if (age > 18)
    {
        cout << "Go to college.";
    }

    else
    {
        cout << "Your grade is: " << age - 5 << "st grade" << endl;
    }

    return 0;
}
