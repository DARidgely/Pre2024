//File Name: Movie.cpp
//
//Author: David Ridgely
//Collaborators: Melanie Garza
//Date: 10/22/2021
//Assignment Number: 4
//CS 2308 Fall 2021
//
//This is the Movie.cpp file. It defines all the functions inside of the Movie class.
//It uses the Movie.h header file to do this.

//need to include the necessary things used throughout the .cpp file.
#include "Movie.h"
#include <iostream>
#include <iomanip>

//***********************************************************
// Movie: This is the default constructor with no arguments.
// it sets the variables: id, rating, name, and releaseDate.
//***********************************************************
Movie::Movie() {
    //default constructor with no parameters will set things to empty strings or 0.
    id = 0;
    rating = 0.0;
    name = "";
    releaseDate = "";
}

//***********************************************************
// Movie: This is the default constructor that uses four
// parameters as arguements.
//
// movId: integer that is used for the movie's id number.
// movName: string that is used for the movie's name.
// rDate: string that is used for the releaseDate.
// rate: double that is used for the movie's rating.
//***********************************************************
Movie::Movie(int movId, string movName, string rDate, double rate){
    //this is the default constructor with argument parameters.
    //sets everything that is given.
    id = movId;
    name = movName;
    releaseDate = rDate;
    rating = rate;
}

//***********************************************************
// display: This function displays all the data in the Movie class
//***********************************************************
void Movie::display() {
    //displays stuff in the desired format.
    //fixed << setprecision is used for the rating to output in the 0.0 format
    cout << fixed << setprecision(1);
    cout << left
         << setw(3) << id
         << setw(26) << name
         << setw(12) << releaseDate
         << rating
         << endl;
}

//***********************************************************
// getId: This gets the id of a movie in the Movie class and
// returns it as an int.
//
// returns the movie id as an integer
//***********************************************************
int Movie::getId() {
    return id;
}

//***********************************************************
// getName: This gets the name of a movie in the Movie class and
// returns it as an string.
//
// returns the movie name as a string
//***********************************************************
string Movie::getName() {
    return name;
}

//***********************************************************
// getReleaseDate: This gets the release date of a movie in the
// Movie class and returns it as a string in YYYY/MM/DD format.
//
// returns the movie release date as a string in YYYY/MM/DD format.
//***********************************************************
string Movie::getReleaseDate() {
    return releaseDate;
}

//***********************************************************
// getRating: This gets the rating of a movie in the Movie class 
// and returns it as an double.
//
// returns the movie rating as a double.
//***********************************************************
double Movie::getRating() {
    return rating;
}
