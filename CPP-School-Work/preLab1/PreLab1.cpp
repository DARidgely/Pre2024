//David Ridgely    dar304@txstate.edu
//Jan 30, 2021
//Pre-Lab 1

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 1.
    // There are a several errors with the below code
    // Fix the syntax and logical errors.

    // The Program should take two integers from the user and assign them to x and d.
    // The program should then print d to the power of 2 and x + 36

    int d;
    int x;

    cout << "Enter the value for d:" << endl;
    cin >> d;

    cout << "Enter the value for x:" << endl;
    cin >> x ;

    x += 36;
    d = d*d;

    cout << "d to the power of 2 = " << d << endl;
    cout << "x + 36 = " << x << endl;

    // 2.
    // Write code that takes the number of pounds the user
    // can lift (use cin), divides that number by 2.20462, and then
    // prints it to the screen. This will convert pounds to kg.
    // (200 pounds is equal to 90.7186 kilograms)

    int userPoundsLift;

    cout << "Many pounds can you lift?" << endl;
    cin >> userPoundsLift;

    cout << "You can lift " << userPoundsLift / 2.20462 << "kg." << endl;



return 0;
}
