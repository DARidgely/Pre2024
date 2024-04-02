// File Name: StringQueue.h
//
// Author: David Ridgely
// Collaborators: Melanie Garza
// Date: 11/13/2021
// Assignment Number: 6
// CS 2308 Fall 2021
//
// This is the intialization of the StringQueue
// class, or the header file of the StringQueue class.
// this defines the class, and initializes any data members
// and/or functions that will be used.

#include <string>
using namespace std;


class StringQueue{
  private:
    struct QueueNode {
      string data;
      QueueNode* next;
    };
    QueueNode* front;
    QueueNode* rear;
    int maxSize;
    int count;
    
  public:
    // Constructor
    StringQueue(int);
    ~StringQueue();  // you can remove this if you're using a static array
    
    // Queue operations
    int enqueue(string);  //returns position where inserted, front is 1
    string dequeue();
    bool isEmpty();
    bool isFull();
    void display(ostream& out);
};
