//**********************************
// File Name: Stack.h
// Author: David Ridgely
// Assignment: Participation 4
// CS 3358 Summer 2022
//
// Date: 7/8/2022
//**********************************

#ifndef STACK_H
#define STACK_H

class DynamicStack {
  private:
    struct Node {
      int data;
      Node *next;
    };
    Node* head;

  public:
    DynamicStack();
    ~DynamicStack();
    void push(int);
    int pop();
    void display();
    bool isEmpty() const;

};


#endif
