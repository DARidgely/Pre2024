// David Ridgely    dar304@txstate.edu
// No Collaborators
// Pre_Lab 2

#include <iostream>

#include <fstream>

using namespace std;

int main() {

    string firstName;
    string lastName;
    int year;

    ifstream fin;

    fin.open("prelab_input.txt");

    fin >> firstName;
    fin >> lastName;
    fin >> year;

    if (!fin) {

      cout << "ERROR - File failed to open. Make sure that "
      << "the input file and this file are in the "
      << "same directory." << endl;

      return -1;
    }

    ofstream fout;

    fout.open("delorean.txt");

    fout << firstName << " ";
    fout << lastName << " ";
    year += 40;
    fout << year;


    fin.close();
    fout.close();

    return 0;

}
