// File Name: StringQueue.cpp
//
// Author: David Ridgely
// Collaborators: Melanie Garza
// Date: 11/13/2021
// Assignment Number: 6
// CS 2308 Fall 2021
//
// This file is the StringQueue definition, it will allow
// the program in main to add names to a waitlist and remove
// names from a waitlist. It will display the waitlist and
// will be able to tell if the waitlist is full or empty.

#include "StringQueue.h"
#include <iostream>
#include <cassert>
#define nullptr 0
using namespace std;

//***********************************************************
// StringQueue: initializes the queue list. Takes an int parameter
// which will set the max list size, and sets front and rear to null.
// Will also start the list out at 0 items using the count variable.
//
// n: an integer that will set the max size of the list
//***********************************************************
StringQueue::StringQueue(int n) {
  maxSize = n;
  count = 0;
  front = nullptr;
  rear = nullptr;
}

//***********************************************************
// ~StringQueue: deconstructor will empty the list and deallocate
// the dynamic memory.
//***********************************************************
StringQueue::~StringQueue() {
  while(!isEmpty()) {
    dequeue();
  }
}

//***********************************************************
// enqueue: This function takes in a new item and adds it to
// the end of the wait list, then returns where that item is.
//
// newData: this is the name that will be added to the queue
// waitlist.
//
// returns an int to show where the item that has been added
// in the list.
//***********************************************************
int StringQueue::enqueue(string newData) {
  assert(!isFull());

  QueueNode *temp = new QueueNode;
  temp->data = newData;
  temp->next = nullptr;

  if(isEmpty()) {
    front = temp;
    rear = temp;
  }else {
    rear->next = temp;
    rear = temp;
  }

  count++;
  return count;
}

//***********************************************************
// dequeue: this function will take an item out of the waitlist
// and then return that item.
//
// returns the item that was removed from the list.
//***********************************************************
string StringQueue::dequeue() {
  assert(!isEmpty());

  string removed = front->data;
  QueueNode* temp = front;
  front = front->next;
  delete temp;
  count--;
  return removed;
}

//***********************************************************
// isEmpty: this function will check if the waitlist is empty
// if it is then it will be true, otherwise false.
//
// returns true if empty, false otherwise
//***********************************************************
bool StringQueue::isEmpty() {
  return (count == 0);
}

//***********************************************************
// isFull: this function will check if the waitlist is full
// if it is then it will be true, otherwise false.
//
// returns true if full, false otherwise
//***********************************************************
bool StringQueue::isFull() {
  if(count == maxSize) {
    return true;
  }else {
    return false;
  }
}

//***********************************************************
// display: this function will display the contents of the list
// in a numbered order of first to last.
//
// out: this is the output stream that is used to display to
// the console.
//***********************************************************
void StringQueue::display(ostream& out) {
  QueueNode* display = front;
  int num = 1;

  while(display!=nullptr) {
    out << num << " " << display->data << endl;
    display=display->next;
    num++;
  }
}