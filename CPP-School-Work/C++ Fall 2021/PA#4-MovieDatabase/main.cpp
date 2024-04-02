//File Name: main.cpp
//
//David Ridgely
//Collaborators: Melanie Garza
//Date: 10/22/2021
//Assignment Number: 4
//CS 2308 Fall 2021
//
// A program that will allow the user to interact with a subset of the IMDB movie database.
// Reads in data from a .txt file and utilizes the Movie class to display and store data.
// Uses linear and binary searches and uses Insertion and Selection Sort to sort and search the data.


// These libraries are requires to do the various things throughout the program.
// You probably already know what they do, but iostream is for input/output stuff,
// fstream is for stile input/output, and iomanip is used for formatting purposes.
// Whenever you have a class and you are using multiple files, you want to include
// the file name of the header file for the class(es) that you are using, so "Movie.h".
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Movie.h"

using namespace std;

//***********************************************************
// displayMenu: This is used to display the menu options for
// the user to select from.
//***********************************************************
void displayMenu(){
    //\n just outputs a newline, is equivalent to endl.
    cout << "\nMenu\n"
         << "1. Display movies sorted by id\n"
         << "2. Display movies sorted by release date, then rating\n"
         << "3. Lookup a release date given a name\n"
         << "4. Lookup a movie by id\n"
         << "5. Quit the Program\n"
         << "Enter your choice:\n";
}

//***********************************************************
// displayHeader: This is used to display the header of the
// table of the data.
//***********************************************************
void displayHeader(){
    cout << left
         << setw(3) << "ID"
         << setw(26) << "Name"
         << setw(12) << "Date"
         << "Rating"
         << endl;
}

//***********************************************************
// displayMovies: This is used to display all the movies stored
// in the movies array of type Movie. Calls the display function
// in the Movie class.
//
// movies: array of type Movie that is used to reference the
// movie array in main.
// SIZE: integer that is the size of the array.
//***********************************************************
void displayMovies(Movie movies[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
      //since the movies array is of the Data Type "Movie" we can
      //access the public functions and whatnot inside the Movie class.
      movies[i].display();
    }
}

//***********************************************************
// readMovies: This reads in all the data from a .txt file
// and stores it in the movies array reference. It also counts
// the amount of times the loop iterates and sets the size that
// will be used for future loops.
//
// in: the reference for the input file stream.
// movies: array of data type Movie used to store file data.
// size: integer used to store the size of the array.
//***********************************************************
void readMovies(ifstream& in, Movie movies[], int& size) {
    //All of the parameters in this function are passby refernces so
    //that whatever happens to them in this function will happen to them
    // in the main function. Arrays are by default passby referenced, so if
    // you dont want your array to have changes you usually make a new array in
    // the function if you are doing changes our output stuff.
    int id;
    string name;
    string date;
    double rating;
    //if you are ever incrementing a variable inside a loop you need
    //to initialize it to 0 first.
    int count = 0;
    //this just loops while there is file input for the movie id.
    //as long as id is having a new input the while loop will iterate.
    while (in >> id) {
        in >> ws;  //skips whitespace (newline) in file after the id
        getline(in, name);
        in >> date;
        in >> rating;
        //you can set array elements to any kind of object or variable.
        //and so for every element in this array you are setting it to the data stored in
        //the Movie class at that specific point in time. You could also use vectors but
        //I used arrays this time because she wanted us to anyways and I wanted to see if
        //I could figure out how to do it. I prefer vectors tho cuz they are easier to use lol
        movies[count] = Movie(id, name, date, rating);
        count++;
    }
    size = count;
}

