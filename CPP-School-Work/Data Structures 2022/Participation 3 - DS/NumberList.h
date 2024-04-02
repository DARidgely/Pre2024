//*************************************************
// File Name: NumberList.h
// Author: David Ridgely
// Assignment: Participation 3
// CS 3358 Summer 2022
// 
// Date: 7/7/2022
//*************************************************

#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#define NULL 0

class NumberList {
  private:
    struct ListNode {
      int value;
      ListNode *next;  // Pointer to the next node.

      ListNode() {
        value = 0;
        next = NULL;
      }

      ListNode(double value1, ListNode *next1 = NULL) {
        value = value1;
        next = next1;
      }
    };

    ListNode *head; // Pointer to the head node.

  public:
    NumberList();
    ~NumberList();
    bool isEmpty();
    void addNode(double);
    void displayNode();
    void searchNode(double);
    void deleteNode(double);
    void insertBefore(double, double);

};

#endif