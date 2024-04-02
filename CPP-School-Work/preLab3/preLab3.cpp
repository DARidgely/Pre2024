//David Ridgely dar304@txstate.edu
//February 20, 2021
//No Collaborators
//Pre-Lab 3

#include <iostream>
#include <ctime>   // for seeding rand
#include <cstdlib> // C standard library

using namespace std;

int main()
{

        int random_number;

        // seeds rand (needed for getting random numbers)
        srand(time(NULL));

        // randomly generates a number 1 - 10 inclusively
        random_number = rand() % 10 + 1;

        cout << "You roll a " << random_number << ": ";


        // an IF statement that prints "CRITICAL HIT!!"
        // if the user rolls a 10
        if (random_number == 10){
            cout << "CRITICAL HIT!!" << endl;
        }
        // an ELSE IF statement that prints "Attack Strikes"
        // if the user rolls an 8 or 9.
        else if ((random_number == 8) || (random_number == 9)){
            cout << "Attack Strikes" << endl;
        }
        // an ELSE statement that prints "Attack Misses"
        // for any other roll
        else{
            cout << "Attack Misses" << endl;
        }


    return 0;
}