//***********************************************************
// sortByDateRating: This function sorts the movie data by the
// date the movie was released and if same date sorts by the
// movies' ratings.
//
// movies: array of Movie data used to sort.
// SIZE: size of array.
//***********************************************************
void sortByDateRating(Movie movies[], int SIZE) {
  int i;
  int j;
  int indexSmallest;
  //you want your temp variable set to type Movie so that when you are switching
  //things around it'll store properly because classes are a bit like structs and
  //you can make variables of that new datatype that stores all the variables within.
  //(id, movieName, releaseDate, rating)
  Movie temp;

  //this is where the function does all the checking for the sort.
  //this is the selection sort. it'll start at the first index.
  for (i = 0; i < (SIZE - 1); i++) {
    //you'll set the smallest index at i so you have something to check.
    indexSmallest = i;
    //this will start 1 ahead of i so you can start comparing stuff.
    for(j = i+1; j < SIZE; j++) {
      //this will compare the two release dates by which comes first and will set the index
      //to the earliest release date because we want to movie that came out first to be at the front
      //of the list.
      if(movies[j].getReleaseDate() < movies[indexSmallest].getReleaseDate()){
        indexSmallest = j;
      //this is to check if the release dates are the same, because if they are the same we will
      //need a different way to sort the movies.
      }else if (movies[j].getReleaseDate() == movies[indexSmallest].getReleaseDate()) {
        //this will check the two movies' ratings and put the better rating first.
        //the one with a lower rating will be second. The "indexSmallest" is a bit misleading at first
        //but since we are having the ratings sort from best to worst(highest to lowest) we want to see
        //check to see if the movie at j has a higher rating than the movie at indexSmallest. It would
        //probably be better to just have it named index rather than indexSmallest but whatever. Just
        //future reference stuff.
        if(movies[j].getRating() > movies[indexSmallest].getRating()) {
          indexSmallest = j;
        }
      }
    }
    //this switches the stuff all around, ya know the good stuff.
    temp = movies[i];
    movies[i] = movies[indexSmallest];
    movies[indexSmallest] = temp;
  }
}

//***********************************************************
// sortById: This takes the movie data and sorts it all by the
// movies' id number.
//
// movies: array of Movie data.
// SIZE: size of the array
//***********************************************************
void sortById(Movie movies[], int SIZE) {
  int i;
  int j;
  //same thing as before make sure your temp variable is the correct data type
  //or the same datatype as the thing you are storing and switching around.
  Movie temp;

  //this is the insertion sort. it'll start at the second element rather than the first,
  //and kinda work it's way up but also comparing backwards, so like: {3,1,2,4} compares 1 to 3, etc.
  for(i = 1; i < SIZE; i++) {
    j = i;

    //while we have j greater than 0 and our check of the id being
    //less than the one before (refer above) it'll sort everything.
    //so it goes through "oh 3 is before 1, lets switch that, oh 3 is before 2, switch, etc."
    while (j > 0 && movies[j].getId() < movies[j-1].getId()) {
      temp = movies[j];
      movies[j] = movies[j-1];
      movies[j-1] = temp;
      --j;
    }
  }
}

//***********************************************************
// linearSearchByName: This searches for a movie by a given
// name from the user and returns the index of that movie.
//
// movies: the array used to search through data.
// SIZE: size of the array
// targetName: the name of the movie that is being searched for.
// returns the movie's name index as an int.
//***********************************************************
int linearSearchByName(Movie movies[], int SIZE, string targetName) {
  int i;
  //this will take the targetName given from the user and search through
  //the entire array in whatever order until it finds the movie or target
  //it is looking for. it'll find that the movie at i is the same as the target
  //and return that index.
  for(i = 0; i < SIZE; i++) {
    if (movies[i].getName() == targetName) {
      return i;
    }
  }
  //no movie found
  return -1;
}

//***********************************************************
// binarySearchById: This gets the id of a movie in the Movie class and
// returns it as an int.
//
// movies: the array of movies that is being searched.
// SIZE: the size of the array.
// targetId: the movie ID that is being searched for.
//
// returns the movie's id index as an int.
//***********************************************************
int binarySearchById (Movie movies[], int SIZE, int targetId) {
  int low;
  int mid;
  int high;

  low = 0;
  high = SIZE-1;
  //this will search through and check if the target is greater than
  //or less than the mid point of the entire list. lets say a list of
  //10 things. it'll start at 5 and we want 9 it'll go to the mid point of
  //now 5-10 and search again until it finds the target it is looking for.
  while (high >= low) {
    mid = (high + low)/2;
    if(movies[mid].getId() < targetId) {
      low = mid + 1;
    }else if(movies[mid].getId() > targetId) {
      high = mid-1;
    }else {
      return mid;
    }
  }

  return -1;
}

