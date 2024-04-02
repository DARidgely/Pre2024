// File Name: main.cpp
//
// Author: David Ridgely
// Collaborators: Melanie Garza
// Date: 11/13/2021
// Assignment Number: 6
// CS 2308 Fall 2021
//
// This program simulates a class wait list as used during registration for courses.
// Will allow the user to add a student to a class roster and if that roster is
// full then it will prompt to add to waitlist. If the waitlist is full then a message
// will display notifying the user.

#include "StringQueue.h"
#include "SortedList.h"
#include <iostream>
using namespace std;

int main() {
  int classSize, waitSize;
  string menuInput;
  string name, waitName;
  char joinList;
  int position;

  cout << "Enter class size: ";
  cin >> classSize;
  SortedList classList(classSize);
  cout << "Enter wait list size: ";
  cin >> waitSize;
  StringQueue waitList(waitSize);
  cout << "Enter the commands:" << endl;

  do{
    cin >> menuInput;
     
    if(menuInput == "add") {
      if(!classList.isFull()) {
        cin >> name;
        classList.insert(name);
      
      }else{
        cin >> name;
        cout << ">Class is full, join the wait list (y/n)?";
        cout << endl;
        cin >> joinList;

        if(waitList.isFull()) {
          cout << ">Wait List is also full. Sorry." << endl;
        }else if(!waitList.isFull() && (joinList == 'y' || joinList == 'Y')) {
          position = waitList.enqueue(name);
          cout << ">Added at position " << position << endl;
        }
      }

    }else if(menuInput == "drop") {
      cin >> name;
      classList.remove(name);
      
      if(waitList.isEmpty()) {
        cout << ">No one added to the roster. Wait list is empty." << endl;
      }else if(!waitList.isEmpty()) {
        
        do{
          waitName = waitList.dequeue();
          cout << ">Add " << waitName << " to the class (y/n)?";
          cout << endl;
          cin >> joinList;
          if(joinList == 'y') {
            classList.insert(waitName);
          }
        }while(!waitList.isEmpty());
        
      }

    }else if(menuInput == "pr") {
      classList.displayList(cout);

    }else if(menuInput == "pwl") {
      waitList.display(cout);

    }

  }while(menuInput != "quit");

  return 0;
}