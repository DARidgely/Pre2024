#include "NumberList.h"
#include <iostream>
using namespace std;

NumberList::NumberList() {
  head = NULL;
}

NumberList::~NumberList() {
  Node *p;
  while(!isEmpty()) {
    p = head;
    head = head->next;
    delete p;
  }
}

void NumberList::addNode(int num) {
  Node *newNode = new Node;
  newNode->data = num;
  newNode->next = NULL;

  if(isEmpty()) {
    head = newNode;
  }else {
    Node *p = head;
    while(p->next != NULL) {
    p = p->next;
    }
    p->next = newNode;
  }

}

void NumberList::displayNode() {
  Node* p = head;
  PrintLinkedList(p);
}

void NumberList::PrintLinkedList(Node *p) {
  if(p == NULL) {
    cout << endl;
    return;
  }else {
    cout << p->data << " ";
    PrintLinkedList(p->next);
  }
}

