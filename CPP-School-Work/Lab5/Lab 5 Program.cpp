//David Ridgely    dar304@txstate.edu
//March 9, 2021
//CS1428 Lab
//Lab 5
//Description: this program will print the first n factorials

//****************This is the line of 80 characters in length*******************
//############Your code should not exceed the length of the above line##########

#include <iostream>
using namespace std;

int main() {

    int num,
        factorial = 1;

    // Prompt the user for a number:
    cout << "Enter a number to find its factorial: ";
    cin >> num;
    cout << endl;

    // Validate input, then calculate and print the factorial:
    if (num < 0 || num > 12) {
        cout << "ERROR: Valid numbers are 0 to 12\n";
        return 0;
    }

    if (num == 0) {
        cout << "0! = 1\n";
        return 0;
    }

    cout << num << "! = ";
    for (int i = 1; i <= num; i++) {
        cout << i;
        if(i != num)
            cout << " * ";
        factorial *= i;
    }
    cout << " = " << factorial << endl;


    return 0;
}
