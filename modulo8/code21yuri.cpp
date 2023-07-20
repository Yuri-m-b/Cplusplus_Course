#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cmath>
using namespace std;

double Area(double radius);

double Area(double height, double width);

int main()
{
    cout << "Area Circle (c) or Rectangle (r): ";
    char areaType;
    cin >> areaType;

    switch(areaType)
    {
        case 'c':
            cout << "Enter Radius: ";
            double radius;
            cin >> radius;
            cout << "Area = " << Area(radius) << endl;
            break;
        case 'r':
            cout << "Enter Height: ";
            double height, width;
            cin >> height;
            
            cout << "Enter Width: ";
            cin >> width;
            cout << "Area = " << Area(height, width) << endl;
            break;
        default: cout << "Please enter 'c' or 'r'.";
    }




    return 0;
}

double Area(double radius)
{
    return 3.14159 * pow(radius, 2);
}

double Area(double height, double width)
{
    return height * width;
}
