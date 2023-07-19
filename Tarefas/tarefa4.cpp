#include <iostream>
#include <cmath>
using namespace std;

void draw(int size)
{
    int spaces = size - 1;
    int hashes = 1;
    int stump_spaces = size - 1;

    while (size > 0) {
        // Print spaces
        for (int i = 0; i < spaces; i++) {
            cout << " ";
        }

        // Print hashes
        for (int i = 0; i < hashes; i++) {
            cout << "#";
        }

        // Move to the next row
        cout << endl;

        spaces--;
        hashes += 2;
        size--;
    }

    // Print the stump
    for (int i = 0; i < stump_spaces; i++) {
        cout << " ";
    }
    cout << "#" << endl;
}


int main()
{
    int size;
    cout << "What is the height of the tree?: ";
    cin >> size;

    draw(size);

    return 0;
}
