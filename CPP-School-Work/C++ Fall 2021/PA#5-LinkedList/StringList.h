// File Name: StringList.h
//
// Author: Jill Seaman
// Date: 10/25/2021
// Assignment Number: 5
// CS2308.003 and CS5301 Fall 2021
// Instructor: Jill Seaman
//
// Represents a list of strings.
// Supports adding and removing strings, displaying and sorting strings,
// concatenating the strings, and counting of the number of strings in the list.

#ifndef STRINGLIST_H
#define STRINGLIST_H

#include <string>
using namespace std;

class StringList
{
  private:
    struct StringNode          // the Nodes of the linked list
    {
        string data;           // data is a string
        StringNode *next;      // points to next node in list
    };
    
    StringNode *head;           // points to first node
    StringNode *tail;           // points to last node

  public:
    StringList();
    ~StringList();
    
    int count();
    void pushLast(string);
    void popFront();
    string last();
    void display(ostream& out);
    string concatenate(char);
    void moveToLast(string);
    string minimumUpTo(int);
    void selectionSort();
    
};

#endif