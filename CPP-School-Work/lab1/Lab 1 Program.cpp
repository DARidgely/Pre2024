//David Ridgely dar304@txstate.edu
//2/2/2021
//CS1428 Lab
//Lab 1
//Description: this program will calculate number of circles in a rectangular color paper

#include <iostream>
using namespace std;

int main() {

    int width;
    int height;
    int radiusCircle;
    double areaOfRectangle;
    double areaOfCircle;
    int numOfCircles;

    // Prompt the user for width of a rectangle and store it:
    cout << "Enter the width of a rectangle:" << endl;
    cin >> width;

    //Prompt for and store the rectangles's height and circle's radius:
    cout << "Enter the height of a rectangle:" << endl;
    cin >> height;

    cout << "Enter the radius of a circle:" << endl;
    cin >> radiusCircle;

    //Calculate number of circles and the left over paper and assign them to the appropriate variables:
    areaOfRectangle = (width * height);
    areaOfCircle = 3.142 * (radiusCircle*radiusCircle);
    numOfCircles = areaOfRectangle / areaOfCircle;

    areaOfRectangle = areaOfRectangle - (areaOfCircle*numOfCircles);

    //Display the result to the console:
    cout << "Number of circles that can be cut from the rectangle: " << numOfCircles << endl;
    cout << "Area of the left over color paper: " << areaOfRectangle << endl;


    // Exit the program:
    return 0;
}
