#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#define NULL 0

class NumberList {
  private:
    struct Node {
      int data;
      Node *next;
    };
    Node *head;

  public:
    NumberList();
    ~NumberList();
    void addNode(int);
    void displayNode();
    void PrintLinkedList(Node* p);
    bool isEmpty() { return head == NULL; }
};

#endif