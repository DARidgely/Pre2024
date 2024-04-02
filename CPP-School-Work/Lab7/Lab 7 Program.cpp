//David Ridgely    dar304@txstate.edu
//March 30, 2021
//CS1428 Lab
//Lab 7
//Description: this program will play a simple dice rolling game with the player

//****************This is the line of 80 characters in length*******************
//############Your code should not exceed the length of the above line##########


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function prototypes
int placeBet();
int getRoll();
char playAgain();

int main()
{
	char choice;
	int money = 1000,
		bet,
		computer_roll,
		user_roll;

	srand(time(NULL)); // Seeds the random number generator

	cout << "Gambling is an addiction..." << endl;

	do{
		cout << endl << "You currently have $" << money << endl;
		bet = placeBet(); //Function call

		// Error checking on bet amount
		while(bet > money || bet < 1){
			cout << "ERROR: Invalid bet amount." << endl;
			bet = placeBet(); //Function call
		}

		// Dice rolls
		user_roll = getRoll(); //Function call
		computer_roll = getRoll(); //Function call

		// Display dice rolls
		cout << "You rolled " << user_roll << endl
		     << "Your opponent rolled " << computer_roll << endl;

		// Determine winner
		if(user_roll > computer_roll){
			cout << "You win $" << bet << endl;
			money += bet;
		}
		else{
			cout << "You lose $" << bet << endl;
			money -= bet;
		}

		// Check if user still has money, ask to play again
		if(money > 0){
			choice = playAgain(); //Function call

			// Error checking on user's choice
			while(choice != 'N' && choice != 'Y'){
				cout << "ERROR: Invalid choice." << endl;
				choice = playAgain(); //Function call
			}
		}
		else
			cout << "You are out of money. You can't play anymore" << endl << endl;

	}while( (money > 0) && (choice != 'N') );

	cout << "You ended with $" << money << endl;

	return 0;
}

// Function definitions

int placeBet() {
    int bet;

    cout << "How much would you like to bet? ";
    cin >> bet;

    return bet;
}

int getRoll() {
    int roll;

    roll = rand() % 6+1;

    return roll;
}

char playAgain() {
    char userChoice;

    cout << "Would you like to continue? (Y or N): ";
    cin >> userChoice;

    return userChoice;
}
