// David Ridgely    dar304@txstate.edu

// March,8 2021

// Lab 5 Pre-Lab

// Finish the following program which adds up all integers from 1 to
// the user's given number inclusively using a FOR loop. The total should be
// assigned to the variable 'total'.

#include <iostream>
using namespace std;

int main()
{
    int number;
    int total;
    int i;

    cout << "Enter a positive integer to find the summation of"
         << " all numbers from 1 to the given number." << endl;
    cin >> number;

    for (i = 1; i <= number; i++) {
        total += i;
    }


    cout << "Total : " << total << endl;

    return 0;
}