int main() {
    int menuInput;
    int searchedName = -1;
    string movieName;
    int movieId;
    int searchedId;
    //here we are assuming the size of the movie text file wont be
    //greater than 100 items.
    int size = 100;
    Movie movie[100];

    //file input
    ifstream fin;
    fin.open("movies.txt");
    //calls readMovies to get the file input and set all the data
    //into the movie array.
    readMovies(fin, movie, size);

    //i used a do/while loop here because we want this program to run
    //through at LEAST once. it'll ask the user what they want to do at
    //least once no matter what. We display that menu first thing and have
    //the input to determine what happens next. if the input is 5, since i set
    //the while condition to (menuInput != 5), it will exit the loop without doing
    //anything else within the loop.
    do{
      displayMenu();
      cin >> menuInput;

      //this makes sure that the user only inputs within the menu options.
      //will show an alternate text until the user inputs a correct menu option.
      if(menuInput < 1 || menuInput > 5) {
        while(menuInput < 1 || menuInput > 5) {
          cout << "Please enter 1, 2, 3, 4, or 5:" << endl;
          cin >> menuInput;
        }
      }

      //I could have used a switch statement here but I decided to just go
      //with if/else if statements. I think I decided to do this even though
      //there's only 4 cases because there's only really gonna be 1 input for a case.
      //for example, can only input 1 for option 1. I probably would've used a switch
      //if the user was asked to input option a/A because that's two ways to get the case,
      //but either is fine.
      if(menuInput == 1) {
        //I called sortById because I want to make sure the list of movies
        //is sorted correctly before displaying it.
        sortById(movie, size);
        displayHeader();
        displayMovies(movie, size);
      }else if(menuInput == 2) {
        //I called the sortByDateRating just so we can get it sorted accordingly.
        sortByDateRating(movie, size);
        displayHeader();
        displayMovies(movie, size);
      }else if(menuInput == 3) {
        //in this we want to use getline because the user can input a movie name
        //that has multiple words or spaces in it and we want to get the entire movie name.
        cout << "Please enter a movie name:" << endl;
        cin >> ws;//this ensures there's no white space before hand that will cause the getline to grab nothing.
        getline(cin, movieName);
        //we have this because we want to store the index here in main that is returned from the search.
        searchedName = linearSearchByName(movie, size, movieName);
        //i checked the index this way because whenever I tried checking as if(searchedName == -1)
        //the program had a bug that threw an infinite loop of output so I decided to just set this to >= 0
        //because as long as it's within the elements it'll show the movie and otherwise assuming it returns
        //-1 or lower it'll show No movie was found.
        if(searchedName >= 0) {
          cout << "Release date of '" << movieName << "' is ";
          cout << movie[searchedName].getReleaseDate() << endl;
        }else {
          cout << "No movie found with name: " << movieName << endl;
        }
        //i do this just in case to clear any ws that wasn't captured from getline.
        cin >> ws;
      }else if(menuInput == 4) {
        //here we want the movie id so it's fine that we just do cin because
        //you wont have a movie id with a space in it.
        cout << "Please enter a movie id:" << endl;
        cin >> movieId;
        //we call sortById because we want the list of movies sorted out
        //by id so that the binary search can work correctly. Binary search assumes
        //that the list is sorted that way it can go through the high mid and lows of the list.
        sortById(movie, size);
        //same as before, we want to store the returned index.
        searchedId = binarySearchById(movie, size, movieId);
        //also same as before, when i checked for (searchedId != -1) there was the same bug
        //and I'm not sure exactly why it did it so I just went ahead and checked to make sure
        //that the index we got was somewhere in the arrays elements or list of movies.
        if (searchedId >= 0) {
          displayHeader();
          movie[searchedId].display();
        }else {
          cout << "No movie found with id: " << movieId << endl;
        }
      }

    }while (menuInput != 5);

    cout << "Exiting the program..." << endl;

    return 0;
}
