//David Ridgely dar304@txstate.edu
//March 1, 2021
//Pre Lab 4

// The following is an extremely scientific personality test that can predict
// how well you will do in this course.
// Fill in the area below with the requested code.

#include <iostream>

using namespace std;

int main()
{
     char answer;
     string message;

     cout << "Is Sponge Bob better than Patrick? ('Y' or 'N')" << endl;
     cin >> answer;

     switch(answer){
        case 'Y':
        case 'y':
            cout << "You think Sponge Bob is better than Patrick..." << endl;
            message = "Wrong";
            break;
        case 'N':
        case 'n':
            cout << "You do not think Sponge Bob is better than Patrick..."
                 << endl;
            message = "Correct!";
            break;
        default:
            message = "Invalid Input.";
            break;
     }

     cout << message << endl;

     return 0;
}
