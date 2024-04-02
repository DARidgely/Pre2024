//***********************************
// File Name: Stack.cpp
//
// Author: David Ridgely
// Assignment: Participation 4
// CS 3358 Summer 2022
//
// Date: 7/8/2022
//**********************************

#include "Stack.h"
#include <iostream>
#include <cassert>
using namespace std;


DynamicStack::DynamicStack() {
  head = NULL;
}

DynamicStack::~DynamicStack() {
  while(!isEmpty()) {
    pop();
  }
}

void DynamicStack::push(int num) {
  Node *temp = new Node;
  temp->data = num;
  
  temp->next = head;
  head = temp;
}

int DynamicStack::pop() {
  assert(!isEmpty());

  int result = head->data;

  Node *temp = head;
  head = head->next;
  delete temp;

  return result;
}

void DynamicStack::display() {
  Node *p;
  p = head;

  while(p != NULL) {
    cout << p->data << " ";
    p = p->next;
  }
}

bool DynamicStack::isEmpty() const {
  return (head == NULL);
}
