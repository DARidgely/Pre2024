//Author: David Ridgely    dar304@txstate.edu

//Date: March 22, 2021

// Finish the following program which prints 'Boko' for every third integer
//from 0 to the user's given number inclusively using a While Loop.

#include <iostream>

using namespace std;

int main() {
    int number;
    int counter = 0; //initialize the variable

    // user enters a number
    cout << "Enter a positive integer to print 'Boko' for";
    cout << "every third number from 0 to the given number up to 40." << endl;
    cin >> number;

    // check for invalid user input
    if (number < 1  || number > 40)
    {
        cout << "Invalid Input" << endl;
        return -1; // terminate program
    }

    //Print every number up to the
    //user's number. Every third number print 'Boko' instead
    //Example:
    //1 2 Boko 4 5 Boko
    //for numbers from 0 to the user's number.

    while (counter < number) {
        counter = counter + 1;
        if(counter % 3 == 0) {
            cout << "Boko ";
        }else {
            cout << counter << " ";
        }
    }

    return 0;
}
