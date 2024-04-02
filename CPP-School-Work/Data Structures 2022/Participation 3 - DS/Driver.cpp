//*************************************************
// File Name: Driver.cpp
// Author: David Ridgely
// Assignment: Participation 3
// CS 3358 Summer 2022
// 
// Date: 7/7/2022
//*************************************************


#include "NumberList.h"
#include <iostream>
using namespace std;

int main() {
  NumberList list;

  list.addNode(2.2);
  list.addNode(34.5);
  list.addNode(4.3);
  list.addNode(2.54);

  cout << "Values of the list are displayed: " << endl;
  list.displayNode();

  list.~NumberList();

  return 0;
}