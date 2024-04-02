//**************************************************
// File Name: NumberList.h
//
// Author: David Ridgely
// Assignment: Participation 2 - Number List
// CS 3358 Summer 2022
// Date: 7/6/2022
//*************************************************
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#include <iostream>
using namespace std;

class NumberList {
  private:
    int list[100];
    int count;
    int size;

  public:
    NumberList();
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int, int);
    void remove(int);
    void display();
};

#endif  // NumberList_H