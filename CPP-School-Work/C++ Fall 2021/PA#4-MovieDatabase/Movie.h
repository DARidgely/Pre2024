//File Name: Movie.h
//
//Author: David Ridgely
//Collaborators: Melanie Garza
//Date: 10/22/2021
//Assignment Number: 4
//CS 2308 Fall 2021
//
// This is the movie header file. It defines the Movie class for use in the
// main.cpp file and the Movie.cpp file.

//these things are semi-required when writing .h files.
//they tell the compiler when building the program to check
//if this .h file has been included already and won't intialize/override variables.
//basically checks if defined or not defined already.
#ifndef MOVIE_H
#define MOVIE_H

//since this is just a .h file I wasn't going to include anything, but
//i needed to include string to allow myself to use string datatypes and
//have functions that return strings.
#include <string>
using namespace std;

class Movie{
    //dont want these things accessible outside of the class or getter/setter functions
    //in this case only getter functions can grab/access the values/variables.
    private:
        int id;
        string name;
        string releaseDate;
        double rating;

    //this can be used wherever and whenever as long as you are using a variable
    //that is of 'datatype' Movie so Movie test; test.display();
    public:
        //these are all basically just prototypes, we could do
        //inline functions for any of these but I decided to just
        //have all the functions definitions in the .cpp file.
        Movie();
        //dont need to name the parameters in a prototype just need to declare the datatype.
        Movie(int, string, string, double);
        void display();
        int getId();
        string getName();
        string getReleaseDate();
        double getRating();
};

#endif