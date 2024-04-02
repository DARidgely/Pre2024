//David Ridgely dar304@txstate.edu
//February 25, 2021
//CS1428 Lab
//Lab 3
//Description: this program will allow the user to play a game of Slug, Frog
//  Snake against a randomized computer opponent

//****************This is the line of 80 characters in length*******************
//############Your code should not exceed the length of the above line##########

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    int user_num;  //user's choice
    int comp_num;  //computer's choice

    // Generate the computer's choice randomly:
    srand(time(NULL));
    comp_num = rand() % 3 + 1;

    // Get the user's choice:
    cout << "Slug-Frog-Snake Game" << endl
         << " 1. Slug" << endl
         << " 2. Frog" << endl
         << " 3. Snake" << endl
         << "Enter a number : ";
    cin >> user_num;
    cout << endl;


    // Determine if the user wins, loses, or ties (or enters invalid input):
    if (user_num == 1) {
        if(user_num == 1 && comp_num == 1){
            cout << "You both chose slug! It's a tie!" << endl;
        }else if(user_num == 1 && comp_num == 2) {
            cout << "Frog beats slug! You Lose!" << endl;
        }else if(user_num == 1 && comp_num == 3) {
            cout << "Slug beats Snake! You Win!" << endl;
        }
    }else if(user_num == 2) {
        if(user_num == 2 && comp_num == 1) {
            cout << "Frog beats slug! You Win!" << endl;
        }else if(user_num == 2 && comp_num == 2) {
            cout << "You both chose frog! It's a tie!" << endl;
        }else if(user_num == 2 && comp_num == 3) {
            cout << "Snake beats frog! You Lose!" << endl;
        }
    }else if(user_num == 3) {
        if(user_num == 3 && comp_num == 1) {
            cout << "Slug beats snake! You Lose!" << endl;
        }else if (user_num == 3 && comp_num == 2) {
            cout << "Snake beats frog! You Win!" << endl;
        }else if (user_num == 3 && comp_num == 3) {
            cout << "You both chose snake! It's a tie!" << endl;
        }
    }else {
        cout << "ERROR - Invalid Input. Terminating Program." << endl;
        return -1;
    }


    // Exit the program:
    return 0;
}
