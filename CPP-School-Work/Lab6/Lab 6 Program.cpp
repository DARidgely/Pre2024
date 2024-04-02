//David Ridgely    dar304@txstate.edu
//March 23, 2021
//CS1428 Lab
//Lab 6
//Description: this program will perform some operations on the digits of a number

//****************This is the line of 80 characters in length*******************
//############Your code should not exceed the length of the above line##########


#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int number, sum, even_sum, odd_sum;
    long factorial;
    int lastDigit;
    char userContinue;

    // TODO: Compute the sum of digits and
    // the factorial of the highest digit:

    do {
        cout << "Enter a number (5 - 20)" << endl;
        cin >> number;

        if(number < 5 || number > 100) {
            cout << "Invalid input." << endl;
            cout << "Enter a number (5 - 20): ";
            cin >> number;
        }

        factorial = 1;
        cout << number << "! = ";
        for (int i = 1; i <= number; i++) {
            cout << i;
            if (i != number)
                cout << " x ";
            factorial *= i;
        }
        cout << " = " << factorial << endl;

        even_sum = 0;
        odd_sum = 0;
        while (factorial != 0) {
            lastDigit = factorial%10;
            if(lastDigit%2==0)
                even_sum = even_sum + lastDigit;
            else{
                odd_sum = odd_sum + lastDigit;
            }
            factorial = factorial/10;
        }

        cout << "Sum of even digits: " << even_sum << endl;
        cout << "Sum of odd digits: " << odd_sum << endl;


        cout << "Do you want to continue (y/n)?";
        cin >> userContinue;
        cout << endl;
    }while(userContinue != 'n' && userContinue != 'N');

    cout << "Have a great day!!!" << endl;

    return 0;
}
