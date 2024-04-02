//****************************************
// File Name: NumberList.cpp
// Author: David Ridgely
// Assignment: Participation 3
// CS 3358 Summer 2022
//
// Date: 7/7/2022
//****************************************

#include "NumberList.h"
#include <iostream>
using namespace std;

NumberList::NumberList() {
  head = NULL;
}

NumberList::~NumberList() {
  ListNode *p;

  while(!isEmpty()) {
    p = head;
    head = head->next;
    delete p;
  }
}

bool NumberList::isEmpty() {
  return (head == NULL);
}

void NumberList::addNode(double newValue) {
  ListNode *newNode = new ListNode;
  newNode->value = newValue;
  newNode->next = NULL;

  if(isEmpty()) {
    head = newNode;
  }else {
    ListNode *p = head;
    while(p->next != NULL) {
      p = p->next;
    }
    p->next = newNode;
  }

}

void NumberList::displayNode() {
  ListNode *p;
  p = head;

  while(p != NULL) {
    cout << p->value << " ";
    p = p->next;
  }
}

void NumberList::insertBefore(double newNum, double target) {
  ListNode *newNode = new ListNode(newNum);
  ListNode *p;
  ListNode *n;
  p = head;
  n = NULL;

  while(p != NULL && p->value != target) {
    n = p;
    p = p->next;
  }

  if(n == NULL) {
    head = newNode;
    newNode->next = p;
  }else {
    newNode->next = p;
    n->next = newNode;
  }
}

void NumberList::deleteNode(double target) {
  ListNode *p = head;
  ListNode *n = NULL;

  while(p != NULL && p->value != target) {
    n = p;
    p = p->next;
  }

  if(p != NULL) {
    if(n == NULL) {
      head = p->next;
      delete p;
    }else {
      cout << "Node to be deleted not found" << endl;
    }
  }
}

void NumberList::searchNode(double target) {
  ListNode *p = new ListNode;
  p = head;
  
  while(p != NULL && p->value != target) {
    p = p->next;
  }

  if(p) {
    cout << "The value " << target << " is in the list." << endl;
  }else{
    cout << "Error: " << target << " is not in the list." << endl;
  }

}
