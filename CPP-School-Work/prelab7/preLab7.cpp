// David Ridgely    dar304@txstate.edu
// March 30, 2021
// Lab 7 Prelab Assignment

#include <iostream>
using namespace std;

void welcome_message() {
    cout << "Welcome to my fabulous Jedi power level calculator!" << endl
         << "This program will take your age, weight, and" << endl
         << "midi-chlorian count and return your Jedi power level!"
         << endl << endl;
}

double get_jedilevel() {
    int age, weight, mcc;
    double jedi_level;

    cout << "Please enter your age: ";
    cin >> age;
    cout << "Please enter your weight: ";
    cin >> weight;
    cout << "Please enter your Midi-Chlorian count: ";
    cin >> mcc;

    jedi_level = static_cast <double>(mcc*age) / (weight*weight);
    return jedi_level;
}

int main() {
    double jedi_level = 0;
    int age;
    int weight;
    int mcc;

    // Calls a void function to print out to console a welcome message.
    welcome_message();

    // Calls a function that will prompt the user for his/her age,
    // weight, and midi-cholrian count. Then calculate and return their
    // jedi level (returns a double). Remember to assign the retuned value
    // to the variable 'jedi_level'.
    jedi_level = get_jedilevel();

    // this should remain inside your main function
    cout << "Your Jedi Level is : " << jedi_level;

    return 0;

    }
