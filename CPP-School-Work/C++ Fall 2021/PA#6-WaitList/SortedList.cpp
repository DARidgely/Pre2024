// File Name: SortedList.cpp
//
// Author: David Ridgely
// Collaborators: Melanie Garza
// Date: 11/13/2021
// Assignment Number: 6
// CS 2308 Fall 2021
//
// This file is the definition of the functions for the
// SortedList class. It allows the use of the functions inside
// of the class.

#define nullptr 0
#include "SortedList.h"
#include <iostream>
#include <cassert>
using namespace std;

//***********************************************************
// SortedList: initializes the queue list. Takes an int parameter
// which will set the max list size, and sets front to null.
// Will also start the list out at 0 items using the count variable.
//
// n: an integer that will set the max size of the list
//***********************************************************
SortedList::SortedList(int size) {
  head = nullptr;
  maxSize = size;
  count = 0;
}

//***********************************************************
// ~SortedList: deconstructor will empty the list and deallocate
// the dynamic memory.
//***********************************************************
SortedList::~SortedList() {
  ListNode *p;
  while (!isEmpty()) {
    // deletes the first node
    p = head;
    head = head->next;
    delete p;
  }
}

//***********************************************************
// remove: this function will take an item out of the classlist
// as if it were dropping the student from the class.
//
// val: string parameter of the student's name to drop.
//***********************************************************
void SortedList::remove(string val) {
    ListNode *p = head;      // to traverse the list
    ListNode *n = nullptr;   // trailing node pointer
    
    // skip nodes not equal to val, stop at last
    while (p && p->value!=val) {
        n = p;        // save it!
        p = p->next;  // advance it
    }
    
    // p not null: val is found, set links + delete
    if (p) {
      if (n==nullptr) {   // p points to the first elem.
        head = p->next;
        delete p;

      } else {            // n points to the predecessor
        n->next = p->next;
        delete p;

      }

    }
    count--;
}

//***********************************************************
// insert: This function takes in a new item and adds it in the
// list while also sorting it in ascending alphanumeric order.
//
// val: this is the name that will be added to the class list.
//***********************************************************
void SortedList::insert(string val) {
  // insert val into the list, keeping it always sorted in increasing order
  ListNode *currNode = new ListNode;
  ListNode *newNode = new ListNode;
  newNode->value = val;
  newNode->next = nullptr;

  if(head == nullptr || head->value >= newNode->value) {
    newNode->next = head;
    head = newNode;
  }else {
    currNode = head;
    while(currNode->next != nullptr &&
          currNode->next->value < newNode->value) {
      currNode = currNode->next;
    }
    newNode->next = currNode->next;
    currNode->next = newNode;

  }
  count++;
}

//***********************************************************
// isEmpty: this function will check if the waitlist is empty
// if it is then it will be true, otherwise false.
//
// returns true if empty, false otherwise
//***********************************************************
bool SortedList::isEmpty() {
  return (head==nullptr);
}

//***********************************************************
// isFull: this function will check if the waitlist is full
// if it is then it will be true, otherwise false.
//
// returns true if full, false otherwise
//***********************************************************
bool SortedList::isFull() {
  return (count == maxSize);
}

//***********************************************************
// display: this function will display the contents of the list
// in a numbered order of first to last.
//
// out: this is the output stream that is used to display to
// the console.
//***********************************************************
void SortedList::displayList(ostream& out) {
  ListNode *p = head;
  int nums = 1;
  while (p!=nullptr) {
    out << nums << " " << p->value  << endl;
    p = p->next;
    nums++;
  }
}