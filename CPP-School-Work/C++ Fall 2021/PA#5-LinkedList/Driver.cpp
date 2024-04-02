// File Name: Driver.cpp
// 
// Author: Jill Seaman
// Date: 10/25/2021
// Assignment Number: 5
// CS2308.003 and CS5301 Fall 2021
// Instructor: Jill Seaman
//
// A demo driver for StringList.
//

#include<iostream>
#include<iomanip>
using namespace std;

#include "StringList.h"

int main()
{
    //testing StringList
    StringList slist;
    
    string movie1 = "Star Wars";
    string movie2 = "Fargo";
    string movie3 = "Back to the Future";
    string movie4 = "Titanic";

    // Testing pushLast/display/count
    cout << "Testing pushLast/display/count: " << endl;
    cout << "count is: " << slist.count() << endl;

    slist.pushLast(movie1);
    slist.display(cout);
    cout << "count is: " << slist.count() << endl;
    
    slist.pushLast(movie2);
    slist.display(cout);
    cout << "count is: " << slist.count() << endl;

    //Testing popFront() and last
   cout << endl;
   cout << "Testing popFront and last: " << endl;
   cout << "last: " << slist.last() << endl;
   slist.popFront();
   cout << "popFront: " << endl;
   slist.display(cout);
   cout << "count is: " << slist.count() << endl;
   cout << "last: " << slist.last() << endl;
   cout << "popFront: " << endl;
   slist.popFront();
   slist.display(cout);
   cout << "count is: " << slist.count() << endl;
   cout << "last should not crash):" << slist.last() << endl;
   cout << "popFront (should not crash): " << endl;
   slist.popFront();
   slist.display(cout);
   cout << "count is: " << slist.count() << endl;

   // Testing concatenate
   cout << endl;
   cout << "Testing concatenate" << endl;
   StringList s2;
   s2.pushLast(movie1);
   s2.pushLast(movie2);
   s2.pushLast(movie3);
   string list = s2.concatenate('|');
   cout << list << endl;

   // Testing moveToLast
   cout << endl;
   cout << "Testing moveToLast" << endl;
   s2.moveToLast(movie1);
   s2.display(cout);
   cout << "last: " << s2.last() << endl;
   cout << "now with the last movie: " << endl;
   s2.moveToLast(movie1);
   s2.display(cout);
   cout << "last: " << s2.last()  << endl;
   cout << "now with the string not found in the list: " << endl;
   s2.moveToLast("not there");
   s2.display(cout);   //should not crash


   // Testing minumum
   cout << endl;
   cout << "Testing minumum: " << endl;
   StringList s3;
   s3.pushLast(movie2);
   s3.pushLast(movie1);
   s3.pushLast(movie3);
   s3.pushLast(movie4);

   s3.display(cout);

   cout << "minimum up to 0: " << s3.minimumUpTo(0) << endl;
   cout << "minimum up to 1: " << s3.minimumUpTo(1) << endl;
   cout << "minimum up to 2: " << s3.minimumUpTo(2) << endl;
   cout << "minimum up to 3: " << s3.minimumUpTo(3) << endl;

   //Testing sort
   cout << endl;
   cout << "Testing selectionSort: " << endl;
   s3.selectionSort();
   s3.display(cout);

   cout << endl;
   cout << "Testing selectionSort after pushLast: " << endl;
   s3.pushLast("Jurassic Park");
   s3.display(cout);
   cout << "now sorted: " << endl;
   s3.selectionSort();
   s3.display(cout);
   cout << "last: " << s3.last() << endl;

}


/*  expected output:
 
 Testing pushLast/display/count:
 count is: 0
 Star Wars
 count is: 1
 Star Wars
 Fargo
 count is: 2

 Testing popFront and last:
 last: Fargo
 popFront:
 Fargo
 count is: 1
 last: Fargo
 popFront:
 count is: 0
 last should not crash):
 popFront (should not crash):
 count is: 0

 Testing concatenate
 Star Wars|Fargo|Back to the Future

 Testing moveToLast
 Fargo
 Back to the Future
 Star Wars
 last: Star Wars
 now with the last movie:
 Fargo
 Back to the Future
 Star Wars
 last: Star Wars
 now with the string not found in the list:
 Fargo
 Back to the Future
 Star Wars

 Testing minumum:
 Fargo
 Star Wars
 Back to the Future
 Titanic
 minimum up to 0: Fargo
 minimum up to 1: Fargo
 minimum up to 2: Back to the Future
 minimum up to 3: Back to the Future

 Testing selectionSort:
 Back to the Future
 Fargo
 Star Wars
 Titanic

 Testing selectionSort after pushLast:
 Back to the Future
 Fargo
 Star Wars
 Titanic
 Jurassic Park
 now sorted:
 Back to the Future
 Fargo
 Jurassic Park
 Star Wars
 Titanic
 last: Titanic

 */
