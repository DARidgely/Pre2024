#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
class Stack{
  private:
    T* data;
    int top;
    int capacity;

  public:
    Stack(int size) {
      capacity = size;
      top = -1;
      data = new T[size];
    }

    ~Stack() {
      while(!isEmpty()) {
        pop();
      }
    }

    void push(T x) {
      if(!isFull()) {
        top++;
        data[top] = x;
      }
    }

    T pop() {
      T result;
      if(!isEmpty()) {
        result = data[top];
        top--;
      }
      return result;
    }

    void displayTop() {
      if(!isEmpty()) {
        cout << endl;
        cout << data[top] << endl;
      }
    }

    void display() {
      if(!isEmpty()) {
        for(int i = top; i >=0; i--) {
          cout << data[i] << " ";
        }
      }
      cout << endl;
    }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == capacity-1; }
};

#endif
