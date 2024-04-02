//*************************************
// File Name: DriverStack.cpp
// Author: David Ridgely
// Assignment: Participation 4
// CS 3358 Summer 2022
//
// Date: 7/8/2022
//*************************************

#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
  DynamicStack stack;
  int popped;
  stack.push(3);
  stack.push(5);
  stack.push(1);

  cout << endl;
  stack.display();

  popped = stack.pop();
  cout << endl;
  cout << popped << endl;

  stack.display();
}
