// David Ridgely    dar304@txstate.edu
// March 2, 2021
// CS1428 Lab
// Lab 4
// Description: this program will calculate the cost of a TV
//    plan based on user choices.

//****************This is the line of 80 characters in length*******************
//############Your code should not exceed the length of the above line##########

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    char user_choice;  //user's choice
    double price; //price of monthly package

    // Ask the user for their plan choice:
    cout << "Enter the package name you wish to purchase: ";
    cin >> user_choice;

    // A switch statement to evaluate the total cost of the
    // customer's monthly bill based on the selected plan.
    switch(user_choice) {

        case 'a':
        case 'A':
            cout << "Would you like to purchase the sports plan? (Y/N)" << endl;
            cin >> user_choice;
            if(user_choice == 'y' || user_choice == 'Y') {
                price = 19.99 + 9.99;
            }else if (user_choice == 'n' || user_choice == 'N') {
                price = 19.99;
            }else {
                cout << "Invalid Input - Terminating Program." << endl;
            }
            break;

        case 'b':
        case 'B':
            cout << "Would you like to purchase the sports plan? (Y/N)" << endl;
            cin >> user_choice;
            if(user_choice == 'y' || user_choice == 'Y') {
                price = 39.99 + 9.99;
            }else if (user_choice == 'n' || user_choice == 'N') {
                price = 39.99;
            }else {
                cout << "Invalid Input - Terminating Program." << endl;
            }
            break;

        case 'c':
        case 'C':
            price = 45.99;
            break;

        default:
            cout << "Invalid input, terminating the program" << endl;
            break;
    }

    cout << "The total price of your monthly package is $" << price << endl;

    // Exit the program:
    return 0;
}
