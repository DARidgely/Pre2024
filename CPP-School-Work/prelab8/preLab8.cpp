// David Ridgely    dar304@txstate.edu
// April 5, 2021
// pre-Lab 8

// Add the following functions:

// 1. 'getSide' asks the user to enter the length of a side of a
//     pyramid and returns the given value. (should return a double)

// 2. 'calcVolume' takes the length of a side and returns the volume of a pyramid.

// The volume of a pyramid is (1/3)*side^3

// 3. 'printResults' void type function that should print the results to
//    console.

// The function call is provided, you just need to implement the
// function prototype and function definition.

#include <iostream>
#include <cmath>
using namespace std;

double getSide();
double calcVolume(double);
void printResults(double);

int main()
{
    double side, volume;

    side = getSide();
    volume = calcVolume(side);
    printResults(volume);

    return 0;
}

double getSide() {
    double side;

    cout << "Enter length of a side of the pyramid: ";
    cin >> side;

    return side;
}

double calcVolume(double side) {
    double volume;

    volume = (1.0/3.0) * pow(side, 3);

    return volume;
}

void printResults(double volume) {
    cout << "The Volume of your pyramid is " << volume << " units cubed."
         << endl;
}
